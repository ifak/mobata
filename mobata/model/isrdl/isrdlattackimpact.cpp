#include "isrdlattackimpact.h"

namespace model{
namespace isrdl{

class IsrdlAttackImpact::Private
{
  friend class IsrdlAttackImpact;

  bool _confidentiality = false;
  bool _integrity       = false;
  int  _timeout         = -1;

  QStandardItem* confidentialityItem;
  QStandardItem* integrityItem;
  QStandardItem* timeoutItem;
  Private():
    confidentialityItem(new QStandardItem),
    integrityItem(new QStandardItem),
    timeoutItem(new QStandardItem)
  {}

  ~Private()
  {}
};

void IsrdlAttackImpact::update(){
  if(_d->_confidentiality)
    _d->confidentialityItem->setText(QString("confidentiality : broken"));
  else
    _d->confidentialityItem->setText(QString("confidentiality : intact"));

  if(_d->_integrity)
    _d->integrityItem->setText(QString("integrity : affected"));
  else
    _d->integrityItem->setText(QString("integrity : no damage"));

  if(_d->_timeout<0)
    _d->timeoutItem->setText(QString("availability : constant"));
  else
    _d->timeoutItem->setText(QString("availability : broken(>%0ms)").arg(QString::number(_d->_timeout)));
}

IsrdlAttackImpact::IsrdlAttackImpact():
  _d(new Private())
{
  this->setText(QString("AttackImpact"));
  appendRow(_d->confidentialityItem);
  appendRow(_d->integrityItem);
  appendRow(_d->timeoutItem);
  update();
}

IsrdlAttackImpact::~IsrdlAttackImpact()
{
  delete _d;
}

bool IsrdlAttackImpact::confidentiality()
{
  return _d->_confidentiality;
}

void IsrdlAttackImpact::setConfidentiality(bool conf)
{
  _d->_confidentiality = conf;
  update();
}

bool IsrdlAttackImpact::integrity()
{
  return _d->_integrity;
}

void IsrdlAttackImpact::setIntegrity(bool integ)
{
  _d->_integrity = integ;
  update();
}

int IsrdlAttackImpact::timeout()
{
  return  _d->_timeout;
}

void IsrdlAttackImpact::setTimeout(int timeout)
{
  _d->_timeout = timeout;
  update();
}

}
}
