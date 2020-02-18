#include "declarc.hpp"

#include "../base/textitem.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

DeclArc::DeclArc(graph::AbstractNode* from, graph::AbstractNode* to, 
                 const QString& arcDecl, QUuid uuid,
                 const ArcOptions& arcOptions)
  : graph::DirectedEdge(from, to, arcDecl, uuid, arcOptions)
{
  this->notationItem()->setFlags(QGraphicsItem::ItemIsMovable
                                 | QGraphicsItem::ItemIsSelectable
                                 | QGraphicsItem::ItemIsFocusable);
}

DeclArc::~DeclArc()
{}

int DeclArc::type() const
{
  return Type;
}

}///end namespace spenat
}///end namespace view
