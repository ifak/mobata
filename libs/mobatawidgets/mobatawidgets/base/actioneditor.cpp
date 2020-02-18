#include "actioneditor.hpp"

#include "actionhighlighter.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class ActionEditor::Private
{
	friend  class ActionEditor;
	
	Private()
	{}
	
public:
	~Private()
	{}
	
private:
	ActionHighlighter* _actionHighlighter;
};

ActionEditor::ActionEditor(QWidget* parent)
	: CodeEditor(parent), _d(new Private())
{
	QFont font;
	font.setFamily(QLatin1String("Courier"));
	font.setFixedPitch(true);
	font.setPointSize(10);
	this->setFont(font);

	this->_d->_actionHighlighter = new ActionHighlighter(this->document());
}

ActionEditor::~ActionEditor()
{}

}///end namespace base
}///end namespace view
