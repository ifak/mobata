#include "petrigenerator.hpp"
#include "markinghandler.h"
#include "petriexception.h"

#include <triggermessage.h>
#include <triggermessageparam.h>
#include <mobata/model/diagnosis/diagnosisitem.hpp>
#include <mobata/model/diagnosis/diagsequenceruleitem.hpp>
#include <mobata/model/diagnosis/diagsignalitem.hpp>
#include <mobata/model/spenat/spenatmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>

#include <QMap>
#include <QDebug>
#include <QMultiMap>


struct PetriGenerator::Private
{
  Private(): petriNet(nullptr) {}
  QMap<QString, QString> parsedComponents;  // with name, check-guard
  QMap<QString, QString> parsedSignals;     // with name, check-guard
  model::spenat::SpenatModel *petriNet;
  MarkingHandler *markingHandler;
};

PetriGenerator::PetriGenerator()
  : _d(new Private())
{
  parsedActionId = 3401;  // Default for RSE
}

PetriGenerator::~PetriGenerator()
{
  delete _d;
}

/** Use a diagnosis model (created by ANTLR parser from text input) to create a Petri net. This can
 *  check network messages (e.g. from V2X) by modelling a sequence of target messages.
 */
model::spenat::SpenatModel* PetriGenerator::generatePetriFromDiagSequence(model::diagnosis::DiagnosisItem *diagModel)
{
  Q_ASSERT(diagModel);
  if (!diagModel)
    return nullptr;

//   First implementation: only one rule in one .rule file
  model::diagnosis::DiagnosisSequenceRuleItem* rule
      = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(diagModel->rules().at(0));
  Q_ASSERT(rule);
  if (!rule)
    return nullptr;

  // Read meta info, if needed
  //  diagSequence->name();
  //  rule->name();
  //  rule->description();
  //  rule->isEnabled();

  processSignalDeclarations(rule);
  processComponentDeclarations(rule);

  // TODO parse all sequence items
  StartAndEndPlace startAndEndPlace = preparePetriNet();
  Q_ASSERT(_d->petriNet);
  QVector<model::spenat::PlaceItem*> places;
  places.push_back(startAndEndPlace.first);


  try
  { createIntermediatePlaces(rule->sequenceItems().size(), &places);
    places.push_back(startAndEndPlace.second);
    processMscLevelNew(rule->sequenceItems(), &places);
//		printGeneratedNet();	// Test only
    Q_ASSERT(_d->markingHandler);
    _d->markingHandler->fireAllReadyTrans(_d->petriNet);
  }
  catch (PetriException &e)
  {	qWarning() << "Error in petri net creation: " << e.what();
    return _d->petriNet;
  }

  return _d->petriNet;
}

/** Return handler for place markings that has been created along with the Petri net.
 */
MarkingHandler *PetriGenerator::getMarkingHandler()
{
  return this->_d->markingHandler;
}

/** Get guard of this signal and its optional base signal, merge them. Save signal name and guard
 *  in map.
 */
void PetriGenerator::processSignalDeclarations(model::diagnosis::DiagnosisSequenceRuleItem *rule)
{
  Q_ASSERT(rule);
  if (!rule)
    return;

  model::base::PropSignals::SignalSet diagSignals = rule->getSignals();
  for (model::base::SignalItem* signal: diagSignals)
  {
    // Get signal name, must not be empty
    QString signalName = signal->name();
    Q_ASSERT(!signalName.trimmed().isEmpty());
    if (signalName.trimmed().isEmpty())
      continue;

    // Cast: The SignalItem should always be a DiagSignalItem
    model::diagnosis::DiagSignalItem* diagSignal
        = dynamic_cast<model::diagnosis::DiagSignalItem*>(signal);
    Q_ASSERT(diagSignal);
    if (!diagSignal)
      continue;

//    QString checkGuard = diagSignal->Guard();

//    if (model::diagnosis::DiagSignalItem* baseSignal = diagSignal->BaseSignal())
//    { QString baseCheckGuard = baseSignal->Guard();
//      checkGuard = checkGuard + " and " + baseCheckGuard;
//    }

//    _d->parsedSignals[signalName] = checkGuard;
  }
}

/** (same as for signals)
 */
void PetriGenerator::processComponentDeclarations(model::diagnosis::DiagnosisSequenceRuleItem *rule)
{
  Q_ASSERT(rule);
  if (!rule)
    return;

  QList<model::diagnosis::DiagComponentItem*> components = rule->components();
  for (model::diagnosis::DiagComponentItem* comp: components)
  {
    // Get component name, must not be empty
    QString compName = comp->name();
    Q_ASSERT(!compName.trimmed().isEmpty());
    if (compName.trimmed().isEmpty())
      continue;
    //TODO:@Tim: Change Guard check so that necessary and suffient checks are taken care of
    //QString checkGuard = comp->Guard();

//    if (model::diagnosis::DiagComponentItem* baseComp = comp->BaseComponent())
//    { QString baseCheckGuard = baseComp->Guard();
//      //checkGuard = checkGuard + " and " + baseCheckGuard;
//    }

//    _d->parsedComponents[compName] = checkGuard;
  }
}

/** Prepare basic Petri net model with global start and end places.
 */
StartAndEndPlace PetriGenerator::preparePetriNet()
{
  // Create the bare model
  _d->petriNet = new model::spenat::SpenatModel();
  // Add the global start place
  model::spenat::PlaceItem* startPlace = _d->petriNet->addPlace("start");
  _d->petriNet->addPlace(startPlace);
  _d->markingHandler = new MarkingHandler();
  _d->markingHandler->addInitMarking(startPlace->uuid());
  // Add the global end place
  model::spenat::PlaceItem* endPlace = _d->petriNet->addPlace("end");
  _d->petriNet->addPlace(endPlace);
  _d->markingHandler->setGlobalEndPlace(endPlace->uuid());

  return std::make_pair(startPlace, endPlace);
}

// NOTE Warn when seqItemList is empty?
void PetriGenerator::createIntermediatePlaces(int seqItemListSize, QVector<model::spenat::PlaceItem *> *places)
{
  Q_ASSERT(places);
  if (!places)
    return;

  for (int i=1; i<seqItemListSize; ++i)
  {	QString errorStr("");
    QString placeName = getUniquePlaceName("inter");
    model::spenat::PlaceItem* interPlace = _d->petriNet->addPlace(placeName, &errorStr);
    if (!errorStr.isEmpty() || !interPlace)
    {	qWarning() << "Error during creation of inter place: " << errorStr << " Aborting.";
      return;
    }
    _d->petriNet->addPlace(interPlace);
    places->push_back(interPlace);
  }
}

QString PetriGenerator::getUniquePlaceName(const QString &baseName)
{
  int interPlacesCount = _d->petriNet->places().size();
  int interPlaceNum = interPlacesCount - 2 + 1;	// Substract start and end place and start with 1
  QString uniquePlaceName = baseName + "_" + QString::number(interPlaceNum);
  return uniquePlaceName;
}

// NOTE Warn when seqItemList is empty?
void PetriGenerator::processMscLevelNew(const model::msc::MscSequence::ConstSequenceItems &seqItemList, QVector<model::spenat::PlaceItem *> *places)
{
  Q_ASSERT(places);
  if (!places)
    return;

  // Traverse sequence
  for (int i=0; i<seqItemList.size(); ++i)
  {	model::spenat::PlaceItem *prePlace = places->at(i);
    model::spenat::PlaceItem *postPlace = places->at(i+1);
    model::msc::MscSequenceItem const* seqItem = seqItemList.at(i);
    // NOTE Alternative for dynamic_cast? We need to get the derived type.
    if (model::msc::MscCheckMessageItem const* msgItem = dynamic_cast<model::msc::MscCheckMessageItem const*>(seqItem))
    { // (In PROGES, a ProgesMscMessageItem is derived from a MscSequenceItem to contain actions)
      processMsg(msgItem, prePlace, postPlace);
    }
    else if (model::msc::MscFragmentItem const* fragmentItem = dynamic_cast<model::msc::MscFragmentItem const*>(seqItem))
    {
      // FIXME Implement from PROGES
      Q_UNUSED(fragmentItem);
//      if (ParFragment const* par = dynamic_cast<ParFragment const*>(fragmentItem))
//      {	processFragPar(par, prePlace, postPlace);
//      }

//				else if (AltFragment const* alt = dynamic_cast<AltFragment const*>(fragmentItem))
//				{
//					processFragAlt(alt, prePlace, postPlace);
//				}
//				else if (OptFragment const* opt = dynamic_cast<OptFragment const*>(fragmentItem))
//				{
//					processFragOpt(opt, prePlace, postPlace);
//				}

      // FIXME Implement from PROGES
//      else if (LoopFragment const* loop = dynamic_cast<LoopFragment const*>(fragmentItem))
//      {	processFragLoop(loop, prePlace, postPlace);
//      }

//				else if (ConsiderFragment const* consider = dynamic_cast<ConsiderFragment const*>(fragmentItem))
//				{
//					processFragConsider(consider, prePlace, postPlace);
//				}
//      else
        qWarning() << "Can't process unknown MSC fragment.";
    }
    //		else if(model::msc::MscTimerItem const* timerItem = dynamic_cast<model::msc::MscTimerItem const*>(generalItem))
    //		{
    //			// TODO
    //		}
    else
      qWarning() << "Can't process unknown MSC item.";
  }
}

model::spenat::TransitionItem *PetriGenerator::processMsg(const model::msc::MscCheckMessageItem *msgItem, model::spenat::PlaceItem *prevPlace, model::spenat::PlaceItem *nextPlace)
{
  QString msgName = msgItem->text();  // NOTE Is the text saved during MSC parsing?

  // Create the msg trans in between
  QString transName = getUniqueTransName(msgName);
  // Adding an empty SignalItem as a trigger to indicate that an outer signal (done by a TriggerMessage)
  // must activate this trans. This helps to distinguish from intermediate trans of fragments.
  model::base::SignalItem *modelingSignal = new model::base::SignalItem();
  model::spenat::SignalTriggerItem *modelingTrigger = new model::spenat::SignalTriggerItem(modelingSignal);
  model::spenat::TransitionItem *msgTrans = new  model::spenat::TransitionItem(transName, modelingTrigger);

  QString errorStr("");
  bool success = _d->petriNet->addTransition(msgTrans, &errorStr);
  if (!success)
  {	qWarning() << errorStr;
    return nullptr;
  }
  // Connect msg trans to surrounding places, then update them
  msgTrans->addPrePlaceArc(prevPlace);
  msgTrans->addPostPlaceArc(nextPlace);

  // TODO Save info of guards, merge with other guards
//  qDebug() << "*** guard:";
//  qDebug() << msgItem->guard();
  QString guard = msgItem->guard();
//  guard.replace("AND", "&");
//  _d->markingHandler->addGuardToTransRelation(guard, msgTrans);

  // Temp. solution: Only read the actionID
  QString keyword = "actionID == ";
  int actionIdPos = guard.indexOf(keyword);
  if ((actionIdPos != -1) && (guard.size() > actionIdPos))
  {
    QString actionIdStr = guard.mid(actionIdPos + keyword.size());
    qDebug() << "*** actionIdStr: " << actionIdStr;
    parsedActionId = actionIdStr.toInt();
    qDebug() << "*** num: " << parsedActionId;
  }

  return msgTrans;
}

QString PetriGenerator::getUniqueTransName(const QString &baseName)
{
  int transCount = _d->petriNet->transitions().size();
  QString uniqueTransName = baseName + "_" + QString::number(transCount + 1);	// Start with 1
  return uniqueTransName;
}
