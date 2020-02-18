#include "markinghandler.h"

#include "mobata/model/spenat/transitionitem.hpp"
#include "mobata/model/spenat/spenatbasemodel.hpp"
#include "mobata/model/spenat/preplacearc.hpp"
#include "mobata/model/spenat/postplacearc.hpp"
#include "mobata/model/spenat/placeitem.hpp"
#include "mobata/model/spenat/spenatmodel.hpp"

#include <QDebug>
#include <QScriptEngine>


struct MarkingHandler::Private
{
    Private(): globalEndPlace(QUuid::createUuid()) {}
  QScriptEngine scriptEngine;		// For computing transition guards with boolean expressions
  std::map<QUuid, bool> _markingPerPlace;	// NOTE Integrate into vector to handle multi markings
  QUuid globalEndPlace;
  std::vector<QUuid> errorPlaces;	// NOTE Add creation algo for consider frag
  QMultiMap<QString, model::spenat::TransitionItem*> validSignalsToTrans;
};

MarkingHandler::MarkingHandler()
  : d(new Private())
{
}

MarkingHandler::~MarkingHandler()
{
  delete d;
}

void MarkingHandler::addInitMarking(const QUuid &placeID)
{
  d->_markingPerPlace[placeID] = true;
}

void MarkingHandler::setGlobalEndPlace(const QUuid &placeID)
{
  d->globalEndPlace = placeID;
}

/** Currently a map saves Uuids of places. If an ID is found and its entry is true this be will
 *  interpreted as a token lying on this place.
 */
bool MarkingHandler::isTokenOnPlace(const QUuid &placeID)
{
  if (d->_markingPerPlace.count(placeID) > 0)
    return d->_markingPerPlace[placeID];
  else
    return false;
}

bool MarkingHandler::fireReadyTransOnce(model::spenat::SpenatModel *petriNet)
{
  Q_ASSERT(petriNet);
  if (!petriNet)
    return false;
  bool firedAnyTrans = false;
  using namespace model::spenat;

  SpenatBaseModel::TransitionSet transitions = petriNet->transitions();
  for (TransitionItem* trans: transitions)
  {	bool firedThisTrans = tryToFireTrans(trans, false);
    if (firedThisTrans)
    {	firedAnyTrans = true;
    }
  }

  return firedAnyTrans;
}

/** Check if there's a command to increase a loop counter. If so, increase it now.
 */
void MarkingHandler::checkLoopCounterInc(const QString &transAction)
{
  if (transAction.left(2) == "i_")
  {	QString loopID = transAction;	// FIXME Adjust for several loop IDs and actions
    qint32 count = d->scriptEngine.globalObject().property(loopID).toInt32();
    d->scriptEngine.globalObject().setProperty(loopID, count+1);
//		qDebug() << "Increased loop " << loopID << " to " << count+1;
  }
}

/** Check conditions for firing this transition. Currently implemented:
 *  - There must be one token on every pre place and none on every post place
 *  - Distinguish between msg trans (fired by a trigger) and inter trans (without a trigger)
 */
bool MarkingHandler::canTransFire(model::spenat::TransitionItem *trans, bool withTrigger)
{
  using namespace model::spenat;

  // Check that trans with trigger requirement only gets fired by an outer trigger signal
  if ((bool)trans->triggerItem() != withTrigger)
    return false;

  // Check the (optional) guard
  QString guard = trans->guard();
  if (!guard.isEmpty())
  {	bool guardResult = d->scriptEngine.evaluate(guard).toBool();
//		qDebug() << "Loop counter i_1 is " << d->scriptEngine.globalObject().property("i_1").toInt32();
//		qDebug() << "Guard " << guard << " evaluates to " << guardResult;
    if (!guardResult)
      return false;
  }

  // Check that all pre places HAVE token
  TransitionItem::PrePlaceArcSet preArcs = trans->prePlaceArcs();
  for (PrePlaceArc const* preArc: preArcs)
  {
    const PlaceItem* prePlace = preArc->place();
    QUuid prePlaceID = prePlace->uuid();
    if (!isTokenOnPlace(prePlaceID))
      return false;
  }

  // Check that all post places DON'T have token
  TransitionItem::PostPlaceArcSet postArcs = trans->postPlaceArcs();
  for (PostPlaceArc const* postArc: postArcs)
  {
    const PlaceItem* postPlace = postArc->place();
    QUuid postPlaceID = postPlace->uuid();
    if (isTokenOnPlace(postPlaceID))
      return false;
  }

  return true;
}

/** Arc weight is always 1 - therefore remove 1 token from pre places and put 1 on post places
 *  (ergo set value for place's UUID to true or false).
 */
bool MarkingHandler::tryToFireTrans(model::spenat::TransitionItem *trans, bool withTrigger)
{
  if (!trans)
  {	qDebug() << "No trans to fire...";
    return false;
  }
  if (!canTransFire(trans, withTrigger))
  {	//qWarning() << "Token conditions of trans " << trans->name() << " not fulfilled, can't fire!";
    return false;
  }
  using namespace model::spenat;

  // Take token from every pre place
  TransitionItem::PrePlaceArcSet preArcs = trans->prePlaceArcs();
  for (PrePlaceArc const* preArc: preArcs)
  {	QUuid placeID = preArc->place()->uuid();
    d->_markingPerPlace[placeID] = false;
  }

  // Put token on every post place
  TransitionItem::PostPlaceArcSet postArcs = trans->postPlaceArcs();
  for (PostPlaceArc const* postArc: postArcs)
  {	QUuid placeID = postArc->place()->uuid();
    d->_markingPerPlace[placeID] = true;
  }

  checkLoopCounterInc(trans->actions());
  qDebug() << "Fired trans " << trans->name();

  return true;
}

/** The current test event is regarded wrong when there's a token on any error place. Therefore,
 *  check every error place for tokens.
 */
bool MarkingHandler::error()
{
  for (QUuid const& placeID: d->errorPlaces)
  {	if (isTokenOnPlace(placeID))
      return true;
  }

  return false;
}

/** The current test is regarded complete when there's a token on the global end place.
 */
bool MarkingHandler::finished()
{
  if (isTokenOnPlace(d->globalEndPlace))
    return true;
  else
    return false;
}

/** Print uuids of places where currently tokens are lying. In combination with the graph in the GUI
 *  this helps to check the firing algorithm.
 */
void MarkingHandler::printMarkings()
{
  qDebug() << "Tokens currently on those places:";	// NOTE For better readability, save/get the place's name
  for (auto const& marking : d->_markingPerPlace)
  {	bool tokenIsSet = marking.second;
    if (tokenIsSet)
    {	QUuid tokenID = marking.first;
      qDebug() << tokenID;
    }
  }
}

/** Fire transitions where the token conditions are currently fulfilled. Repeat this until nothing
 *  can fire anymore. This is needed for non-message trans like the start and end of fragments.
 */
void MarkingHandler::fireAllReadyTrans(model::spenat::SpenatModel *petriNet)
{
  Q_ASSERT(petriNet);
  if (!petriNet)
    return;
  while (fireReadyTransOnce(petriNet));
}

/** If a loop fragment has been processed during petri net creation, an unique ID has been created
 *  and saved within transition actions. Initialize the ID to check it at runtime.
 */
void MarkingHandler::registerLoopID(const QString &id)
{
  d->scriptEngine.globalObject().setProperty(id, 0);
}

void MarkingHandler::addGuardToTransRelation(QString guard, model::spenat::TransitionItem *trans)
{
  d->validSignalsToTrans.insert(guard, trans);
}
