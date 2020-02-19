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
#pragma once
#include "../dslparser_global.hpp"
#include <mobata/model/base/propports.hpp>

namespace model{
namespace base{
  class BaseModel;
}
}

namespace dslparser {
namespace common{

void nameDecl(QString* content, const QString& name);
void commonDecl(const model::base::BaseModel* model, QString* content, int tabCount);
void portsDecl(const model::base::PropPorts* propPorts, QString* content, int tabCount);
void signalDecl(const model::base::BaseModel* model, QString* content, int tabCount);
void attributeDecl(const model::base::BaseModel* model, QString* content, int tabCount);
void dataTypeDecl(const model::base::BaseModel* model, QString* content, int tabCount);
void functionDecl(const model::base::BaseModel* model, QString* content, int tabCount);
QString nextLine(int tabCount);
QString doubleNextLine(int tabCount);
QString newLineTabHandler(const QString& input, int tabCount);
int newLines(const QString& input);
void writeMultiLineString(QString* content, const QString& token, const QString& body, int tabCount);
bool saveSpecificationModel(QString* content, const QString& filePath, QString* errorString);


}//namespace common
} // namespace dslparser
