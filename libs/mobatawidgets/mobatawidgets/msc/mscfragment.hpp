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
#ifndef VIEW_MSC_MSCFRAGMENT_HPP
#define VIEW_MSC_MSCFRAGMENT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <QGraphicsRectItem>
#include "mscsequencestep.hpp"

namespace view{
namespace msc{

////forward declaration
class KMscFragmentRegion;

class MOBATAWIDGETSSHARED_EXPORT KMscFragment
    : public QGraphicsRectItem,
    public MscSequenceStep
{
public:
  typedef QList<KMscFragmentRegion const*> ConstMscRegionSet;
  typedef QList<KMscFragmentRegion*>       MscRegionSet;

public:
  KMscFragment(int fragmentType, KMscSequence* parentSequence);
  virtual ~KMscFragment();

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace);

public:
  int  fragmentType() const;
  void setFragmentType(int fragmentType);

public:
  KMscFragmentRegion*  addRegion(const QString &condition=QString());
  ConstMscRegionSet    regions() const;
  MscRegionSet         regions();

private:
  Q_DISABLE_COPY(KMscFragment)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif
