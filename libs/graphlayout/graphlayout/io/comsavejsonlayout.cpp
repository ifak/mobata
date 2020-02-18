#include "comsavejsonlayout.hpp"
#include "writelayout.hpp"
#include "layoutgraph.hpp"

#include <mobata/utils/functors.hpp>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace graphlayout {

class ComSaveJsonLayout::Private
{
  friend class ComSaveJsonLayout;

  LayoutGraph const*  _layout;
  QString           _fileName;

  Private(LayoutGraph const* layout,
          const QString& fileName)
    : _layout(layout),
      _fileName(fileName)
  {}
};

ComSaveJsonLayout::ComSaveJsonLayout(LayoutGraph const* layout,
                               const QString& fileName,
                               QObject *parent)
  : QObject(parent),
    _d(new Private(layout, fileName))
{}

ComSaveJsonLayout::~ComSaveJsonLayout()
{
  delete this->_d;
}

bool ComSaveJsonLayout::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    utils::AddPtrString(errorMessage) << "layout " <<  this->_d->_layout->name() << " could not be saved to " << this->_d->_fileName << "!";
    return false;
  }

  QJsonObject json_layoutObject;
  io::writeLayout(this->_d->_layout,
                  json_layoutObject);
  QJsonDocument jsonDocument(json_layoutObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace graphlayout
