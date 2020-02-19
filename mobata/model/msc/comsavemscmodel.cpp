#include "comsavemscmodel.hpp"

#include "mscmodel.hpp"
#include "io/writemscmodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace msc {

class ComSaveMscModel::Private
{
  friend class ComSaveMscModel;

  MscModel const*  _mscModel;
  QString           _fileName;

  Private(MscModel const* mscModel,
          const QString& fileName)
    : _mscModel(mscModel),
      _fileName(fileName)
  {}
};

ComSaveMscModel::ComSaveMscModel(MscModel const* mscModel,
                                 const QString& fileName,
                                 QObject *parent)
  : QObject(parent),
    _d(new Private(mscModel, fileName))
{}

ComSaveMscModel::~ComSaveMscModel()
{
  delete this->_d;
}

bool ComSaveMscModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("msc model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_mscModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_mscModelObject;
  io::writeMscModel(this->_d->_mscModel, json_mscModelObject);
  QJsonDocument jsonDocument(json_mscModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace msc
} // namespace model
