/*
 * This file is part of mobata.
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
#ifndef MODEL_BASE_PROPSIGNALS_HPP
#define MODEL_BASE_PROPSIGNALS_HPP

#include <QList>
#include <QUuid>

class QStandardItem;

namespace model {
namespace base {

class SignalItem;

class PropSignals
{
public:
  typedef QList<SignalItem*>        SignalSet;
  typedef QList<SignalItem const*>  ConstSignalSet;

public:
  PropSignals(QStandardItem* parentItem);
  virtual ~PropSignals();

public:
  SignalItem*       addSignal(const QString& name,
                              QString* errorString=0);
  bool              addSignal(SignalItem* newSignal,
                              QString* errorString=0);
  void              removeSignalByID(const QUuid& signalUuid);
  void              removeSignal(const QString& signalName);
  SignalSet         getSignals();
  ConstSignalSet    getSignals() const;
  SignalItem*       signal(const QString& signalName);
  SignalItem const* signal(const QString& signalName) const;
  SignalItem*       signal(const QUuid& signalUuid);
  SignalItem const* signal(const QUuid& signalUuid) const;

public:
  QString signalsDeclString() const;
    void  cloneSignals(PropSignals* cloneSignals) const;

protected:
  void  resetSignals();
  void  setSignalsParentItem(QStandardItem* signalsParentItem);

private:
  Q_DISABLE_COPY(PropSignals)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model

#endif // MODEL_BASE_PROPSIGNALS_HPP
