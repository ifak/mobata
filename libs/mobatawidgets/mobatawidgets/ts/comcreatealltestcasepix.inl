#include <mobata/model/ts/testsuite.hpp>
#include <mobata/model/ts/testgroupitem.hpp>
#include <mobata/model/ts/testcaseitem.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view
{
namespace ts
{

template<class CreateTcCommand>
void ComCreateAllTestCasePix::execute()
{
  model::ts::TestSuite const* testSuite=this->testSuite();
  if(!testSuite)
    return;

  int count=0;
  this->reset();
  foreach(model::ts::TestGroupItem const* testGroup,
          testSuite->testGroups())
  {
    foreach(model::ts::TestCaseItem const* testCaseItem,
            testGroup->testCases())
    {
      CreateTcCommand* createTcPixCommand=new CreateTcCommand(testCaseItem,
                                                              this);
      connect(createTcPixCommand, SIGNAL(result(const TsTestCaseItem*,QPixmap)),
              this, SLOT(testCasePixSlot(const TsTestCaseItem*,const QPixmap&)));
      this->addTcPixCommand(testCaseItem, createTcPixCommand);
      createTcPixCommand->execute(this->networkManager());

      ++count;
    }
  }

  if(!count)
    QTimer::singleShot(10,this,&ComCreateAllTestCasePix::finished);

  return;
}

} // end namespace ts
} // end namespace view

#include <mobata/memory_leak_start.hpp>
