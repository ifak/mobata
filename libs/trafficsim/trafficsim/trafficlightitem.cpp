#include "trafficlightitem.hpp"

namespace trafficsim {

TrafficLightItem::TrafficLightItem(const QString& name, const QString& type, const int duration, const int turns, const bool createPhases)
    :ModelItem(name), _type(type), _duration(duration), _turns(turns), _createPhases(createPhases)
{
    // Do nothing
}
TrafficLightItem::~TrafficLightItem()
{
    // Do nothing
}

const QList<PhaseItem* > &TrafficLightItem::phases() const
{
    return _phases;
}


QString TrafficLightItem::trafficLightType() const
{
    return _type;
}

QString TrafficLightItem::id() const
{
    return _id;
}

void TrafficLightItem::addPhases(PhaseItem *&newPhase)
{
    _phases.append(newPhase);
}

void TrafficLightItem::setID(const QString &id)
{
    _id = id;
}

double TrafficLightItem::duration() const
{
    return _duration;
}

void TrafficLightItem::setDuration(int duration)
{
    _duration = duration;
}

void TrafficLightItem::setCreatePhases(bool createPhases)
{
    _createPhases = createPhases;
}

bool TrafficLightItem::createPhases() const
{
    return _createPhases;
}

int TrafficLightItem::turns() const
{
    return _turns;
}

const QList<TlTransitionItem *> &TrafficLightItem::transitions() const{
    return _transitions;
}
void TrafficLightItem::addTransitions(TlTransitionItem* &newTransition){
    _transitions.append(newTransition);
}

}///end namespace trafficsim
