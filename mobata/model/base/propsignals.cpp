/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "propsignals.hpp"

#include <QStandardItem>

#include "signalitem.hpp"

#include "../../utils/functors.hpp"

namespace model {
namespace base {

class PropSignals::Private
{
  friend class PropSignals;

  Private()
    : _signalsItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _signalsItem;
};

PropSignals::PropSignals(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setSignalsParentItem(parentItem);
}

PropSignals::~PropSignals()
{
  delete this->_d;
}

void PropSignals::resetSignals()
{
  if(this->_d->_signalsItem)
    this->_d->_signalsItem->removeRows(0, this->_d->_signalsItem->rowCount());

  return;
}

void PropSignals::cloneSignals(PropSignals* cloneSignals) const
{
  Q_ASSERT(cloneSignals);

  bool result = false;
  for(SignalItem const* signalItem : this->getSignals())
  {
    SignalItem* cloneSignalItem = signalItem->clone();
    result = cloneSignals->addSignal(cloneSignalItem);
    Q_ASSERT(result);
  }

  return;
}

void PropSignals::setSignalsParentItem(QStandardItem* signalsParentItem)
{
  Q_ASSERT(signalsParentItem);

  if(this->_d->_signalsItem)
    return;

  this->_d->_signalsItem=new QStandardItem(QIcon
                                           (QLatin1String(":mobata/images/base/manysignal.png")),
                                           QLatin1String("signals"));
  this->_d->_signalsItem->setFlags(this->_d->_signalsItem->flags() & ~Qt::ItemIsEditable);
  signalsParentItem->appendRow(this->_d->_signalsItem);

  return;
}

SignalItem* PropSignals::addSignal(const QString& name,
                                   QString* errorString)
{
  Q_ASSERT(this->_d->_signalsItem);

  if(this->signal(name))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a signal '%1'!")
                                      .arg(name);
    return 0;
  }

  SignalItem* newSignalItem=new SignalItem(name);
  this->_d->_signalsItem->appendRow(newSignalItem);

  return newSignalItem;
}

bool PropSignals::addSignal(SignalItem* newSignal,
                            QString* errorString)
{
  Q_ASSERT(this->_d->_signalsItem);
  Q_ASSERT(newSignal);

  if(this->signal(newSignal->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a signal '%1'!")
                                      .arg(newSignal->name());
    return false;
  }

  this->_d->_signalsItem->appendRow(newSignal);

  return true;
}

void PropSignals::removeSignalByID(const QUuid& signalUuid)
{
  Q_ASSERT(this->_d->_signalsItem);

  SignalItem* remSignal = this->signal(signalUuid);
  if(remSignal)
    this->_d->_signalsItem->removeRow(remSignal->row());

  return;
}

void PropSignals::removeSignal(const QString& signalName)
{
  Q_ASSERT(this->_d->_signalsItem);

  SignalItem* remSignal = this->signal(signalName);
  if(remSignal)
    this->_d->_signalsItem->removeRow(remSignal->row());

  return;
}

PropSignals::SignalSet PropSignals::getSignals()
{
  SignalSet signalSet;
  if(!this->_d->_signalsItem)
    return signalSet;

  int end=this->_d->_signalsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    SignalItem* signal=utils::simple_cast<SignalItem*>(this->_d->_signalsItem->child(i));
    signalSet.append(signal);
  }

  return signalSet;
}

PropSignals::ConstSignalSet PropSignals::getSignals() const
{
  ConstSignalSet signalSet;
  if(!this->_d->_signalsItem)
    return signalSet;

  int end=this->_d->_signalsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    SignalItem* signal=utils::simple_cast<SignalItem*>(this->_d->_signalsItem->child(i));
    signalSet.append(signal);
  }

  return signalSet;
}

SignalItem* PropSignals::signal(const QString &signalName)
{
  for(SignalItem* signal : this->getSignals())
    if(signal->name()==signalName)
      return signal;

  return 0;
}

SignalItem const* PropSignals::signal(const QString &signalName) const
{
  for(SignalItem const* signal : this->getSignals())
    if(signal->name()==signalName)
      return signal;

  return 0;
}

SignalItem* PropSignals::signal(const QUuid &signalUuid)
{
  for(SignalItem* signalItem : this->getSignals())
    if(signalItem->uuid()==signalUuid)
      return signalItem;

  return 0;
}

SignalItem const* PropSignals::signal(const QUuid &signalUuid) const
{
  for(SignalItem const* signalItem : this->getSignals())
    if(signalItem->uuid()==signalUuid)
      return signalItem;

  return 0;
}

QString PropSignals::signalsDeclString() const
{
  QString declString=QStringLiteral("");
  for(SignalItem const* signal : this->getSignals())
  {
    declString+=signal->toString();
    declString+=QStringLiteral("\n");
  }

  if(!declString.isEmpty())
    declString.remove(declString.size(),1); //last "\n"

  return declString;
}

} // namespace base
} // namespace model

