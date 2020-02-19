#include "testcaseitem.hpp"
#include "testsystemitem.hpp"
#include "sutitem.hpp"

#include "testgroupitem.hpp"
#include "testsuite.hpp"
#include "model/base/attributeitem.hpp"

#include "../msc/mscstepitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace ts{

class TestCaseItem::Private
{
  friend class TestCaseItem;
};

TestCaseItem::TestCaseItem(const QString& name)
  : msc::MscSequence(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    _d(new Private())
{
  this->setText(this->toString());
}

TestCaseItem::~TestCaseItem()
{
  delete this->_d;
}

void TestCaseItem::reset()
{
  this->resetAttributes();
  this->resetSignals();

  msc::MscSequence::reset();

  return;
}

TestCaseItem* TestCaseItem::clone() const
{
  TestCaseItem* cloneTestCaseItem = new TestCaseItem();

  this->cloneDataTypes(cloneTestCaseItem);
  this->cloneAttributes(cloneTestCaseItem);
  this->cloneSignals(cloneTestCaseItem);
//  this->cloneMscSequence(cloneTestCaseItem);

  return cloneTestCaseItem;
}

TestSuite const* TestCaseItem::testSuite() const
{
  return utils::simple_cast<TestSuite const*>(this->model());
}

QList<msc::MscCoverageItem> TestCaseItem::coverageItems() const
{
  QList<msc::MscCoverageItem> coverageItems;

  for(msc::MscSequenceItem const* sequenceItem
      : this->sequenceItems())
  {
    if(msc::MscStepItem const* stepItem=dynamic_cast<msc::MscStepItem const*>(sequenceItem))
    {
      for(const msc::MscCoverageItem& stepCoverageItem : stepItem->coverageItems())
        coverageItems.append(stepCoverageItem);
    }
  }

  return coverageItems;
}

int TestCaseItem::calcTestStepsCount() const
{
  int testStepsCount=0;

  for(msc::MscSequenceItem const* sequenceItem
      : this->sequenceItems())
  {
    int stepType = sequenceItem->stepType();

    if(stepType==msc::MessageStep
       || stepType==msc::CheckMessageStep
       || stepType==msc::TimeoutStep)
      ++testStepsCount;
  }

  return testStepsCount;
}

void TestCaseItem::addContent(base::BaseModel *model,QString* errorString)
{
  QString err("");
  for (auto type : model->dataTypes())
  {
    if(type->name() == QString("int") || type->name() == QString("real") || type->name() == QString("bool") || type->name() == QString("string"))
      continue;
    base::DataTypeItem* item = new base::DataTypeItem(type->name(),type->uuid());
    for (auto literals : type->literals())
      item->addLiteral(literals);
    this->addDataType(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }

  for (base::AttributeItem* attr : model->attributes())
  {
    auto newAttr = new base::AttributeItem(attr->name(),
                                           attr->dataType(),
                                           attr->initValue(),
                                           attr->uuid());
    this->addAttribute(newAttr,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for (auto signal : model->getSignals())
  {
    base::SignalItem* item = new base::SignalItem(signal->name(),signal->uuid());
    for(auto param : signal->params())
    {
      base::ParamItem* pItem = new base::ParamItem(param->name(),
                                                   param->dataType(),
                                                   param->uuid());
      item->addParameter(pItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    this->addSignal(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
}

}/// end namespace ts
}/// end namespace model
