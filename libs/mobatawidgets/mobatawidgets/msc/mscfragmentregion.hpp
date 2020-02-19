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
#ifndef VIEW_MSC_MSCFRAGMENTREGION_HPP
#define VIEW_MSC_MSCFRAGMENTREGION_HPP

#include "../mobatawidgets_global.hpp"

#include "mscsequence.hpp"

namespace view{
namespace msc{

///forward declaration//////////////
class KMscFragment;

class MOBATAWIDGETSSHARED_EXPORT KMscFragmentRegion : public KMscSequence
{
public:
  KMscFragmentRegion(KMscFragment* parent,
                     const QString& condition=QString());
  virtual ~KMscFragmentRegion();

public:
  const QString&  condition() const;
  void            setCondition(const QString& condition);

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace);

private:
  Q_DISABLE_COPY(KMscFragmentRegion)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif
