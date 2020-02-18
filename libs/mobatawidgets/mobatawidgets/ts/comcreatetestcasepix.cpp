#include "comcreatetestcasepix.hpp"

#include <mobata/model/ts/testcaseitem.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view
{
namespace ts
{

ComCreateTestCasePix::ComCreateTestCasePix(model::ts::TestCaseItem const* testCase,
                                           QObject *parent)
  :	msc::ComCreateMscPix (testCase, parent)
{}

ComCreateTestCasePix::~ComCreateTestCasePix()
{}

void ComCreateTestCasePix::execute(QNetworkAccessManager* networkManager)
{
  return msc::ComCreateMscPix::execute(networkManager);
}

model::ts::TestCaseItem const* ComCreateTestCasePix::testCase() const
{
  return utils::simple_cast<model::ts::TestCaseItem const*>(this->mscSequence());
}

} // end namespace ts
} // end namespace view
