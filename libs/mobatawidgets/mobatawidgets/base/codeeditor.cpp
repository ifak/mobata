#include "codeeditor.hpp"

#include <QPainter>
#include <QTextBlock>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class LineNumberArea : public QWidget
{
public:
  LineNumberArea(CodeEditor* codeEdit) : QWidget(codeEdit), codeEditor(codeEdit)
	{}

public:
	QSize sizeHint() const 
	{
		return QSize(codeEditor->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent *event) 
	{
		this->codeEditor->lineNumberAreaPaintEvent(event);
	}

private:
	CodeEditor* codeEditor;
};

class CodeEditor::Private
{
	friend class CodeEditor;

	Private()
	{}

public:
	~Private()
	{}
	
private:
  LineNumberArea* _lineNumberArea;
};

CodeEditor::CodeEditor(QWidget* parent)
	: QPlainTextEdit(parent), _d(new Private())
{
  this->_d->_lineNumberArea = new LineNumberArea(this);

	connect(this, SIGNAL(blockCountChanged(int)), 
					this, SLOT(updateLineNumberAreaWidth(int)));
	connect(this, SIGNAL(updateRequest(const QRect &, int)), 
					this, SLOT(updateLineNumberArea(const QRect &, int)));
	connect(this, SIGNAL(cursorPositionChanged()), 
					this, SLOT(highlightCurrentLine()));

	this->updateLineNumberAreaWidth(0);
	this->highlightCurrentLine();
}

CodeEditor::~CodeEditor()
{
}

int CodeEditor::lineNumberAreaWidth()
{
	int digits = 1;
	int max = qMax(1, blockCount());
	while (max >= 10) 
	{
		max /= 10;
		++digits;
	}

	int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
	this->setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);

	return;
}

void CodeEditor::updateLineNumberArea(const QRect& rect, int dy)
{
	if (dy)
		this->_d->_lineNumberArea->scroll(0, dy);
	else
		this->_d->_lineNumberArea->update(0, rect.y(), 
																			this->_d->_lineNumberArea->width(), rect.height());

	if (rect.contains(viewport()->rect()))
		this->updateLineNumberAreaWidth(0);

	return;
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
	QPlainTextEdit::resizeEvent(e);

	QRect cr = contentsRect();
	this->_d->_lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));

	return;
}

void CodeEditor::highlightCurrentLine()
{
	QList<QTextEdit::ExtraSelection> extraSelections;

	if (!isReadOnly()) 
	{
		QTextEdit::ExtraSelection selection;

		QColor lineColor = QColor(Qt::yellow).lighter(160);

		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		selection.cursor = textCursor();
		selection.cursor.clearSelection();
		extraSelections.append(selection);
	}

	this->setExtraSelections(extraSelections);

	return;
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
	QPainter painter(this->_d->_lineNumberArea);
	painter.fillRect(event->rect(), Qt::lightGray);


	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid() && top <= event->rect().bottom()) 
	{
		if (block.isVisible() && bottom >= event->rect().top()) 
		{
			QString number = QString::number(blockNumber + 1);
			painter.setPen(Qt::black);
			painter.drawText(0, top, 
											 this->_d->_lineNumberArea->width(), 
											 fontMetrics().height(),
				Qt::AlignRight, number);
		}

		block = block.next();
		top = bottom;
		bottom = top + (int) blockBoundingRect(block).height();
		++blockNumber;
	}

	return;
}

}///end namespace base
}///end namespace view
