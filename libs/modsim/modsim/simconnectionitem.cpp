#include "simconnectionitem.hpp"

namespace modsim{

class SimConnectionItem::Private{
  friend class SimConnectionItem;

  QString         _targetModel;
  QString         _targetPort;

  QString         _sourceModel;
  QString         _sourcePort;

  QStandardItem*  _source;
  QStandardItem*  _target;

  QStandardItem*  _targetModelItem;
  QStandardItem*  _targetPortItem;
  QStandardItem*  _sourceModelItem;
  QStandardItem*  _sourcePortItem;

  Private()
  {
    _source          = new QStandardItem;
    _target          = new QStandardItem;
    _source->setText(QString("Source"));
    _target->setText(QString("Target"));
    _targetModelItem = new QStandardItem;
    _targetPortItem  = new QStandardItem;
    _sourceModelItem = new QStandardItem;
    _sourcePortItem  = new QStandardItem;

    _source->appendRow(_sourceModelItem);
    _source->appendRow(_sourcePortItem);
    _target->appendRow(_targetModelItem);
    _target->appendRow(_targetPortItem);
  }
};

SimConnectionItem::SimConnectionItem():
  model::base::ModelItem(),
  _d(new Private())
{
  setText(QString("Connection"));
  appendRow(_d->_source);
  appendRow(_d->_target);
}

SimConnectionItem::~SimConnectionItem()
{
  delete _d;
}

const QString& SimConnectionItem::targetModel() const
{
  return _d->_targetModel;
}

const QString& SimConnectionItem::targetPort() const
{
  return _d->_targetPort;
}

const QString& SimConnectionItem::sourceModel() const
{
  return  _d->_sourceModel;
}

const QString& SimConnectionItem::sourcePort() const
{
  return  _d->_sourcePort;
}

void SimConnectionItem::setTargetModel(const QString& targetModelAsName)
{
  _d->_targetModel = targetModelAsName;
  _d->_targetModelItem->setText(QString("model: %0").arg(targetModelAsName));
}

void SimConnectionItem::setTargetPort(const QString& targetPortName)
{
  _d->_targetPort = targetPortName;
  _d->_targetPortItem->setText(QString("port: %0").arg(targetPortName));
}

void SimConnectionItem::setSourceModel(const QString& sourceModelAsName)
{
  _d->_sourceModel = sourceModelAsName;
  _d->_sourceModelItem->setText(QString("model: %0").arg(sourceModelAsName));
}

void SimConnectionItem::setSourcePort(const QString& sourcePortName)
{
  _d->_sourcePort = sourcePortName;
  _d->_sourcePortItem->setText(QString("port: %0").arg(sourcePortName));
}

}//namespace modsim
