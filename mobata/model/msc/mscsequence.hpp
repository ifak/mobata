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
#pragma once

#include "../../mobata_global.hpp"

#include "msc_types.hpp"
#include "msccomponentitem.hpp"

#include "../base/modelitem.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscSequence
    : public base::ModelItem,
    public prop::NameProperty
{
public:
  typedef QList<MscComponentItem const*>  ConstComponentItems;
  typedef QList<MscSequenceItem const*>   ConstSequenceItems;

public:
  explicit MscSequence(const QString &name=QStringLiteral(""));
  virtual ~MscSequence();

public:
  virtual void          reset();

public:
  MscMessageItem*       addMessage(MscComponentItem const* sourceComponent,
                                   MscComponentItem const* targetComponent,
                                   const QString& messageText=QString());
  MscMessageItem*       addMessage(PortItem const* sourcePort,
                                   PortItem const* targetPort,
                                   const QString& messageText=QString());
  bool                  addMessage(MscMessageItem* newMessage);
  MscCheckMessageItem*  addCheck( MscComponentItem const* sourceComponent,
                                  MscComponentItem const* targetComponent,
                                  const QString& messageText=QString());
  MscCheckMessageItem*  addCheck( PortItem const* sourcePort,
                                  PortItem const* targetPort,
                                  const QString& messageText=QString());
  bool                  addCheck( MscCheckMessageItem* newCheckMessage);

  MscTimerItem*         addTimer(MscComponentItem const* component,
                                 const QString& timerName,
                                 QString* errorMessage=nullptr);
  MscSleepTimerItem*    addSleepTimer(MscComponentItem const* component,
                                      double duration);
  MscTimeoutItem*       addTimeout(MscComponentItem const* component,
                                   MscTimerItem const* timer);
  MscFragmentItem*      addFragment(FragmentType fragmentType);
  void                  addFragment(MscFragmentItem* newFragment );
  MscStatementItem*     addStatement(MscComponentItem const* component,
                                     const QString& statement);
  MscTimerItem const*   timer(const QString& timerName);
  MscTimerItem const*   timer(const QUuid& timerUuid);

public:
  ConstComponentItems     componentItems() const;
  MscComponentItem const* component(const QUuid& uuid) const;
  ConstSequenceItems      sequenceItems() const;
  MscSequenceItem const*  sequenceItem(const QUuid& sequItemID) const;

protected:
  QList<MscTimerItem const*>  timers() const;

private:
  Q_DISABLE_COPY(MscSequence)
  class Private;
  Private* _d;
};

}/// end namespace msc
}/// end namespace model
