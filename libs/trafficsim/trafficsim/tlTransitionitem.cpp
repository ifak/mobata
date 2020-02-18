#include "tlTransitionitem.hpp"

namespace trafficsim {
TlTransitionItem::TlTransitionItem(PhaseItem* startPhase,QList<PhaseItem*> transitionPhases,PhaseItem* endPhase,QList<QString> trigger):
    model::base::ModelItem("Transition"),
    _startPhase(startPhase),
    _endPhase(endPhase),
    _transitionPhases(transitionPhases),
    _trigger(trigger)
{}

QList<PhaseItem*> TlTransitionItem::transitionPhases(){
    return _transitionPhases;
}

void TlTransitionItem::addTransitionPhases(PhaseItem* phase){
    _transitionPhases.append(phase);
}

PhaseItem* TlTransitionItem::startPhase(){
    return _startPhase;
}

PhaseItem* TlTransitionItem::endPhase(){
    return _endPhase;
}

QList<QString> TlTransitionItem::trigger(){
    return _trigger;
}

void TlTransitionItem::addTrigger(QString trigger){
    _trigger.append(trigger);
}

}///end namespace trafficsim
