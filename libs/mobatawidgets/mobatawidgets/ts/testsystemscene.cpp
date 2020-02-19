#include "testsystemscene.hpp"

#include "../base/functors.hpp"

#include "../comp/link.hpp"
#include "../comp/linkport.hpp"

#include "testcomponent.hpp"

#include <QGraphicsPathItem>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

class TestSystemScene::Private
{
  friend class TestSystemScene;

  TestSystemBox*  _testSystemBox;
  base::TextItem* _notationItem;
  QString         _notation;
  TestComponents  _testComponents;
  TestSystemLinks _testSystemLinks;
  TestLinks       _testLinks;

  Private()
    : _testSystemBox(0),
      _notationItem(0),
      _notation(QStringLiteral(""))
  {}
  ~Private()
  {}

  void createTestSystemBox();
  void createNotationItem();
};


void TestSystemScene::Private::createTestSystemBox()
{
  this->_testSystemBox=new TestSystemBox;
  this->_testSystemBox->hide();

  return;
}

void TestSystemScene::Private::createNotationItem()
{
  Q_ASSERT(this->_testSystemBox);

  QString itemNotation=QStringLiteral("test system");
  if(!this->_notation.isEmpty())
    itemNotation+=QLatin1String(": ")+this->_notation;

  this->_notationItem=new base::TextItem(itemNotation,
                                         this->_testSystemBox);
  this->_notationItem->hide();

  return;
}

///TestSystemScene///////////////
TestSystemScene::TestSystemScene(QObject *parent)
  : SutScene(parent),
    _d(new Private)
{
  this->_d->createTestSystemBox();
  Q_ASSERT(this->_d->_testSystemBox);
  this->addItem(this->_d->_testSystemBox);

  this->_d->createNotationItem();
}

TestSystemScene::~TestSystemScene()
{
  delete this->_d;
}

void TestSystemScene::reset()
{
  SutScene::reset();

  this->_d->_testComponents.clear();
  this->_d->_testSystemLinks.clear();
  this->_d->_testLinks.clear();

  this->_d->createTestSystemBox();
  this->addItem(this->_d->_testSystemBox);

  this->_d->createNotationItem();

  return;
}

void TestSystemScene::addTestComponent(TestComponent* newTestComponent)
{
  if(!newTestComponent)
    return;

  newTestComponent->setParentItem(this->_d->_testSystemBox);
  newTestComponent->setPos(this->_d->_testSystemBox->mapFromScene(newTestComponent->pos()));
  this->_d->_testComponents.append(newTestComponent);

  return;
}

void TestSystemScene::addTestSystemLink(Link* link)
{
  if(!link)
    return;

  link->setParentItem(this->_d->_testSystemBox);

  QPainterPath newPath = view::base::makeRectPath(link->path());
  link->updatePath(newPath);

  this->_d->_testSystemLinks.append(link);

  return;
}

void TestSystemScene::addTestLink(Link* link)
{
  if(!link)
    return;

  QPainterPath newPath = view::base::makeRectPath(link->path());
  link->updatePath(newPath);

  this->_d->_testLinks.append(link);

  return;
}

const TestSystemScene::TestComponents& TestSystemScene::testComponents() const
{
  return this->_d->_testComponents;
}

const TestSystemScene::TestSystemLinks& TestSystemScene::testSystemLinks() const
{
  return this->_d->_testSystemLinks;
}

const TestSystemScene::TestLinks& TestSystemScene::testLinks() const
{
  return this->_d->_testLinks;
}

TestSystemBox const* TestSystemScene::testSystemBox() const
{
  return this->_d->_testSystemBox;
}

base::TextItem const* TestSystemScene::testSystemNotationItem() const
{
  return this->_d->_notationItem;
}

const QString&TestSystemScene::testSystemNotation() const
{
  return this->_d->_notation;
}

void TestSystemScene::setTestSystemNotation(const QString &testSystemNotation)
{
  Q_ASSERT(this->_d->_notationItem);

  this->_d->_notation=testSystemNotation;

  QString itemNotation=QStringLiteral("test system");
  if(!this->_d->_notation.isEmpty())
    itemNotation+=QLatin1String(": ")+this->_d->_notation;

  this->_d->_notationItem->setPlainText(itemNotation);

  return;
}

Port* TestSystemScene::port(const QUuid& portUuid) const
{
  if(Port* port=SutScene::port(portUuid))
    return port;

  foreach(Component* component,
          this->_d->_testComponents)
  {
    if(Port* port=component->port(portUuid))
      return port;
  }

  foreach(Link* link,
          this->_d->_testSystemLinks)
  {
    if(link->linkPort()
       && link->linkPort()->uuid() == portUuid)
      return link->linkPort();
  }

  foreach(Link* link,
          this->_d->_testLinks)
  {
    if(link->linkPort()
       && link->linkPort()->uuid() == portUuid)
      return link->linkPort();
  }

  return 0;
}

TestSystemBox* TestSystemScene::testSystemBox()
{
  return this->_d->_testSystemBox;
}

} // namespace ts
} // namespace view
