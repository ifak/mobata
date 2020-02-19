/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef VIEW_BASE_FUNCTORS_HPP
#define VIEW_BASE_FUNCTORS_HPP

namespace view{
namespace base{

static inline  QPainterPath makeRectPath(const QPainterPath& origPath)
{
  if(origPath.elementCount() < 3)
    return origPath;

  QList<QPointF> pathPoints;
  QPointF p;

  for(int i = 0; i < origPath.elementCount(); i++){

    p = origPath.elementAt(i);
    pathPoints.append(p);
  }

  for(int i = 0; i < pathPoints.length(); i++){

    if( i == pathPoints.length()-1){                    // letztes element
      QLineF line(pathPoints.at(i), pathPoints.at(i-1));
      qreal angle = line.angle();

      if((angle <= 45 || angle >= 315) || (angle >= 135 && angle <= 225)){
        QPointF point(pathPoints.at(i-1).x(), pathPoints.at(i).y());

        if(pathPoints.at(i-1).x() == pathPoints.at(i-2).x()){
          pathPoints.replace(i-1, point);
        } else{
          pathPoints.insert(i, point);
        }
      } else if((angle > 45 && angle < 135) || (angle > 225 && angle < 315)){
        QPointF point(pathPoints.at(i).x(), pathPoints.at(i-1).y());
        if(pathPoints.at(i-1).y() == pathPoints.at(i-2).y()){
          pathPoints.replace(i-1, point);
        } else{
          pathPoints.insert(i, point);
        }
      }
      i = pathPoints.length()-1;
    } else if (i < pathPoints.length()-2){
      QLineF line(pathPoints.at(i), pathPoints.at(i+1));
      qreal angle = line.angle();

      if((angle <= 45 || angle >= 315) || (angle >= 135 && angle <= 225)){
        if((i != 0) && (pathPoints.at(i).y() == pathPoints.at(i-1).y())){

          QPointF newPoint(pathPoints.at(i).x(), pathPoints.at(i+1).y());
          pathPoints.insert(i+1, newPoint);
        } else{
          QPointF pointToReplace(pathPoints.at(i+1).x(), pathPoints.at(i).y());
          pathPoints.replace(i+1, pointToReplace);
        }
      } else if((angle > 45 && angle < 135) || (angle > 225 && angle < 315)){
        if((i != 0) && pathPoints.at(i).x() == pathPoints.at(i-1).x()){
          QPointF newPoint(pathPoints.at(i+1).x(), pathPoints.at(i).y());
          pathPoints.insert(i+1, newPoint);
        } else{
          QPointF pointToReplace(pathPoints.at(i).x(), pathPoints.at(i+1).y());
          pathPoints.replace(i+1, pointToReplace);
        }
      }
    }
  }

  QPainterPath newPath(pathPoints.at(0));

  for(int i = 1; i < pathPoints.length(); i++){
    newPath.lineTo(pathPoints.at(i));
  }

  return newPath;
}


static inline QPointF calcIntercectPoint(const QLineF& line, const QRectF& rect)
{
  QPointF intersectPoint=QPointF();

  QLineF rectLine(rect.bottomLeft(), rect.bottomRight());
  if(rectLine.intersect(line, &intersectPoint) == QLineF::BoundedIntersection)
    return intersectPoint;

  rectLine=QLineF(rect.bottomLeft(), rect.topLeft());
  if(rectLine.intersect(line, &intersectPoint) == QLineF::BoundedIntersection)
    return intersectPoint;

  rectLine=QLineF(rect.bottomRight(), rect.topRight());
  if(rectLine.intersect(line, &intersectPoint) == QLineF::BoundedIntersection)
    return intersectPoint;

  rectLine=QLineF(rect.topLeft(), rect.topRight());
  if(rectLine.intersect(line, &intersectPoint) == QLineF::BoundedIntersection)
    return intersectPoint;

  return QPointF();
}

}//end namespace base
}//end namespace view

#endif // VIEW_BASE_FUNCTORS_HPP

