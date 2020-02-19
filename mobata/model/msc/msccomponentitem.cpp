#include "msccomponentitem.hpp"

namespace model {
namespace msc {

MscComponentItem::MscComponentItem(const QString& name)
  : base::ComponentItem(name)
{
  QString errorString;
  this->_defaultPort = this->addPort(QStringLiteral("_defaultPort"), &errorString);
  Q_ASSERT(this->_defaultPort);
  this->setText(this->toString());
}

MscComponentItem::~MscComponentItem()
{}

base::PortItem const* MscComponentItem::defaultPort() const
{
  return this->_defaultPort;
}

} // namespace msc
} // namespace model

