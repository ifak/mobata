#include "junctionitem.hpp"

#include "junctionarc.hpp"

#include "../graph/nodeitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

class JunctionItem::Private
{
  friend class JunctionItem;

public:
  Private():_sourcesItem(0), _targetsItem(0)
  {}
  ~Private()
  {}

private:
  QStandardItem*	_sourcesItem;
  QStandardItem*	_targetsItem;
};

JunctionItem::JunctionItem(const QUuid& uuid)
  :	NodeItem(uuid), _d(new Private())
{}

JunctionItem::~JunctionItem()
{}

JunctionArc *JunctionItem::addSource(NodeItem* sourceNode)
{
  if(!sourceNode)
    return 0;

  if(!this->_d->_sourcesItem)
  {
    this->_d->_sourcesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/manyjunctionarc.png")),
                                             QLatin1String("sources"));
    this->_d->_sourcesItem->setFlags(this->_d->_sourcesItem->flags() & ~Qt::ItemIsEditable);
    this->appendRow(this->_d->_sourcesItem);
  }

  JunctionArc* newSourceItem=new JunctionArc(sourceNode, this);
  this->_d->_sourcesItem->appendRow(newSourceItem);

  return newSourceItem;
}

JunctionArc const* JunctionItem::source(NodeItem const* sourceNode) const
{
  foreach(JunctionArc const* sourceArc, this->sources())
    if(sourceArc->source()==sourceNode)
      return sourceArc;

  return 0;
}

const JunctionArc *JunctionItem::sourceArc(const QUuid &arcUuid) const
{
  foreach(JunctionArc const* sourceArc, this->sources())
    if(sourceArc->uuid()==arcUuid)
      return sourceArc;

  return 0;
}

JunctionItem::JunctionSourceSet JunctionItem::sources()
{
  JunctionSourceSet sources;
  if(!this->_d->_sourcesItem)
    return sources;

  int end=this->_d->_sourcesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_sourcesItem->child(i);
    JunctionArc* source=utils::simple_cast<JunctionArc*>(currChild);
    Q_ASSERT(source);
    sources.append(source);
  }

  return sources;
}

JunctionItem::ConstJunctionSourceSet JunctionItem::sources() const
{
  ConstJunctionSourceSet sources;
  if(!this->_d->_sourcesItem)
    return sources;

  int end=this->_d->_sourcesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_sourcesItem->child(i);
    JunctionArc* source=utils::simple_cast<JunctionArc*>(currChild);
    Q_ASSERT(source);
    sources.append(source);
  }

  return sources;
}

void JunctionItem::removeSource(NodeItem const* sourceNode)
{
  foreach(JunctionArc const* sourceArc,
          this->sources())
  {
    if(sourceArc->source()==sourceNode)
      this->_d->_sourcesItem->removeRow(sourceArc->row());
  }

  return;
}

JunctionArc* JunctionItem::addTarget(NodeItem* targetNode)
{
  if(!targetNode)
    return 0;

  if(!this->_d->_targetsItem)
  {
    this->_d->_targetsItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/manyjunctionarc.png")),
                                             QLatin1String("targets"));
    this->_d->_targetsItem->setFlags(this->_d->_targetsItem->flags() & ~Qt::ItemIsEditable);
    this->appendRow(this->_d->_targetsItem);
  }

  JunctionArc* newTargetItem=new JunctionArc(this, targetNode);
  this->_d->_targetsItem->appendRow(newTargetItem);

  return newTargetItem;
}

JunctionArc const* JunctionItem::target(NodeItem const* targetNode) const
{
  foreach(JunctionArc const* targetArc, this->targets())
    if(targetArc->target()==targetNode)
      return targetArc;

  return 0;
}

const JunctionArc *JunctionItem::targetArc(const QUuid &arcUuid) const
{
  foreach(JunctionArc const* target, this->targets())
    if(target->uuid()==arcUuid)
      return target;

  return 0;
}

JunctionItem::JunctionTargetSet JunctionItem::targets()
{
  JunctionTargetSet targets;
  if(!this->_d->_targetsItem)
    return targets;

  int end=this->_d->_targetsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_targetsItem->child(i);
    JunctionArc* target=utils::simple_cast<JunctionArc*>(currChild);
    Q_ASSERT(target);
    targets.append(target);
  }

  return targets;
}

JunctionItem::ConstJunctionTargetSet JunctionItem::targets() const
{
  ConstJunctionTargetSet targets;
  if(!this->_d->_targetsItem)
    return targets;

  int end=this->_d->_targetsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_targetsItem->child(i);
    JunctionArc* target=utils::simple_cast<JunctionArc*>(currChild);
    Q_ASSERT(target);
    targets.append(target);
  }

  return targets;
}

void JunctionItem::removeTarget(NodeItem const* targetNode)
{
  foreach(JunctionArc const* constTargetArc,
          this->targets())
  {
    if(constTargetArc->target()==targetNode)
      this->_d->_targetsItem->removeRow(constTargetArc->row());
  }

  return;
}

void JunctionItem::updateText()
{
  this->setText(this->toString());

  foreach(JunctionArc* source, this->sources())
    source->setText(source->toString());

  foreach(JunctionArc* target, this->targets())
    target->setText(target->toString());

  return;
}

QString JunctionItem::toString() const
{
  QString decl=QLatin1String("junction");

  if(this->_d->_sourcesItem
     && this->_d->_sourcesItem->rowCount())
    decl+=QLatin1String(" from ");

  int pos=0;
  foreach(JunctionArc const* source, this->sources())
  {
    if(pos)
      decl+=QLatin1String(",");
    decl+=source->toString();
  }

  if(this->_d->_targetsItem
     && this->_d->_targetsItem->rowCount())
    decl+=QLatin1String(" to ");

  foreach(JunctionArc const* target, this->targets())
    decl+=target->toString();

  return decl;
}

}///end namespace model
}///end namespace spenat
