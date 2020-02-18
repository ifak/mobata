#include "linkport.hpp"

#include "link.hpp"

#include <QtMath>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace comp {

LinkPort::LinkPort(Link* link,
                   const QString& notation,
                   const NodeOptions& portOptions,
                   const QUuid& uuid)
  : Port(link, notation, portOptions, uuid)
{}

LinkPort::~LinkPort()
{}

QPointF LinkPort::calcPosition(QPointF possPosition)
{
  Link* link=dynamic_cast<Link*>(this->parentItem());
  Q_ASSERT(link);

  typedef std::pair<QPointF, QPointF> Line;
  QVector<Line> lines;

  QPainterPath linkPath=link->path();
  int elemCount=linkPath.elementCount();
  if(elemCount<2)
    return QPointF();

  QPointF formerPoint, nextPoint;
  int pos=0;
  for(int i=0; i<elemCount; ++i, ++pos)
  {
    if(pos==0)
    {
      formerPoint=QPointF(linkPath.elementAt(0));
      continue;
    }
    else
    {
      nextPoint=linkPath.elementAt(pos);
      lines.append(std::make_pair(formerPoint,
                                  nextPoint));
      formerPoint=nextPoint;
    }
  }

  QPointF localPossPoint=possPosition;
  qreal x0=localPossPoint.x();
  qreal y0=localPossPoint.y();

  ///@see http://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
  qreal currDistance=0;
  Line const* shortestLine=&lines.at(0);
  QPointF linePoint(x0,y0);
  pos=0;
  for(int i=0; i<lines.size(); ++i, ++pos)
  {
    const Line& currLine=lines.at(pos);

    qreal x1=currLine.first.x();
    qreal y1=currLine.first.y();
    qreal x2=currLine.second.x();
    qreal y2=currLine.second.y();

    qreal linePointX, linePointY;
    qreal m   = (y2-y1)/(x2-x1);
    if(qIsInf(m))
    {
      linePointX=x1;
      linePointY=y0;
    }
    else if(qFloatDistance(m, 0.0) < (1 << 7)) // m == 0
    {
      linePointX=x0;
      linePointY=y1;
    }
    else
    {
      qreal b   = y1 - m*x1;
      qreal b0  = y0 + x0/m;
      linePointX = (b0-b)/(m+1/m);
      linePointY = m*linePointX + b;
    }

    //restrictions
    if(linePointX<x1)
      linePointX=x1;
    if(linePointX>x2)
      linePointX=x2;

    if(linePointY<y1)
      linePointY=y1;
    if(linePointY>y2)
      linePointY=y2;

    qreal distance = qSqrt(qPow(linePointY-y0,2) + qPow(linePointX - x0, 2));

    if(pos==0)
    {
      currDistance=distance;
      linePoint.setX(linePointX);
      linePoint.setY(linePointY);
    }
    else
    {
      if(distance < currDistance)
      {
        currDistance = distance;
        linePoint.setX(linePointX);
        linePoint.setY(linePointY);
        shortestLine=&currLine;
      }
    }
  }
  Q_ASSERT(shortestLine);

  return linePoint;
}

} // namespace comp
} // namespace view

