#include "texteditdelegate.hpp"

#include <QTextDocument>
#include <QTextEdit>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class TextEditDelegate::Private
{
	friend class TextEditDelegate;
	
	Private()
	{}
	
public:
	~Private()
	{}
	
private:
	mutable QTextDocument _document;
};

TextEditDelegate::TextEditDelegate(QObject *parent)
	:	QStyledItemDelegate(parent), _d(new Private())
{}

TextEditDelegate::~TextEditDelegate()
{}

QWidget *TextEditDelegate::createEditor(QWidget *parent, 
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);
	
	return new QTextEdit(parent);
}

void TextEditDelegate::setEditorData(QWidget *editor, 
                                    const QModelIndex &index) const
{
	QString stringData=index.model()->data(index, Qt::DisplayRole).toString();
	QTextEdit* textEdit = qobject_cast<QTextEdit*>(editor);
	Q_ASSERT(textEdit);
  textEdit->setText(stringData);
	
	return;
}

void TextEditDelegate::setModelData(QWidget *editor, 
                                    QAbstractItemModel *Model,
                                    const QModelIndex &index) const
{
	QTextEdit* textEdit = qobject_cast<QTextEdit*>(editor);
	Q_ASSERT(textEdit);
	Model->setData(index, textEdit->toPlainText());
	
	return;
}

QSize TextEditDelegate::sizeHint(const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
	QString stringData=index.model()->data(index, Qt::DisplayRole).toString();
	this->_d->_document.setDefaultFont(option.font);
	this->_d->_document.setPlainText(stringData);
	
	return QSize(this->_d->_document.size().width()+20, 
							 this->_d->_document.size().height());
}

void TextEditDelegate::closeAndCommitEditor()
{
	QTextEdit* textEdit = qobject_cast<QTextEdit*>(this->sender());
	Q_ASSERT(textEdit);
	emit commitData(textEdit);
	emit closeEditor(textEdit);
	
	return;
}

}///end namespace base
}///end namespace view
