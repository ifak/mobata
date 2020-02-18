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
#ifndef VIEW_TS_COMCREATETESTCASEPIX_HPP
#define VIEW_TS_COMCREATETESTCASEPIX_HPP

#include "../mobatawidgets_global.hpp"

#include "../msc/comcreatemscpix.hpp"

namespace model{ namespace ts{
class TestCaseItem;
}}

namespace view
{
namespace ts
{

/*!
 * \brief The ComCreateTestCasePix class command creates a png-pic of a testcase-item
*/
class MOBATAWIDGETSSHARED_EXPORT ComCreateTestCasePix
    : public msc::ComCreateMscPix
{
  Q_OBJECT

public:
  /*!
   * \brief ComCreatePrefixPic constructor of the command class
   * \param testCase	test-case-item
   */
  ComCreateTestCasePix(model::ts::TestCaseItem const* testCase,
                       QObject* parent=0);
  virtual ~ComCreateTestCasePix();

public:
  virtual void execute(QNetworkAccessManager* networkManager);

public:
  model::ts::TestCaseItem const* testCase() const;
};

} // end namespace ts
} // end namespace view

#endif // VIEW_TS_COMCREATETESTCASEPIX_HPP
