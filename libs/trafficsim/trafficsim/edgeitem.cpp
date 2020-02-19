#include "edgeitem.hpp"
#include "laneitem.hpp"
#include "Util/errortracker.hpp"

namespace trafficsim {

EdgeItem::EdgeItem(const QString &name)
    : model::base::ModelItem(QUuid(name)),
      _lanesParent(nullptr)
{
    // Do nothing
}

EdgeItem::~EdgeItem()
{
    if (_lanesParent)
    {
        for (int i = 0; i < _inboundLanes.count(); i++)
        {
            _lanesParent->takeRow(_inboundLanes.at(i)->row());
        }
        qDeleteAll(_inboundLanes);

        for (int i = 0; i < _outboundLanes.count(); i++)
        {
            _lanesParent->takeRow(_outboundLanes.at(i)->row());
        }
        qDeleteAll(_outboundLanes);

        _lanesParent->removeRows(0, _lanesParent->rowCount());

        this->takeRow(_lanesParent->row());
        delete _lanesParent;
    }
}

bool EdgeItem::addLane(const QString &name,
                       const QString &type,
                       QList<QQmlError> &errorList,
                       const QString &fileName)
{
    // check if the parent to all lanes called "lanes" is already created if not create it
    // and set it as a child to the current edge item
    if (0x00 == _lanesParent)
    {
        _lanesParent = new ModelItem("lanes");
        this->appendRow(_lanesParent);
    }

    // the name of a lane musst be unique within an edge check if this is the case
    if (isLanePresent(name))
    {
        QString errorString(QString::fromLatin1("A lane with the name "));
        errorString.append(name)
                   .append(QString::fromLatin1(" is already present"));
        addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
        return false;
    }

    LaneItem *newChild;
    // determine if lanes are going in or out the lanes are going from left to right
    // so with the first "CarOut" all following lanes are outgoing lanes
    if (_outboundLanes.size() > 0 || type == "CarOut")
    {
        if (type == "Pedestrian" && isLanePresent("Pedestrian", true))
        {
            QLatin1String errorString("The outgoing lanes of the edge have a pedestrian sidewalk already defined. "
                                      "Ignoring the second definition");
            addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
            return false;
        }

        if (type == "Bicycle" && isLanePresent("Bicycle", true))
        {
            QLatin1String errorString("The outgoing lanes of the edge have a bicycle lane already defined. "
                                      "The current model supports only one bicycle lane. "
                                      "Ignoring the second definition");
            addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
            return false;
        }

         newChild = new LaneItem(name, type);
        _outboundLanes.append(newChild);
    }
    else
    {
        if (type == "Pedestrian" && isLanePresent("Pedestrian", false))
        {
            QLatin1String errorString("The ingoing lanes of the edge have a pedestrian sidewalk already defined. "
                                      "Ignoring the second definition");
            addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
            return false;
        }

        if (type == "Bicycle" && isLanePresent("Bicycle", false))
        {
            QLatin1String errorString("The ingoing lanes of the edge have a bicycle lane already defined. "
                                      "The current model supports only one bicycle lane. "
                                      "Ignoring the second definition");
            addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
            return false;
        }

         newChild = new LaneItem(name, type);
        _inboundLanes.append(newChild);
    }

    _lanesParent->appendRow(newChild);

    return true;
}

const QList<LaneItem *> &EdgeItem::inboundLanes() const
{
    return _inboundLanes;
}

const QList<LaneItem*> &EdgeItem::outboundLanes() const
{
    return _outboundLanes;
}

int EdgeItem::numLanes() const
{
    return _numLanes;
}

bool EdgeItem::isLanePresent(const QString &name)
{
    foreach (const LaneItem* inboundLane, _inboundLanes)
    {
        if (!inboundLane->name().compare(name))
        {
            return true;
        }
    }

    foreach (const LaneItem* outboundLane, _outboundLanes)
    {
        if (!outboundLane->name().compare(name))
        {
            return true;
        }
    }

    return false;
}

bool EdgeItem::isLanePresent(const QString &name, bool isEgress)
{
    if (isEgress)
    {
        foreach (const LaneItem* outboundLane, _outboundLanes)
        {
            if (!outboundLane->name().compare(name))
            {
                return true;
            }
        }
    }
    else
    {
        foreach (const LaneItem* inboundLane, _inboundLanes)
        {
            if (!inboundLane->name().compare(name))
            {
                return true;
            }
        }
    }

    return false;
}

void EdgeItem::addPhase(PhaseItem* &phase)
{
    _phases.append(phase);
}

const QList<PhaseItem* >& EdgeItem::phases() const
{
    return _phases;
}

}///end namespace trafficsim
