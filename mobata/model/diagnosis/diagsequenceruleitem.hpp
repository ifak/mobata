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
#ifndef MODEL_DIAGNOSIS_DIAGNOSISSEQUENCERULEITEM_HPP
#define MODEL_DIAGNOSIS_DIAGNOSISSEQUENCERULEITEM_HPP


#include "../msc/mscsequence.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"
#include "../base/propdatatypes.hpp"

namespace model{
namespace diagnosis{

class DiagnosisSequenceRuleItem
        : public msc::MscSequence,
        public base::PropDataTypes,
        public base::PropAttributes,
        public base::PropSignals
{
public:
    DiagnosisSequenceRuleItem(const QString& name=QStringLiteral("diagnosis"))
        : msc::MscSequence(name),
          base::PropDataTypes(this),
          base::PropAttributes(this),
          base::PropSignals(this)
    {}
    ~DiagnosisSequenceRuleItem(){
        reset();
    }

    virtual void reset(){
        for(auto comp : _components){
            delete(comp);
        }
        _components.clear();
    }

    virtual void addComponent(DiagComponentItem* item){
        _components.append(item);
    }
    virtual QList<DiagComponentItem*> components(){
        return _components;
    }
    void setDescription(QString descprition){
        _description = descprition;
    }
    const QString description(){
        return _description;
    }

private:
    Q_DISABLE_COPY(DiagnosisSequenceRuleItem)
    QList<DiagComponentItem*> _components;
    QString _description;
};

}///end namespace ts
}/// end namespace model

#endif // MODEL_DIAGNOSIS_DIAGNOSISSEQUENCERULEITEM_HPP
