#include "comrendertestcase.hpp"

#include "testcasescene.hpp"
#include "msctestresult.hpp"

#include <mobata/model/ts/ts.hpp>

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

class ComRenderTestCase::Private
{
  friend class ComRenderTestCase;

  view::graph::NodeOptions _sutCompOptions;
  QColor                   _sutLifeLineColor;
  qreal                    _sutLifeLineWidth;
  view::graph::NodeOptions _testCompOptions;
  QColor                   _testLifeLineColor;
  qreal                    _testLifeLineWidth;
  qreal                    _realCompBoxWidth;
  qreal                    _realCompBoxHeight;

  Private(const view::graph::NodeOptions& sutCompOptions,
          const QColor& sutLifeLineColor,
          const qreal sutLifeLineWidth,
          const view::graph::NodeOptions& testCompOptions,
          const QColor& testLifeLineColor,
          const qreal testLifeLineWidth)
    : _sutCompOptions(sutCompOptions),
      _sutLifeLineColor(sutLifeLineColor),
      _sutLifeLineWidth(sutLifeLineWidth),
      _testCompOptions(testCompOptions),
      _testLifeLineColor(testLifeLineColor),
      _testLifeLineWidth(testLifeLineWidth),
      _realCompBoxWidth(20),
      _realCompBoxHeight(20)
  {}
};

ComRenderTestCase::ComRenderTestCase(TestCaseScene* testCaseScene,
                                     model::ts::TestCaseItem const* modelTestCase,
                                     const view::graph::NodeOptions& sutCompOptions,
                                     const QColor& sutLifeLineColor,
                                     const qreal sutLifeLineWidth,
                                     const view::graph::NodeOptions& testCompOptions,
                                     const QColor& testLifeLineColor,
                                     const qreal testLifeLineWidth,
                                     const graph::ArcOptions arcOptions)
  : msc::ComRenderMscSequence(testCaseScene, modelTestCase, arcOptions),
    _d(new Private(sutCompOptions, sutLifeLineColor, sutLifeLineWidth, testCompOptions, testLifeLineColor, testLifeLineWidth))
{
  foreach (const model::msc::MscComponentItem *componentItem,
           modelTestCase->componentItems())
  {
    QGraphicsTextItem compNameItem(componentItem->name());
    if (model::ts::SutComponentType == componentItem->compType())
      compNameItem.setFont(sutCompOptions.textFont());
    else if (model::ts::TestComponentType == componentItem->compType())
      compNameItem.setFont(testCompOptions.textFont());
    else
      continue;

    QRectF compNameItemRect(compNameItem.boundingRect());
    qreal compBoxWidth = compNameItemRect.width() + 20;
    if (this->_d->_realCompBoxWidth < compBoxWidth)
      this->_d->_realCompBoxWidth = compBoxWidth;
    qreal compBoxHeight = compNameItemRect.height() + 20;
    if (this->_d->_realCompBoxHeight < compBoxHeight)
      this->_d->_realCompBoxWidth = compBoxWidth;
  }

  if (this->_d->_realCompBoxWidth < sutCompOptions.size().width())
    this->_d->_realCompBoxWidth = sutCompOptions.size().width();
  if (this->_d->_realCompBoxWidth < testCompOptions.size().width())
    this->_d->_realCompBoxWidth = testCompOptions.size().width();
  if (this->_d->_realCompBoxHeight < sutCompOptions.size().height())
    this->_d->_realCompBoxHeight = sutCompOptions.size().height();
  if (this->_d->_realCompBoxHeight < testCompOptions.size().height())
    this->_d->_realCompBoxHeight = testCompOptions.size().height();
}

ComRenderTestCase::~ComRenderTestCase()
{}

TestCaseScene* ComRenderTestCase::viewScene()
{
  return utils::simple_cast<TestCaseScene*>(ComRenderMscSequence::viewScene());
}

model::ts::TestCaseItem const* ComRenderTestCase::modelSequence() const
{
  return utils::simple_cast<model::ts::TestCaseItem const*>(ComRenderMscSequence::modelSequence());
}

bool ComRenderTestCase::execute(QString* errorMessage)
{
  bool result=ComRenderMscSequence::execute(errorMessage);

  // add attribute declaration box
  // add signal declaration box

  return result;
}

bool ComRenderTestCase::addComponents(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  TestCaseScene* testCaseScene=this->viewScene();
  Q_ASSERT(testCaseScene);

  model::ts::TestCaseItem const* testCaseItem=this->modelSequence();
  Q_ASSERT(testCaseItem);

  view::graph::NodeOptions realSutCompOptions(this->_d->_sutCompOptions);
  realSutCompOptions.setSize(this->_d->_realCompBoxWidth, this->_d->_realCompBoxHeight);
  view::graph::NodeOptions realTestCompOptions(this->_d->_testCompOptions);
  realTestCompOptions.setSize(this->_d->_realCompBoxWidth, this->_d->_realCompBoxHeight);

  for(model::msc::MscComponentItem const* componentItem :
      testCaseItem->componentItems())
  {
    if(componentItem->compType()==model::ts::SutComponentType)
      testCaseScene->addSutComponent(componentItem->name(),
                                     componentItem->uuid(),
                                     realSutCompOptions,
                                     this->_d->_sutLifeLineColor,
                                     this->_d->_sutLifeLineWidth);
    else if(componentItem->compType()==model::ts::TestComponentType)
      testCaseScene->addTestComponent(componentItem->name(),
                                      componentItem->uuid(),
                                      realTestCompOptions,
                                      this->_d->_testLifeLineColor,
                                      this->_d->_testLifeLineWidth);
    else
      Q_ASSERT(false);
  }

  return true;
}

bool ComRenderTestCase::dispatchSequenceItem(model::msc::MscSequenceItem const* sequItem,
                                             msc::KMscSequence* sequence,
                                             QString* errorMessage)
{
  Q_ASSERT(sequItem);

  bool result = true;
  if (sequItem->stepType() == model::ts::TestResultStep)
  {
    result = this->addTestResultItem(utils::simple_cast<model::ts::TestResultItem const*>(sequItem),
                                     sequence, errorMessage);
    if (!result)
      return false;
  }
  else
  {
    result=ComRenderMscSequence::dispatchSequenceItem(sequItem,
                                                      sequence,
                                                      errorMessage);
    if(!result)
      return false;
  }

  return true;
}

bool ComRenderTestCase::addTestResultItem(model::ts::TestResultItem const* testResultItem,
                                          msc::KMscSequence* sequence,
                                          QString* errorMessage)
{
  Q_ASSERT(testResultItem);
  Q_ASSERT(this->viewScene());

  model::msc::MscComponentItem const* component=testResultItem->component();
  if(!component)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("component of test-result '%1' "
                                 "not found!").arg(testResultItem->toString());
    return false;
  }

  MscTestComponent* viewTestComponent=this->viewScene()->testComponent(component->uuid());
  if(!viewTestComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("view test-component of test-result '%1' "
                                 "not found!").arg(testResultItem->toString());
    return false;
  }

  MscTestResult* testResult=this->viewScene()->addTestResultStep(testResultItem->value(),
                                                                 viewTestComponent,
                                                                 sequence,
                                                                 errorMessage);
  if(!testResult)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("test-result '%1' "
                                 "could not be created!").arg(testResultItem->toString());
    return false;
  }

  testResult->setReferenceId(testResultItem->uuid());

  return true;
}

} // namespace ts
} // namespace view

