#include "sutview.hpp"

#include "sutscene.hpp"

#include <mobata/utils/functors.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

SutView::SutView(QWidget* parent)
  : graph::GraphView(parent)
{}

SutView::SutView(SutScene* sutScene,
                 QWidget *parent)
  : graph::GraphView(sutScene, parent)
{}

SutView::~SutView()
{}

SutScene* SutView::sutScene()
{
  return utils::simple_cast<SutScene*>(this->scene());
}

} // namespace ts
} // namespace view
