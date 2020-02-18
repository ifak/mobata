#include "testcaseview.hpp"

#include "testcasescene.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace ts{

TestCaseView::TestCaseView(QWidget* parent)
  : msc::KMscView(parent)
{}

TestCaseView::TestCaseView(TestCaseScene* testCaseScene,
                           QWidget* parent)
  : msc::KMscView(testCaseScene, parent)
{
  Q_ASSERT(testCaseScene);
  Q_ASSERT(this->scene());
}

TestCaseView::~TestCaseView()
{}

TestCaseScene* TestCaseView::testCaseScene()
{
  return utils::simple_cast<TestCaseScene*>(this->scene());
}

} // namespace ts
} // namespace view

