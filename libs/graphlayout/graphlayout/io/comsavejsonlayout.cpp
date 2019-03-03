/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

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
