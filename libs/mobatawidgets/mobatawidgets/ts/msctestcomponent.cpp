#include "msctestcomponent.hpp"

#include "../msc/msccomponentlifeline.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

MscTestComponent::MscTestComponent(const QString& compName,
                                   const QUuid& referenceId,
                                   QGraphicsItem* parent)
    : msc::KMscComponent(compName, referenceId, parent)
{
  this->setBrush(QBrush(Qt::white));
  this->setPen(QPen(Qt::darkRed, 3));

  this->lifeline()->setPen(QPen(Qt::darkRed, 3));
}

MscTestComponent::MscTestComponent(const QString& compName,
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

MscTestComponent::~MscTestComponent()
{}

} // namespace ts
} // namespace view

