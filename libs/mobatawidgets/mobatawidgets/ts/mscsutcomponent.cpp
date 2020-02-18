#include "mscsutcomponent.hpp"

#include "../msc/msccomponentlifeline.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

MscSutComponent::MscSutComponent(const QString& compName,
                                 const QUuid& referenceId,
                                 QGraphicsItem* parent)
  : msc::KMscComponent(compName, referenceId, parent)
{
  this->setBrush(QBrush(Qt::white));
  this->setPen(QPen(Qt::black, 3));

  this->lifeline()->setPen(QPen(Qt::black, 3));
}

MscSutComponent::MscSutComponent(const QString& compName,
                                 const QUuid& referenceId,
                                 const view::graph::NodeOptions& compOptions,
                                 const QColor& lifeLineColor,
                                 const qreal lifeLineWidth,
                                 QGraphicsItem* parent)
  : msc::KMscComponent(compName,
                       referenceId,
                       compOptions.textFont(),
                       compOptions.textColor(),
                       compOptions.size(),
                       compOptions.getColor(),
                       compOptions.pen(),
                       QPen(lifeLineColor, lifeLineWidth),
                       parent)
{
  // Do nothing
}

MscSutComponent::~MscSutComponent()
{}

} // namespace ts
} // namespace view

