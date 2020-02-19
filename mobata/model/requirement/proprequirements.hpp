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
#ifndef MODEL_REQUIREMENT_PROPREQUIREMENTS_HPP
#define MODEL_REQUIREMENT_PROPREQUIREMENTS_HPP

#include "requirement_types.hpp"

#include <QList>

class QUuid;
class QStandardItem;


namespace model {
namespace irdl {

class PropRequirements
{
public:
  typedef QList<RequirementItem*>       RequirementsSet;
  typedef QList<RequirementItem const*> ConstRequirementsSet;

public:
  PropRequirements(QStandardItem* parentItem);
  virtual ~PropRequirements();

public:
  RequirementItem* requirement(const QUuid& testCaseUuid) const;
  RequirementsSet   requirements() const;

public:
  bool          addRequirement(RequirementItem* requirement,
                            QString* errorString = nullptr);
  RequirementItem* addRequirement(const QString& name);

  void removeRequirement(RequirementItem* testCase);
  void removeRequirement(const QUuid& testCaseId);

protected:
  void  resetRequirements();
  void  setRequirementsParentItem(QStandardItem* parent);

private:
  Q_DISABLE_COPY(PropRequirements)
  class Private;
  Private*  _d;
};

} // namespace requirement
} // namespace model

#endif // MODEL_REQUIREMENT_PROPREQUIREMENTS_HPP
