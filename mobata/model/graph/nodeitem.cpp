#include "nodeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace graph{

NodeItem::NodeItem(const QUuid &uuid)
	:	ModelItem(uuid)
{}

NodeItem::~NodeItem()
{}

}///end namespace graph
}///end namespace model
