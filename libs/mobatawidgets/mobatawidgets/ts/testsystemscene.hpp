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
#ifndef VIEW_TS_TESTSYSTEMSCENE_HPP
#define VIEW_TS_TESTSYSTEMSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "sutscene.hpp"

#include "types.hpp"

namespace view {
namespace ts {

typedef QGraphicsPathItem TestSystemBox;

class MOBATAWIDGETSSHARED_EXPORT TestSystemScene
    : public SutScene
{
  Q_OBJECT

  friend class ComRenderTestSystem;

public:
  typedef QVector<TestComponent*> TestComponents;
  typedef QVector<Link*>          TestSystemLinks;
  typedef QVector<Link*>          TestLinks;

public:
  explicit TestSystemScene(QObject *parent = 0);
  virtual ~TestSystemScene();

public:
  virtual void reset();

public:
  void  addTestComponent(TestComponent* newTestComponent);
  void  addTestSystemLink(Link* link);
  void  addTestLink(Link* link);

  const TestComponents&   testComponents() const;
  const TestSystemLinks&  testSystemLinks() const;
  const TestLinks&        testLinks() const;

  TestSystemBox const*    testSystemBox() const;
  base::TextItem const*   testSystemNotationItem() const;

  const QString&          testSystemNotation() const;
  void                    setTestSystemNotation(const QString& testSystemNotation);

public:
  virtual view::ts::Port* port(const QUuid& portUuid) const;

private:
  TestSystemBox*  testSystemBox();

private:
  Q_DISABLE_COPY(TestSystemScene)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_TESTSYSTEMSCENE_HPP
