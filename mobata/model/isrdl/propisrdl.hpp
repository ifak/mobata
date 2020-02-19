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

#include "isrdl_types.hpp"

#include <QList>

class QUuid;
class QStandardItem;


namespace model {
namespace isrdl {

class PropIsrdl
{
public:
  typedef QList<IsrdlItem*>       IsrdlSet;
  typedef QList<IsrdlItem const*> ConstIsrdlSet;

public:
  PropIsrdl(QStandardItem* parentItem);
  virtual ~PropIsrdl();

public:
  IsrdlItem* isrdlItem(const QUuid& testCaseUuid) const;
  IsrdlSet   isrdlItems() const;

public:
  bool          addIsrdlItem(IsrdlItem* isrdl,
                            QString* errorString=nullptr);
  IsrdlItem* addIsrdlItem(const QString& name);

  void removeIsrdlItem(IsrdlItem* isrdlItem);
  void removeIsrdlItem(const QUuid& isrdlUuid);

protected:
  void  resetIsrdlItems();
  void  setIsrdlParentItem(QStandardItem* parent);

private:
  Q_DISABLE_COPY(PropIsrdl)
  class Private;
  Private*  _d;
};

} // namespace isrdl
} // namespace model

#endif // MODEL_REQUIREMENT_PROPREQUIREMENTS_HPP
