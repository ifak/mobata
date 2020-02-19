#include "texteditwidgetitem.hpp"

#include <QTextEdit>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

TextEditWidget::TextEditWidget(QTextEdit* textEdit, QGraphicsItem * parentItem)
	: QGraphicsProxyWidget(parentItem)
{
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
	this->setWindowFlags(Qt::Window);

	if(!textEdit)
		this->setWidget(new QTextEdit());
	else
		this->setWidget(textEdit);
}

TextEditWidget::~TextEditWidget()
{}

int TextEditWidget::type() const
{
	return Type;
}

}//end namespace base
}//end namespace view
