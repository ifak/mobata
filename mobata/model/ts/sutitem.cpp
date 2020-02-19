#include "sutitem.hpp"

#include "testsuite.hpp"
#include "../msc/msccomponentitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace ts{

SutItem::SutItem(const QString &name)
  :	prop::NameProperty(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    PropLinks(this),
    PropComponents(this)
{
  this->setIcon(QIcon(":mobata/images/ts/sut.png"));
  this->setText(this->name());
}

SutItem::~SutItem()
{}

void SutItem::reset()
{
  this->resetAttributes();
  this->resetSignals();
  this->resetComponents();
  this->resetLinks();

  return;
}

QString SutItem::toString() const
{
  return this->name();
}

}///end namespace ts
}///end namespace model
