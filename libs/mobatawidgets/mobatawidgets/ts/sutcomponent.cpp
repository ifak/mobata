#include "sutcomponent.hpp"

#include "../base/textitem.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

SutComponent::SutComponent(const QString& name,
                           const NodeOptions& sutCompOptions)
  : comp::Component(name, sutCompOptions)
{
  QRectF notationRect=this->notationItem()->boundingRect();

  QSizeF newSize(this->size());

  if(notationRect.width()>newSize.width())
    newSize.setWidth(notationRect.width());

  if(notationRect.height() > newSize.height())
    newSize.setHeight(notationRect.height());

  this->setSize(newSize);
  this->notationItem()->setPos(-notationRect.width()/2,
                               -notationRect.height()/2);
}

SutComponent::~SutComponent()
{}

} // namespace ts
} // namespace view

