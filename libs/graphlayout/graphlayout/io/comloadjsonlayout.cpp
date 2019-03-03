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

#include "comloadjsonlayout.hpp"
#include "readlayout.hpp"
#include "layoutgraph.hpp"

#include <mobata/utils/functors.hpp>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace graphlayout {

class ComLoadJsonLayout::Private
{
  friend class ComLoadJsonLayout;

  const QString _fileName;
  LayoutGraph*    _layout;

  Private(const QString& fileName,
          LayoutGraph* layout)
    : _fileName(fileName),
      _layout(layout)
  {}
};

ComLoadJsonLayout::ComLoadJsonLayout(const QString& fileName,
                               LayoutGraph* layout,
                               QObject *parent)
  : QObject(parent),
    _d(new Private(fileName, layout))
{}

ComLoadJsonLayout::~ComLoadJsonLayout()
{
  delete this->_d;
}

bool ComLoadJsonLayout::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_layout);

  QFile inputFile(this->_d->_fileName);
  if (!inputFile.open(QIODevice::ReadOnly
                      | QIODevice::Text))
  {
    utils::AddPtrString(errorMessage) << "layout file " << this->_d->_fileName << " could not be loaded!";
    return false;
  }

  QJsonParseError jsonError;
  QJsonDocument json_layoutDoc = QJsonDocument::fromJson(inputFile.readAll(), &jsonError);
  if(jsonError.error != QJsonParseError::NoError)
  {
    utils::AddPtrString(errorMessage) << jsonError.errorString();
    return  false;
  }

  //delete layout if dependency check fails
  if(!io::dependencyCheck(json_layoutDoc.object(),
                          this->_d->_layout,
                          errorMessage)){
    //inputFile.remove();   //not removing layout file for now!
    utils::AddPtrString(errorMessage) << "Not all dependent graph elements have been found. Layout file is no longer up-to-date and therefore removed.";
    return false;
  }


  io::readLayout(json_layoutDoc.object(),
                 this->_d->_layout,
                 errorMessage);

  return true;
}

} // namespace graphlayout
