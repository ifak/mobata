#include "roundrectnode.hpp"

#include "../base/textitem.hpp"
#include "resizingrect.hpp"

#include <QPainter>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

RoundRectNode::RoundRectNode(const QString& notation, 
                             const NodeOptions &nodeOptions,
                             const QUuid &uuid,
                             QGraphicsItem *parent)
  : ResizingRectNode(notation, nodeOptions, uuid, parent)
{}

RoundRectNode::~RoundRectNode()
{}

int	RoundRectNode::type() const
{
  return Type;
}

void RoundRectNode::paint(QPainter *painter, 
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setBrush(this->brush());
  painter->setPen(this->pen());
  painter->drawRoundedRect(this->boundingRect(), 10, 10);

  if(this->isSelected() || this->getResizingRect()->isResizing())
    this->getResizingRect()->show();
  else
    this->getResizingRect()->hide();

  if(this->getProxyWidget())
    this->updateProxyWidgetGeometry();

  return;
}

}// end namespace graph
}//end namespace view
