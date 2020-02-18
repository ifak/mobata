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
#ifndef MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP
#define MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP

#include "requirement_types.hpp"

#include "../base/basemodel.hpp"
#include "../base/propattributes.hpp"
#include "../base/propcomponents.hpp"
#include "proprequirements.hpp"

namespace model{
namespace msc {
    class MscFragmentRegionItem;
}
namespace irdl{

class MOBATASHARED_EXPORT RequirementsModel
    : public base::BaseModel,
    public base::PropComponents,
    public PropRequirements
{

public:
  explicit RequirementsModel(QObject *parent = nullptr);
  virtual ~RequirementsModel();

public:
  virtual void reset();

public:
    void addContent(RequirementsModel* model, QString *errorString = nullptr);
    void addContent(BaseModel* model, QString *errorString = nullptr);

private:
  void copyRegion(msc::MscFragmentRegionItem *origReg ,msc::MscFragmentRegionItem *copyReg);
  void addSequenceItem(msc::MscSequence *seq ,msc::MscSequenceItem *seqItem);

private:
  Q_DISABLE_COPY(RequirementsModel)
  class Private;
  Private*	_d;
};

typedef QSharedPointer<RequirementsModel> RequirementModelPtr;

}///end namespace requirement
}///end namespace model

#endif // MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP
