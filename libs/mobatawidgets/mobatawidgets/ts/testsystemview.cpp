#include "testsystemview.hpp"

#include "testsystemscene.hpp"

#include <mobata/utils/functors.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

TestSystemView::TestSystemView(QWidget* parent)
  : graph::GraphView(parent)
{}

TestSystemView::TestSystemView(TestSystemScene* testSystemScene,
                               QWidget *parent)
  : graph::GraphView(testSystemScene, parent)
{}

TestSystemView::~TestSystemView()
{}

TestSystemScene* TestSystemView::testSystemScene()
{
  return utils::simple_cast<TestSystemScene*>(this->scene());
}

} // namespace ts
} // namespace view
