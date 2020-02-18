#include "mscview.hpp"

#include "mscscene.hpp"

#include <mobata/utils/functors.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

KMscView::KMscView(QWidget* parent)
  : graph::GraphView(parent)
{}

KMscView::KMscView(KMscScene* mscScene,
                   QWidget* parent)
  : graph::GraphView(mscScene, parent)
{
  Q_ASSERT(mscScene);
  Q_ASSERT(this->scene());
}

KMscView::~KMscView()
{}

KMscScene* KMscView::mscScene()
{
  return utils::simple_cast<KMscScene*>(this->scene());
}

}//end namespace msc
}//end namespace view
