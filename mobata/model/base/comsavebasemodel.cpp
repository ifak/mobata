#include "comsavebasemodel.hpp"

#include "basemodel.hpp"
#include "io/writebasemodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace base {

class ComSaveBaseModel::Private
{
  friend class ComSaveBaseModel;

  BaseModel const*  _baseModel;
  const QString     _fileName;

  Private(BaseModel const* baseModel,
          const QString& fileName)
    : _baseModel(baseModel),
      _fileName(fileName)
  {}
};

ComSaveBaseModel::ComSaveBaseModel(BaseModel const* baseModel,
                                   const QString& fileName,
                                   QObject *parent)
  : QObject(parent),
    _d(new Private(baseModel, fileName))
{}

ComSaveBaseModel::~ComSaveBaseModel()
{
  delete this->_d;
}

bool ComSaveBaseModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("base model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_baseModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_baseModelObject;
  io::writeBaseModel(this->_d->_baseModel, json_baseModelObject);
  QJsonDocument jsonDocument(json_baseModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace base
} // namespace model
