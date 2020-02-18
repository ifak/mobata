#include "intersectionitem.hpp"
#include "edgeitem.hpp"
#include "trafficdistributionitem.hpp"
#include "Util/errortracker.hpp"

namespace trafficsim {

IntersectionItem::IntersectionItem(const QString &name, qreal accident, bool hasTrafficLight)
    : ModelItem(name),
      _edgeParent(0),
      _accident(accident),
      _hasTrafficLight(hasTrafficLight)
{
    this->appendRow(new ModelItem("accident: " + QString::number(accident)));

    if (hasTrafficLight)
    {
        this->appendRow(new ModelItem("trafficLight: true"));
    }
    else
    {
        this->appendRow(new ModelItem("trafficLight: false"));
    }
}

IntersectionItem::~IntersectionItem()
{
   if (_edgeParent)
   {
       for (int i = 0; i < _edges.count(); i++)
       {
           _edgeParent->takeRow(_edges.at(i)->row());
       }
       qDeleteAll(_edges);

       _edgeParent->removeRows(0, _edgeParent->rowCount());

       this->takeRow(_edgeParent->row());
       delete _edgeParent;
   }
   this->removeRows(0, this->rowCount());
}

QList<QString> IntersectionItem::edgeNames() const
{
    return _edgeNames;
}

void IntersectionItem::setEdgeNames(const QList<QString> &edgeNames)
{
    _edgeNames = edgeNames;
}

void IntersectionItem::addEdgeName(const QString &name)
{
    _edgeNames.append(name);
}

EdgeItem *IntersectionItem::addEdge(const QString &name,
                                    QList<QQmlError> &errorList,
                                    const QString &fileName)
{
    // check if the intersection has the global child containing all edges if not create it
    if (0x00 == _edgeParent)
    {
        _edgeParent = new ModelItem("Edges");
        this->appendRow(_edgeParent);
    }

    // check if the name of an edge is already present
    if(_edgeNames.contains(name))
    {
        QString errorString(QString::fromLatin1("An arm with the name "));
        errorString.append(name)
                   .append(QString::fromLatin1(" was already defined earlier"));
        addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
        return 0x00;
    }

    EdgeItem *newChild = new EdgeItem(name);
    _edgeParent->appendRow(newChild);
    addEdgeName(name);
    _edges.append(newChild);

    return newChild;
}

const QList<EdgeItem*> &IntersectionItem::edges() const
{
    return _edges;
}

qreal IntersectionItem::accident() const
{
    return _accident;
}

bool IntersectionItem::hasTrafficLight() const
{
    return _hasTrafficLight;
}

const QList<TrafficLightItem* > &IntersectionItem::trafficLights() const
{
    return _trafficLights;
}

void IntersectionItem::addTrafficLight(TrafficLightItem* newTrafficLight)
{
    _trafficLights.append(newTrafficLight);
}

const QList<SensorItem* >& IntersectionItem::sensors() const{
    return _sensors;
}
void IntersectionItem::addSensor(SensorItem* sensor){
    _sensors.append(sensor);
}
}///end namespace trafficsim
