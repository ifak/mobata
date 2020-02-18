#include "mscfragment.hpp"

#include "mscfragmentregion.hpp"

#include "../base/textitem.hpp"

#include <QBrush>
#include <QPen>
#include <QFont>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscFragment::Private
{
  friend class KMscFragment;

  Private(int fragmentType)
    : _fragmentType(fragmentType),
      _typeItem(0),
      _offset(25)
  {}

  int                           _fragmentType;
  QVector<KMscFragmentRegion*>  _mscFragmentRegions;
  QVector<QGraphicsLineItem*>   _seperatingLines;
  base::TextItem*               _typeItem;
  int                           _offset;
};

KMscFragment::KMscFragment(int fragmentType, KMscSequence* parentSequence)
  : QGraphicsRectItem(parentSequence),
    MscSequenceStep(this),
    _d(new Private(fragmentType))
{
  this->setBrush(QBrush(Qt::white));
  this->setPen(QPen(Qt::darkGreen, 3));
}

KMscFragment::~KMscFragment()
{
  delete this->_d;
}

int KMscFragment::fragmentType() const
{
  return this->_d->_fragmentType;
}

void KMscFragment::setFragmentType(int fragmentType)
{
  this->_d->_fragmentType=fragmentType;

  return;
}

KMscFragmentRegion* KMscFragment::addRegion(const QString& option)
{
  KMscFragmentRegion* newFragmentRegion=new KMscFragmentRegion(this, option);
  this->_d->_mscFragmentRegions.push_back(newFragmentRegion);

  if(this->_d->_seperatingLines.size()<this->_d->_mscFragmentRegions.size()-1)
  {
    QGraphicsLineItem* newSeperatingLine=new QGraphicsLineItem(this);
    newSeperatingLine->setPen(QPen(Qt::darkGreen, 2, Qt::DashLine));

    this->_d->_seperatingLines.push_back(newSeperatingLine);
  }

  return newFragmentRegion;
}

KMscFragment::ConstMscRegionSet KMscFragment::regions() const
{
  ConstMscRegionSet regionsList;
  foreach(KMscFragmentRegion* region, this->_d->_mscFragmentRegions)
    regionsList.append(region);

  return regionsList;
}

KMscFragment::MscRegionSet KMscFragment::regions()
{
  return this->_d->_mscFragmentRegions.toList();
}

qreal KMscFragment::updateGeometry(const qreal bottomSceneY,
                                   const qreal marginSpace)
{
  qreal currentBottomSceneY=bottomSceneY + marginSpace;

  foreach (KMscFragmentRegion* region, this->regions())
    currentBottomSceneY=region->updateGeometry(currentBottomSceneY,
                                               marginSpace);

  QRectF childrenRect=this->childrenBoundingRect();
  childrenRect.setX(childrenRect.x() - this->_d->_offset);
  childrenRect.setWidth(childrenRect.width() + marginSpace);
  this->setRect(childrenRect);

  if((bottomSceneY + childrenRect.height()) > currentBottomSceneY )
    currentBottomSceneY = bottomSceneY + childrenRect.height();

  if(!this->_d->_typeItem)
  {
    QFont textFont;
    textFont.setBold(true);

    QString fragmentTypeString=model::msc::fragmentType2string(this->_d->_fragmentType);
    this->_d->_typeItem=new base::TextItem(fragmentTypeString, this);
    this->_d->_typeItem->setFont(textFont);
  }
  this->_d->_typeItem->setPos(childrenRect.x(),childrenRect.y());

  if(this->_d->_mscFragmentRegions.size()<=1)
    return currentBottomSceneY;

  Q_ASSERT(this->_d->_mscFragmentRegions.size()==this->_d->_seperatingLines.size()+1);

  int pos=0;
  foreach(KMscFragmentRegion const* currRegion, this->_d->_mscFragmentRegions)
  {
    if(pos > this->_d->_mscFragmentRegions.size() - 2)
      break;

    QRectF currRegionRect=currRegion->rect();

    QGraphicsLineItem* currSeperatingLine=this->_d->_seperatingLines.at(pos);
    Q_ASSERT(currSeperatingLine);
    currSeperatingLine->setLine(childrenRect.x(),
                                childrenRect.y()+currRegionRect.height(),
                                childrenRect.x()+childrenRect.width(),
                                childrenRect.y()+currRegionRect.height());

    ++pos;
  }

  return currentBottomSceneY;
}

}//////end namespace msc
}// end namespace view
