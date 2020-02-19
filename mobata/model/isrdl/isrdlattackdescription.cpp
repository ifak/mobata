#include "isrdlattackdescription.h"
#include <QStandardItem>
#include <QList>

namespace model{
namespace isrdl{

class IsrdlAttackDescription::Private
{
  friend class IsrdlAttackDescription;

  AttackVector            _vector = Internet;
  QList<AttackPrivileges> _privs;

  QStandardItem*          vectorItem;
  QStandardItem*          privItem;
  QList<QStandardItem*>   privItemList;
  Private():
    vectorItem(new QStandardItem),
    privItem(new QStandardItem)
  {}

  ~Private()
  {}
};

IsrdlAttackDescription::IsrdlAttackDescription():
  _d(new Private())
{
  this->setText(QString("AttackDescription"));
  appendRow(_d->vectorItem);
  appendRow(_d->privItem);
  update();
}

IsrdlAttackDescription::~IsrdlAttackDescription()
{
  delete _d;
}

QList<AttackPrivileges> IsrdlAttackDescription::attackPrivileges()
{
  return _d->_privs;
}

void IsrdlAttackDescription::setAttackPrivileges(QList<AttackPrivileges> priv)
{
  _d->_privs = priv;
  update();
}

void IsrdlAttackDescription::addAttackPrivilege(AttackPrivileges priv)
{
  _d->_privs.append(priv);
  update();
}

AttackVector IsrdlAttackDescription::attackVector()
{
  return  _d->_vector;
}

void IsrdlAttackDescription::setAttackVector(AttackVector vec)
{
  _d->_vector = vec;
  update();
}

void IsrdlAttackDescription::update()
{
  switch (_d->_vector) {
  case(Internet):{
    _d->vectorItem->setText(QString("source: Internet"));
    break;
  }
  case(Local):{
    _d->vectorItem->setText(QString("source: Local"));
    break;
  }
  case(Physical):{
    _d->vectorItem->setText(QString("source: Physical"));
    break;
  }
  }
  _d->privItem->setText(QString("privileges"));
  _d->privItem->removeRows(0,_d->privItem->rowCount());
  _d->privItemList.clear();
  for(AttackPrivileges priv : _d->_privs){
    switch (priv) {
    case(Administrator):{
    QStandardItem* item = new QStandardItem(QString("Administrator"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    case(Install):{
    QStandardItem* item = new QStandardItem(QString("Install"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    case(Uninstall):{
    QStandardItem* item = new QStandardItem(QString("Uninstall"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    case(Save):{
    QStandardItem* item = new QStandardItem(QString("Save"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    case(Edit):{
    QStandardItem* item = new QStandardItem(QString("Edit"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    case(NoPrivileges):{
    QStandardItem* item = new QStandardItem(QString("NoPrivileges"));
    _d->privItemList.append(item);
    _d->privItem->appendRow(item);
    break;
    }
    }
  }
}

}
}
