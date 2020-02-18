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
#ifndef VIEW_TS_MSCTESTRESULT_HPP
#define VIEW_TS_MSCTESTRESULT_HPP

#include "../mobatawidgets_global.hpp"

#include "../msc/mscstatement.hpp"

#include "msctestcomponent.hpp"

namespace view {
namespace ts {

class MOBATAWIDGETSSHARED_EXPORT MscTestResult
    : public msc::KMscStatement
{
public:
  MscTestResult(const QString& statement,
                MscTestComponent const* mscTestComponent,
                QGraphicsItem* parentItem = 0);
  virtual ~MscTestResult();

public:
  virtual MscTestComponent const* mscComponent() const;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_MSCTESTRESULT_HPP
