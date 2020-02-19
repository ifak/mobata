#include "trafficsimmodel.hpp"
#include "intersectionitem.hpp"
#include "stepitem.hpp"

#include "Util/errortracker.hpp"

namespace trafficsim{

TrafficSimModel::TrafficSimModel(QObject* parent)
  : QStandardItemModel(parent),
    _steps(nullptr)
{}

TrafficSimModel::~TrafficSimModel()
{
    if (_steps)
    {
        for (int i = 0; i < _simulationSteps.count(); i++)
        {
            _steps->takeRow(_simulationSteps.at(i)->row());
        }
        qDeleteAll(_simulationSteps);

        _steps->removeRows(0, _steps->rowCount());

        this->takeRow(_steps->row());
        delete _steps;
    }

    if(!_trafficDistributions.empty()){
        qDeleteAll(_trafficDistributions);
        _trafficDistributions.clear();
    }

    if (!_intersections.isEmpty())
    {
        qDeleteAll(_intersections);
    }
}

const QList<TrafficDistributionItem*> &TrafficSimModel::trafficDistributions() const
{
    return _trafficDistributions;
}

void TrafficSimModel::setTrafficDistributions(const QList<TrafficDistributionItem*> &value)
{
    qDeleteAll(_trafficDistributions);
    _trafficDistributions.clear();
    _trafficDistributions = value;
}

void TrafficSimModel::addTrafficDistribution(TrafficDistributionItem *newDistribution)
{
    _trafficDistributions.append(newDistribution);
}

IntersectionItem *TrafficSimModel::addIntersection(const QString &name,
                                                   qreal accident,
                                                   bool hasTrafficLight,
                                                   QList<QQmlError> &errorList,
                                                   const QString &fileName)
{
    bool checkName = false;
    foreach (IntersectionItem* intersection, _intersections) {
        checkName |= intersection->uuid().toString() == name; //TODO:also no idea if this works
    }
    IntersectionItem* intersectionItem;
    if (!checkName)
    {
        if ((1 < accident) || (0 > accident))
        {
            QString errorString(QString::fromLatin1("The traffic accident probability needs to be between 0 and 1. "));
            errorString.append(QString::fromLatin1("The current value "))
                    .append(QString::number(accident))
                    .append(QString::fromLatin1(" is not suited as proability and will be set to 0."));
            addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
            return nullptr;
        }
        else
        {
            intersectionItem = new IntersectionItem(name, accident, hasTrafficLight);
        }
        _intersections.append(intersectionItem);
        this->appendRow(intersectionItem);
    }
    else
    {
        QString errorString(QString::fromLatin1("A intersection with the same name was already created before no new intersection will be "
                                                                                           "created the old one will be used instead"));
        addError(errorString, -1, QUrl::fromLocalFile(fileName), errorList);
        return nullptr;
    }

    return intersectionItem;
}

StepItem *TrafficSimModel::addStep(const QString &name, int start, int stop)
{
    if (0x00 == _steps)
    {
        _steps = new model::base::ModelItem("Steps");
        this->appendRow(_steps);
    }

    StepItem *newStep = new StepItem(name, start, stop);
    _steps->appendRow(newStep);
    _simulationSteps.append(newStep);

    return newStep;
}

const QList<StepItem*> &TrafficSimModel::simulationSteps() const
{
    return _simulationSteps;
}

const QList<IntersectionItem *>&TrafficSimModel::intersections() const
{
    return _intersections;
}

void TrafficSimModel::reset()
{
    if (_steps)
    {
        this->takeRow(_steps->row());

        for (int i = _steps->rowCount(); i > 0; i--)
        {
            _steps->takeRow(i-1);
        }

        qDeleteAll(_simulationSteps);
        _simulationSteps.clear();
        delete _steps;
        _steps = 0x00;
    }

    if (!_intersections.isEmpty())
    {
        for (int i = _intersections.count(); i > 0; i--)
        {
            this->takeRow(_intersections[i]->row());
        }
        qDeleteAll(_intersections);
    }

    this->invisibleRootItem()->removeRows(0, this->invisibleRootItem()->rowCount());
}

}///end namespace trafficsim
