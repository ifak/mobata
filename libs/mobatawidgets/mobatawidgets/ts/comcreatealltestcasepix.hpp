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
#ifndef VIEW_TS_COMCREATEALLTESTCASEPIX_HPP
#define VIEW_TS_COMCREATEALLTESTCASEPIX_HPP

#include "../mobatawidgets_global.hpp"

#include <QObject>
#include <QPixmap>
#include <QTimer>

class QNetworkAccessManager;

namespace model{ namespace ts{
class TestSuite;
class TestCaseItem;
}}

namespace view
{
namespace ts
{
class ComCreateTestCasePix;

class MOBATAWIDGETSSHARED_EXPORT ComCreateAllTestCasePix
    : public QObject
{
  Q_OBJECT
public:
  explicit ComCreateAllTestCasePix(model::ts::TestSuite const* testSuite,
                                   QNetworkAccessManager* networkManager,
                                   QObject *parent = 0);
  virtual ~ComCreateAllTestCasePix();

public:
  const QPixmap& testCasePix(model::ts::TestCaseItem const* testCase);

signals:
  void finished();
  void progress(int currProgress);

public:
  template<class CreateTcCommand>
  void execute();

private slots:
  void testCasePixSlot(model::ts::TestCaseItem const* testCase,
                       const QPixmap& testCasePix);

private:
  void                        reset();
  model::ts::TestSuite const* testSuite();
  QNetworkAccessManager*      networkManager();
  void                        addTcPixCommand(model::ts::TestCaseItem const* testCaseItem,
                                              ComCreateTestCasePix* tcPixCommand);

private:
  class Private;
  Private* _d;
};

} // end namespace ts
} // end namespace view

#include "comcreatealltestcasepix.inl"

#endif // VIEW_TS_COMCREATEALLTESTCASEPIX_HPP
