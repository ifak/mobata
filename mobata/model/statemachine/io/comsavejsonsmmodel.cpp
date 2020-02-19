#include "comsavejsonsmmodel.hpp"
#include "writesmmodel.hpp"

#include "../statemachinemodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace statemachine {

class ComSaveJsonSMModel::Private
{
  friend class ComSaveJsonSMModel;

  StateMachineModel const*  _smModel;
  QString           _fileName;

  Private(StateMachineModel const* smModel,
          const QString& fileName)
    : _smModel(smModel),
      _fileName(fileName)
  {}
};

ComSaveJsonSMModel::ComSaveJsonSMModel(StateMachineModel const* smModel,
                               const QString& fileName,
                               QObject *parent)
  : QObject(parent),
    _d(new Private(smModel, fileName))
{}

ComSaveJsonSMModel::~ComSaveJsonSMModel()
{
  delete this->_d;
}

bool ComSaveJsonSMModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("statemachine model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_smModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_smModelObject;
  io::writeStateMachineModel(this->_d->_smModel, json_smModelObject);
  QJsonDocument jsonDocument(json_smModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace msc
} // namespace model
