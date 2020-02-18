#include "comsavereqmodel.hpp"

#include "requirementsmodel.hpp"
#include "io/writereqmodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace irdl {

class ComSaveReqModel::Private
{
  friend class ComSaveReqModel;

  RequirementsModel const*  _reqModel;
  QString           _fileName;

  Private(RequirementsModel const* reqModel,
          const QString& fileName)
    : _reqModel(reqModel),
      _fileName(fileName)
  {}
};

ComSaveReqModel::ComSaveReqModel(const RequirementsModel *reqModel,
                                 const QString& fileName,
                                 QObject *parent)
  : QObject(parent),
    _d(new Private(reqModel, fileName))
{}

ComSaveReqModel::~ComSaveReqModel()
{
  delete this->_d;
}

bool ComSaveReqModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("msc model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_reqModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_reqModelObject;
  io::writeReqModel(this->_d->_reqModel, json_reqModelObject);
  QJsonDocument jsonDocument(json_reqModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

std::string ComSaveReqModel::jsonString()
{
    QJsonObject json_reqModelObject;
    io::writeReqModel(this->_d->_reqModel, json_reqModelObject);
    QJsonDocument jsonDocument(json_reqModelObject);
    return jsonDocument.toJson().toStdString();
}

} // namespace requirement
} // namespace model
