#include "msctestresult.hpp"

#include <QPen>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

MscTestResult::MscTestResult(const QString& statement,
                             MscTestComponent const* mscTestComponent,
                             QGraphicsItem* parentItem)
  : msc::KMscStatement(statement, mscTestComponent, parentItem)
{
  this->setPen(QPen(Qt::darkRed, 3));
}

MscTestResult::~MscTestResult()
{}

MscTestComponent const* MscTestResult::mscComponent() const
{
  MscTestComponent const* mscTestComponent=utils::simple_cast<MscTestComponent const*>(msc::KMscStatement::mscComponent());
  Q_ASSERT(mscTestComponent);

  return mscTestComponent;
}

} // namespace ts
} // namespace view

