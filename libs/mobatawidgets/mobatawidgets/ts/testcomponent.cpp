#include "testcomponent.hpp"

namespace view{
namespace ts{


class TestComponent::Private
{
  friend class TestComponent;

  Private()   {}
  ~Private()  {}
};

TestComponent::TestComponent(const QString& notation,
                             const comp::NodeOptions &nodeOptions)
  : Component(notation, nodeOptions),
    _d(new Private())
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

TestComponent::~TestComponent()
{
  delete this->_d;
}


} //end namespace ts
} //end namespace view


