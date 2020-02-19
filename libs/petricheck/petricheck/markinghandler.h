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
#ifndef MARKINGHANDLER_H
#define MARKINGHANDLER_H

/** This class enables firing of petrinet transitions by managing tokens on places. Such tokens used
 *  to be connected directly to places. But with a new thinking and algorithms, a marking list shall
 *  be separated from the places list. This allows to handle several markings for the whole net. The
 *  connections to places are now realized by saving their Uuids.
 */

#include <map>
#include <vector>
#include <QUuid>
#include <QSharedPointer>

namespace model
{	namespace spenat
  {	class TransitionItem;
    class SpenatModel;
  }
}

class MarkingHandler
{
public:
  MarkingHandler();
  ~MarkingHandler();
  void addInitMarking(const QUuid &placeID);
  void setGlobalEndPlace(const QUuid &placeID);
  bool tryToFireTrans(model::spenat::TransitionItem *trans, bool withTrigger);
  bool error();
  bool finished();
  void printMarkings();
  void fireAllReadyTrans(model::spenat::SpenatModel *petriNet);
  void registerLoopID(const QString &id);
  void addGuardToTransRelation(QString guard, model::spenat::TransitionItem *trans);

private:
  bool isTokenOnPlace(const QUuid &placeID);
  bool canTransFire(model::spenat::TransitionItem *trans, bool withTrigger);
  bool fireReadyTransOnce(model::spenat::SpenatModel *petriNet);
  void checkLoopCounterInc(const QString &transAction);

private:
  struct Private;
  Private *d;		// opaque pointer
};

#endif // MARKINGHANDLER_H
