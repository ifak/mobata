#include "declscene.hpp"

#include "decljunction.hpp"
#include "decltransition.hpp"
#include "declplace.hpp"

#include "../graph/functors.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

class DeclScene::Private
{
  friend class DeclScene;
  
  Private()
  {}
};

DeclScene::DeclScene(QObject *parent) 
	: SpenatScene(parent), _d(new Private)
{
  this->setName(QStringLiteral("spenat"));
}

DeclScene::~DeclScene()
{
	delete this->_d;
}

DeclJunction* DeclScene::junction(QUuid junctionUuid)
{
  return graph::graphSceneItem<DeclJunction>(junctionUuid, this);
}

DeclJunction const* DeclScene::junction(QUuid junctionUuid) const
{
	return graph::graphSceneItem<DeclJunction const>(junctionUuid, this);
}

QList<DeclJunction const*> DeclScene::junctions() const
{
	return graph::graphSceneItems<DeclJunction const>(this);
}

QList<DeclJunction*> DeclScene::junctions()
{
	return graph::graphSceneItems<DeclJunction>(this);
}

DeclJunction *DeclScene::addJunction(QPointF pos,
                                     QUuid junctionUuid)
{
	DeclJunction* newJunction=new DeclJunction();
	newJunction->setUuid(junctionUuid);
	this->addItem(newJunction);
	newJunction->setPos(this->onGrid(pos));//TODO: onGrid(pos)
	
	emit junctionAdded(newJunction->uuid());
	emit graphModified(true);

	return newJunction;
}

void DeclScene::removeJunction(const QUuid &junctionUuid)
{
	DeclJunction* junction=graph::graphSceneItem<DeclJunction>(junctionUuid,
                                                             this);
	if(junction)
		return this->removeJunction(junction);
	
	return;
}

void DeclScene::removeJunction(DeclJunction* junction)
{
	if(!junction)
		return;
	
	QUuid junctionUuid=junction->uuid();
	this->removeNode(junction);
	emit junctionRemoved(junctionUuid);
	
	return;
}

const graph::AbstractNode *DeclScene::node(const QUuid &nodeUuid) const
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclJunction* currNode=qgraphicsitem_cast<DeclJunction*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
  }
  
  return 0;
}

graph::AbstractNode *DeclScene::node(const QUuid &nodeUuid)
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclJunction* currNode=qgraphicsitem_cast<DeclJunction*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
  }
  
  return 0;
}

DeclScene::ConstNodeSet DeclScene::nodes() const
{
  ConstNodeSet nodes;
  
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
      nodes.append(currNode);
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
      nodes.append(currNode);
    else if(DeclJunction* currNode=qgraphicsitem_cast<DeclJunction*>(currItem))
      nodes.append(currNode);
  }
  
  return nodes;
}

DeclScene::NodeSet DeclScene::nodes()
{
  NodeSet nodes;
  
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
      nodes.append(currNode);
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
      nodes.append(currNode);
    else if(DeclJunction* currNode=qgraphicsitem_cast<DeclJunction*>(currItem))
      nodes.append(currNode);
  }
  
  return nodes;
}

bool DeclScene::isValidArc(const graph::AbstractNode *sourceNode, 
													 const graph::AbstractNode *targetNode,
													 QString* errorMessage) const
{
	Q_ASSERT(errorMessage);
  
  if(!SpenatScene::isValidArc(sourceNode, targetNode, errorMessage))
    return false;
	
	using namespace spenat;
	
	if(DeclTransition const* sourceTrans=qgraphicsitem_cast<DeclTransition const*>(sourceNode))
	{
		if(DeclJunction const* targetJunct=qgraphicsitem_cast<DeclJunction const*>(targetNode))
		{///error-arc
			Q_UNUSED(targetJunct);
			*errorMessage=tr("arc between transition and "
                       "junction is not allowed!"
                       "source-transition:'%1'")
                    .arg(sourceTrans->notation());
			return false;
		}
	}
	///source junction
	else if(DeclJunction const* sourceJunction=qgraphicsitem_cast<DeclJunction const*>(sourceNode))
	{
		Q_UNUSED(sourceJunction);
		
		if(DeclTransition const* targetTrans=qgraphicsitem_cast<DeclTransition const*>(targetNode))
		{///error-arc
			*errorMessage=tr("arc between junction and "
                       "transtion is not allowed!"
                       " target-transition:'%1'")
                    .arg(targetTrans->notation());
			return false;
		}
		else if(DeclJunction const* targetJunct=qgraphicsitem_cast<DeclJunction const*>(targetNode))
		{///error-arc TODO: in future...;)
			Q_UNUSED(targetJunct);
			*errorMessage=QLatin1String("arc between 2 junctions is currently not allowed!");
			return false;
		}
	}
	
  return true;
}

void DeclScene::removeGraphItem(QGraphicsItem* graphItem)
{
  if(DeclJunction* selectedJunction=dynamic_cast<DeclJunction*>(graphItem))
    this->removeJunction(selectedJunction);
  else
    return SpenatScene::removeGraphItem(graphItem);
}

}///end namespace spenat
}///end namespace view
