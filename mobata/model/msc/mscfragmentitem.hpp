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

#include "../../mobata_global.hpp"

#include "msc_types.hpp"

#include "mscsequenceitem.hpp"

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscFragmentItem
    : public MscSequenceItem
{
public:
  typedef QList<MscFragmentRegionItem const*> ConstMscRegionSet;
  typedef QList<MscFragmentRegionItem*>       MscRegionSet;
  typedef QList<MscComponentItem const*>      ConstComponentItems;

public:
  MscFragmentItem(int type);
  virtual ~MscFragmentItem();

public:
  virtual int     stepType() const        { return FragmentStep;}
  virtual QString stepTypeString() const  { return QLatin1String(constants::FragmentStepId);}

public:
  int   fragmentType() const;
  void  setFragmentType(int fragmentType);

  MscFragmentRegionItem*  addRegion(const QString &condition=QString());
  bool                    addRegion(MscFragmentRegionItem* newFragmentRegion);
  ConstMscRegionSet       regions() const;
  MscRegionSet            regions();

  ConstComponentItems     componentItems() const;

  void                    setDuration(uint duration /* ms*/);
  uint                    duration() const;

private:
  Q_DISABLE_COPY(MscFragmentItem)
  class Private;
  QScopedPointer<Private> _d;
};

}/// end namespace msc
}/// end namespace model
