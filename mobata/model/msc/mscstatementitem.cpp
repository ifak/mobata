#include "mscstatementitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscStatementItem::Private
{
  friend class MscStatementItem;

  Private(const QString& statement)
    : _statement(statement)
  {}

public:
  ~Private()  {}

private:
  QString _statement;
};

MscStatementItem::MscStatementItem(const MscComponentItem* component,
                                   const QString& statement)
  :	MscStepItem(component),
    _d(new Private(statement))
{
  Q_ASSERT(component);

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/statement.png")));
  this->setText(this->toString());

}

MscStatementItem::~MscStatementItem()
{
  delete this->_d;
}

const QString& MscStatementItem::statement() const
{
  return this->_d->_statement;
}

void MscStatementItem::setStatement(const QString& statement)
{
  this->_d->_statement=statement;

  return;
}

QString MscStatementItem::toString() const
{
  return _d->_statement;
}

}/// end namespace msc
}/// end namespace model
