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
#ifndef TlTransitionItem_H
#define TlTransitionItem_H

#include <mobata/model/base/modelitem.hpp>

#include "phaseitem.hpp"

namespace trafficsim {

class PhaseItem;

class TlTransitionItem : public model::base::ModelItem
{
public:
    TlTransitionItem(PhaseItem* startPhase,
                     QList<PhaseItem*> transitionPhases,
                     PhaseItem* endPhase,
                     QList<QString> trigger);
    QList<PhaseItem*> transitionPhases();
    void addTransitionPhases(PhaseItem* phase);
    QList<QString> trigger();
    void addTrigger(QString trigger);
    PhaseItem* startPhase();
    PhaseItem* endPhase();

private:
    PhaseItem* _startPhase;
    PhaseItem* _endPhase;
    QList<PhaseItem*> _transitionPhases;
    QList<QString> _trigger;
};
}//namespace trafficsim
#endif // TlTransitionItem_H
