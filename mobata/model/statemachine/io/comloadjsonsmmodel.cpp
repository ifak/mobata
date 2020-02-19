#include "comloadjsonsmmodel.hpp"
#include "readsmmodel.hpp"


#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace statemachine {

class ComLoadJsonSMModel::Private
{
  friend class ComLoadJsonSMModel;

  const QString         _fileName;
  StateMachineModel*    _smModel;

  Private(const QString& fileName,
          StateMachineModel* smModel)
    : _fileName(fileName),
      _smModel(smModel)
  {}
};

ComLoadJsonSMModel::ComLoadJsonSMModel(const QString& fileName,
                                       StateMachineModel* smModel,
                                       QObject *parent)
  : QObject(parent),
    _d(new Private(fileName, smModel))
{}

ComLoadJsonSMModel::~ComLoadJsonSMModel()
{
  delete this->_d;
}

bool ComLoadJsonSMModel::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_smModel);

  QFile inputFile(this->_d->_fileName);
  if (!inputFile.open(QIODevice::ReadOnly
                      | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("statemachine model file '%1' could not be loaded!")
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonParseError jsonError;
  QJsonDocument json_smModelDoc=QJsonDocument::fromJson(inputFile.readAll(), &jsonError);
  if(jsonError.error != QJsonParseError::NoError)
  {
    if(errorMessage)
      *errorMessage += jsonError.errorString();
    return  false;
  }

  this->_d->_smModel->reset();

  bool result = io::readStateMachineModel(json_smModelDoc.object(),
                                          this->_d->_smModel,
                                          errorMessage);

  if(!result)
    return  false;

  return true;
}

} // namespace base
} // namespace model
