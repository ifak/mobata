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
#pragma once

#include <QVector>
#include <QUuid>

namespace model {
namespace msc {

enum MscCoverageType
{
  UnknownCoverageItem,
  PlaceCoverageItem,
  TransitionCoverageItem,
  RequirementCoverageItem,
  MscCoverageUserItem
};

inline
QString coverageType2string(const MscCoverageType coverageType)
{
  if(coverageType == PlaceCoverageItem)
    return QLatin1String("PlaceCoverageItem");
  else if(coverageType == TransitionCoverageItem)
    return QLatin1String("TransitionCoverageItem");
  else if(coverageType == RequirementCoverageItem)
    return QLatin1String("RequirementCoverageItem");

  return QLatin1String("UnknownCoverage");
}

inline
MscCoverageType string2coverageType(const QString& coverageTypeString)
{
  if(coverageTypeString == QLatin1String("PlaceCoverageItem"))
    return PlaceCoverageItem;
  else if(coverageTypeString == QLatin1String("TransitionCoverageItem"))
    return TransitionCoverageItem;
  else if(coverageTypeString == QLatin1String("RequirementCoverageItem"))
    return RequirementCoverageItem;

  return UnknownCoverageItem;
}

class MscCoverageItem
{
public:
  MscCoverageItem()
    : _uuid(), _coverageType(UnknownCoverageItem)
  {}

  MscCoverageItem(const QString& name,
                  const QUuid& uuid,
                  const MscCoverageType coverageType)
    : _name(name), _uuid(uuid), _coverageType(coverageType)
  {}

public:
  const QString&  name() const          {return this->_name;}
  const QUuid&    uuid() const          {return this->_uuid;}
  MscCoverageType coverageType() const  {return this->_coverageType;}

private:
  QString         _name;
  QUuid           _uuid;
  MscCoverageType _coverageType;
};

class MscPropCoverages
{
public:
  typedef QVector<MscCoverageItem> CoverageItemSet;

public:
  MscPropCoverages();
  MscPropCoverages(const MscPropCoverages& orig);
  virtual ~MscPropCoverages();

public:
  void  addCoverageItem(const MscCoverageItem& coverageItem);
  void  addCoverageItem(const QString& name,
                        const QUuid& uuid,
                        const MscCoverageType coverageType);

public:
  const CoverageItemSet&  coverageItems() const;

protected:
  void  resetCoverageItems();

protected:
  CoverageItemSet _coverageItems;
};

} // namespace msc
} // namespace model
