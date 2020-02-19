#include "phaseitem.hpp"

namespace trafficsim {

PhaseItem::PhaseItem(const QMap<QString,QString> states, double duration, const QString& name, double minDur, double maxDur):
    ModelItem("Phase"),_states(states),_duration(duration), _name(name), _minDur(minDur), _maxDur(maxDur)
{
    // Do nothing
}


PhaseItem::~PhaseItem()
{

}

QMap<QString,QString> PhaseItem::states() const
{
    return _states;
}

double PhaseItem::duration() const
{
    return _duration;
}

double PhaseItem::minDur() const
{
    return _minDur;
}

double PhaseItem::maxDur() const
{
    return _maxDur;
}

QString PhaseItem::name() const
{
    return _name;
}

}///end namespace trafficsim
