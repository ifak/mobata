#include "simmodelitem.hpp"

namespace modsim{

class SimModelItem::Private{
  friend class SimModelItem;

  QString        _modelPath;

  QStandardItem* _modelNameItem;
  QStandardItem* _modelPathItem;

  Private(const QString& absolutePath)
    : _modelPath(absolutePath)
  {
    _modelNameItem = new QStandardItem;
    _modelPathItem = new QStandardItem;
  }
};

SimModelItem::SimModelItem(const QString& name, const QString& absolutePath):
  model::base::ModelItem(),
  prop::NameProperty(name),
  _d(new Private(absolutePath))
{
  this->_d->_modelNameItem->setText(QString("name: %0").arg(name));
  this->_d->_modelPathItem->setText(QString("absolutePath: %1").arg(absolutePath));
  appendRow(_d->_modelNameItem);
  appendRow(_d->_modelPathItem);
}

SimModelItem::~SimModelItem()
{
  delete _d;
}

const QString& SimModelItem::absoluteFilePath() const
{
  return _d->_modelPath;
}

void SimModelItem::setAbsoluteFilePath(const QString& path)
{
  _d->_modelPathItem->setText(QString("path: %1").arg(path));
  _d->_modelPath = path;
}

}//namespace modsim
