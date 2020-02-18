#include "actionhighlighter.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

struct ActionHighlightingRule
{
	QRegExp pattern;
	QTextCharFormat format;
};

class ActionHighlighter::Private
{
	friend class ActionHighlighter;
	
	Private()
	{}
	
public:
	~Private()
	{}
	
private:	
	QVector<ActionHighlightingRule> _highlightingRules;

	QRegExp _commentStartExpression;
	QRegExp _commentEndExpression;

	QTextCharFormat _keywordFormat;
	QTextCharFormat _singleLineCommentFormat;
	QTextCharFormat _multiLineCommentFormat;
	QTextCharFormat _identifierFormat;
	QTextCharFormat _signalFormat;
};

ActionHighlighter::ActionHighlighter(QTextDocument* parent)
	: QSyntaxHighlighter(parent), _d(new Private())
{
	ActionHighlightingRule rule;

	this->_d->_keywordFormat.setForeground(Qt::darkBlue);
	this->_d->_keywordFormat.setFontWeight(QFont::Bold);
	
	QStringList keywordPatterns;
	keywordPatterns << QLatin1String("send")
									<< QLatin1String("to")
									<< QLatin1String("trigger");
	foreach (const QString &pattern, keywordPatterns) 
	{
		rule.pattern = QRegExp(pattern);
		rule.format = this->_d->_keywordFormat;
		this->_d->_highlightingRules.append(rule);
	}

	this->_d->_singleLineCommentFormat.setForeground(Qt::red);
	rule.pattern = QRegExp(QLatin1String("//[^\n]*"));
	rule.format = this->_d->_singleLineCommentFormat;
	this->_d->_highlightingRules.append(rule);

	this->_d->_multiLineCommentFormat.setForeground(Qt::red);

	this->_d->_identifierFormat.setForeground(Qt::darkGreen);
	rule.pattern = QRegExp(QLatin1String("\".*\""));
	rule.format = this->_d->_identifierFormat;
	this->_d->_highlightingRules.append(rule);

	this->_d->_signalFormat.setFontItalic(true);
	this->_d->_signalFormat.setForeground(Qt::darkMagenta);
	rule.pattern = QRegExp(QLatin1String("\\b[A-Za-z0-9_]+(?=\\()"));
	rule.format = this->_d->_signalFormat;
	this->_d->_highlightingRules.append(rule);

	this->_d->_commentStartExpression = QRegExp(QLatin1String("/\\*"));
	this->_d->_commentEndExpression = QRegExp(QLatin1String("\\*/"));
}

ActionHighlighter::~ActionHighlighter()
{}

void ActionHighlighter::highlightBlock(const QString& text)
{
	foreach (const ActionHighlightingRule& rule, this->_d->_highlightingRules)
	{
		QRegExp expression(rule.pattern);
		int index = expression.indexIn(text);
		while (index >= 0) 
		{
			int length = expression.matchedLength();
			setFormat(index, length, rule.format);
			index = expression.indexIn(text, index + length);
		}
	}
	this->setCurrentBlockState(0);

	int startIndex = 0;
	if (previousBlockState() != 1)
		startIndex = this->_d->_commentStartExpression.indexIn(text);

	while (startIndex >= 0) 
	{
		int endIndex = this->_d->_commentEndExpression.indexIn(text, startIndex);
		int commentLength;
		if (endIndex == -1) 
		{
			setCurrentBlockState(1);
			commentLength = text.length() - startIndex;
		} 
		else 
		{
			commentLength = endIndex - startIndex	+ this->_d->_commentEndExpression.matchedLength();
		}

		this->setFormat(startIndex, commentLength, this->_d->_multiLineCommentFormat);
		startIndex = this->_d->_commentStartExpression.indexIn(text, startIndex + commentLength);
	}

	return;
}

}///end namespace base
}///end namespace view
