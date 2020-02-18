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
#ifndef MODEL_TS_IO_READXMLTESTSUITE_HPP
#define MODEL_TS_IO_READXMLTESTSUITE_HPP

#include <QXmlStreamReader>
#include <QString>

#include "../../msc/io/readxmlmscmodel.hpp"

namespace model{
namespace ts{
namespace io{

template<class SystemModel, class TestCaseType>
bool readXmlTestCase(QXmlStreamReader* xmlStreamReader,
                     SystemModel* systemModel,
                     TestCaseType* testCaseItem,
                     QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(testCaseItem);

  return msc::io::readXmlSequence(xmlStreamReader,
                                  systemModel,
                                  testCaseItem,
                                  errorMessage);
}

} /// namespace io
} /// namespace ts
} /// namespace model

#endif // MODEL_TS_IO_READXMLTESTSUITE_HPP
