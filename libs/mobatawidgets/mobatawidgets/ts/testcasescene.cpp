#include "testcasescene.hpp"

#include "mscsutcomponent.hpp"
#include "msctestcomponent.hpp"
#include "msctestresult.hpp"

#include "../msc/mscsequence.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

TestCaseScene::TestCaseScene(QObject* parent)
  : msc::KMscScene(parent)
{}

TestCaseScene::~TestCaseScene()
{}

MscSutComponent* TestCaseScene::addSutComponent(const QString& name,
                                                const QUuid& referenceId,
                                                const graph::NodeOptions &compOptions,
                                                const QColor &lifeLineColor,
                                                const qreal lifeLineWidth)
{
  msc::KMscComponent* mscComponent=this->mscComponent(referenceId);
  MscSutComponent* mscSutComponent=dynamic_cast<MscSutComponent*>(mscComponent);
  if(!mscSutComponent)
  {
    if(mscComponent)
      return 0;///already a component with this id, but not a msc-sut-component

    mscSutComponent = new MscSutComponent(name, referenceId, compOptions, lifeLineColor, lifeLineWidth);
    this->addMscComponent(mscSutComponent);
  }

  return mscSutComponent;
}

MscTestComponent* TestCaseScene::addTestComponent(const QString& name,
                                                  const QUuid& referenceId,
                                                  const view::graph::NodeOptions& compOptions,
                                                  const QColor& lifeLineColor,
                                                  const qreal lifeLineWidth)
{
  msc::KMscComponent* mscComponent=this->mscComponent(referenceId);
  MscTestComponent* mscTestComponent=dynamic_cast<MscTestComponent*>(mscComponent);
  if(!mscTestComponent)
  {
    if(mscComponent)
      return 0;///already a component with this id, but not a msc-test-component

    mscTestComponent = new MscTestComponent(name, referenceId, compOptions, lifeLineColor, lifeLineWidth);
    this->addMscComponent(mscTestComponent);
  }

  return mscTestComponent;
}

QList<MscSutComponent*> TestCaseScene::sutComponents() const
{
  QList<MscSutComponent*> mscSutComponents;

  foreach(msc::KMscComponent* mscComponent,
          this->mscComponents())
  {
    MscSutComponent* mscSutComponent=dynamic_cast<MscSutComponent*>(mscComponent);
    if(mscSutComponent)
      mscSutComponents.append(mscSutComponent);
  }

  return mscSutComponents;
}
MscSutComponent* TestCaseScene::sutComponent(const QUuid& referenceId)
{
  return dynamic_cast<MscSutComponent*>(this->mscComponent(referenceId));
}

QList<MscTestComponent*> TestCaseScene::testComponents() const
{
  QList<MscTestComponent*> mscTestComponents;

  foreach(msc::KMscComponent* mscComponent,
          this->mscComponents())
  {
    MscTestComponent* mscTestComponent=dynamic_cast<MscTestComponent*>(mscComponent);
    if(mscTestComponent)
      mscTestComponents.append(mscTestComponent);
  }

  return mscTestComponents;
}

MscTestComponent* TestCaseScene::testComponent(const QUuid& referenceId)
{
  return dynamic_cast<MscTestComponent*>(this->mscComponent(referenceId));
}

MscTestResult* TestCaseScene::addTestResultStep(const model::ts::TestResultValue testResultValue,
                                                MscTestComponent* mscTestcomponent,
                                                msc::KMscSequence* parentSequence,
                                                QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  msc::KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->rootSequence();
  Q_ASSERT(messageParent);

  QString testResultStatement=QStringLiteral("this.testResult=")
                              +testResult2String(testResultValue);
  MscTestResult* newMscTestResult=new MscTestResult(testResultStatement,
                                                    mscTestcomponent,
                                                    messageParent);
  messageParent->addStatementStep(newMscTestResult);

  return newMscTestResult;
}

} // namespace ts
} // namespace view

