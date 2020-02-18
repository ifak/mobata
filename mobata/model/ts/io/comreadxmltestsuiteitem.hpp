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

#include "../../../mobata_global.hpp"

#include <QObject>

namespace model {
namespace ts {
class TestSuiteItem;
namespace io {

class MOBATASHARED_EXPORT ComReadXmlTestSuiteItem
    : public QObject
{
  Q_OBJECT
public:
  explicit ComReadXmlTestSuiteItem(const QString& testSuiteFileName,
                                   model::ts::TestSuiteItem* testSuiteItem,
                                   QObject *parent = nullptr);
  virtual ~ComReadXmlTestSuiteItem();

public:
  bool execute(QString* errorMessage);

private:
  Q_DISABLE_COPY(ComReadXmlTestSuiteItem)
  class Private;
  Private* _d;
};

} // namespace io
} // namespace ts
} // namespace model
