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
#ifndef MODEL_BASE_LINKITEM_HPP
#define MODEL_BASE_LINKITEM_HPP

#include "../../mobata_global.hpp"

#include "modelitem.hpp"

namespace model {
namespace base {

class PortItem;

class MOBATASHARED_EXPORT LinkItem
    : public ModelItem
{
public:
  LinkItem(PortItem const* from,
           PortItem const* to,
           const QString& notation=QStringLiteral(""));

  virtual ~LinkItem();

public:
  PortItem const* from() const;
  PortItem const* to() const;
  PortItem const* port() const;

  void            setNotation(const QString& notation);
  const QString&  notation() const;
  virtual QString toString() const;

private:
  Q_DISABLE_COPY(LinkItem)
  class Private;
  Private* _d;
};

} // namespace base
} // namespace model

#endif // MODEL_BASE_LINKITEM_HPP
