#include "declmodelview.hpp"

#include <mobata/model/spenat/spenatdeclmodel.hpp>

#include <QHeaderView>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

DeclModelView::DeclModelView(QWidget *parent) :
	QTreeView(parent)
{
	this->setWordWrap(true);
	this->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void DeclModelView::setDeclModel(model::spenat::SpenatDeclModel *declModel)
{
	if(!declModel)
		return;
	
	QTreeView::setModel(declModel);
	
	foreach(int column, QList<int>()<<1<<2<<3<<4<<5<<6<<7)
		this->hideColumn(column);
	
	return;
}

}///end namespace spenat
}///end namespace view
