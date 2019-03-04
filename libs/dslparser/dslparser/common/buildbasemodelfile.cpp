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

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

#include "buildbasemodelfile.hpp"
#include <mobata/utils/functors.hpp>
#include "mobata/model/base/basemodel.hpp"
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/functionitem.hpp>

using namespace utils;
using namespace model::base;

namespace dslparser {
namespace common {

bool saveSpecificationModel(QString* content, const QString& filePath, QString* errorString)
{
  if(filePath.isEmpty()){
    AddPtrString(errorString) << "Parameter 'filePath' is empty!";
    return false;
  }

  QFileInfo fileInfo(filePath);
  QDir directory = fileInfo.absoluteDir();
  if(!directory.exists()){
    AddPtrString(errorString) << "Directory defined in parameter 'filePath' does not exist!";
    return false;
  }

  QFile file(filePath);
  QString output = (*content);
  if(file.open(QIODevice::ReadWrite))
  {
    QTextStream stream(&file);
    stream << output << endl;
    file.close();
  }
  else{
    AddPtrString(errorString) << QStringLiteral("File could not be created!");
    return false;
  }

  return true;
}

void nameDecl(QString* content, const QString& name)
{
  Q_ASSERT(content);

  AddPtrString(content) << QStringLiteral("name: ") +
                           name +
                           QStringLiteral(";");
  return;
}

void commonDecl(const BaseModel* model, QString* content, int tabCount)
{
  Q_ASSERT(model);
  Q_ASSERT(content);

  dataTypeDecl(model, content, tabCount);

  attributeDecl(model, content, tabCount);

  signalDecl(model, content, tabCount);

  functionDecl(model, content, tabCount);

  return;
}

void portsDecl(const PropPorts* propPorts, QString* content, int tabCount)
{
  Q_ASSERT(propPorts);
  Q_ASSERT(content);

  PropPorts::ConstPortSet ports = propPorts->ports();

  if(ports.isEmpty())
    return;

  AddPtrString(content) << QStringLiteral("Port ");
  for(auto port = ports.cbegin(); port != ports.cend(); port++) {
    AddPtrString(content) << (*port)->name();
    if((*port) != ports.back())
      AddPtrString(content) << QStringLiteral(", ");
  }
  AddPtrString(content) << QStringLiteral(";") +
                           nextLine(tabCount);

  return;
}

void signalDecl(const BaseModel* model, QString* content, int tabCount)
{
  Q_ASSERT(model);
  Q_ASSERT(content);

  if(model->getSignals().isEmpty())
    return;

  for(const SignalItem* signal : model->getSignals()){
    AddPtrString(content) << QStringLiteral("Signal ") + signal->name();
    if(!signal->params().isEmpty()){
      AddPtrString(content) << QStringLiteral(" (");
      for(const ParamItem* param : signal->params()) {
        AddPtrString(content) << QStringLiteral(" ") + param->toString();
        if(param != signal->params().back())
          AddPtrString(content) << QStringLiteral(",");
      }
      AddPtrString(content) << QStringLiteral(")");
    }
    AddPtrString(content) << QStringLiteral(";") +
                             nextLine(tabCount);
  }
  AddPtrString(content) << nextLine(tabCount);

  return;
}

void attributeDecl(const BaseModel* model, QString* content, int tabCount)
{
  Q_ASSERT(model);
  Q_ASSERT(content);

  if(model->attributes().isEmpty())
    return;

  for(const AttributeItem* attribute : model->attributes()){
    AddPtrString(content) << QStringLiteral("Attribute ") +
                             attribute->dataType() +
                             QStringLiteral(" ") +
                             attribute->name();
    if(!attribute->initValue().isEmpty()){
      if(attribute->dataType() == QStringLiteral("bool")){
        if(attribute->initValue() == QStringLiteral("0"))
          AddPtrString(content) << QStringLiteral(" = false");
        else if(attribute->initValue() == QStringLiteral("1"))
          AddPtrString(content) << QStringLiteral(" = true");
      }
      else
        AddPtrString(content) << QStringLiteral(" = ") + attribute->initValue();
    }
    AddPtrString(content) << QStringLiteral(";") + nextLine(tabCount);
  }

  AddPtrString(content) << nextLine(tabCount);

  return;
}

void dataTypeDecl(const BaseModel* model, QString* content, int tabCount)
{
  Q_ASSERT(model);
  Q_ASSERT(content);

  if(model->dataTypes().isEmpty())
    return;

  for(const DataTypeItem* type : model->dataTypes()){
    if(type->typeBaseString() != type->toString()){
      AddPtrString(content) << QStringLiteral("Type ") +
                               type->typeDeclString() +
                               QStringLiteral(" ") +
                               type->toString() +
                               QStringLiteral(";") +
                               nextLine(tabCount);
    }
  }

  AddPtrString(content) << nextLine(tabCount);

  return;
}

void functionDecl(const BaseModel* model, QString* content, int tabCount)
{
  Q_ASSERT(model);
  Q_ASSERT(content);

  if(model->functions().isEmpty())
    return;

  for(const FunctionItem* function : model->functions()){
    AddPtrString(content) << QStringLiteral("Function ") +
                             function->returnType() +
                             QStringLiteral(" ") +
                             function->name() +
                             QStringLiteral("(");

    for(const ParamItem* param : function->params()){
      if(param != function->params().first())
        AddPtrString(content) << QStringLiteral(" ");

      AddPtrString(content) << param->toString();

      if(param != function->params().back())
        AddPtrString(content) << QStringLiteral(",");
    }

    AddPtrString(content) << QStringLiteral(")") +
                             nextLine(tabCount) +
                             QStringLiteral("{") +
                             newLineTabHandler(function->statementBody(), tabCount + 1) +
                             nextLine(tabCount) +
                             QStringLiteral("}") +
                             doubleNextLine(tabCount);
  }

  return;
}

QString nextLine(int tabCount)
{
  QString res("\n");
  for(int i = 0; i < tabCount; i++){
    res.append(QStringLiteral(" "));
  }
  return res;
}

QString doubleNextLine(int tabCount)
{
  return nextLine(tabCount) + nextLine(tabCount);
}

QString newLineTabHandler(const QString& input, int tabCount)
{
  QStringList list = input.split(QRegExp("\\n"), QString::SkipEmptyParts);
  for(QStringList::iterator it = list.begin(); it != list.end(); it++){
    (*it) = (*it).trimmed();
    for(int i = 0; i < tabCount; i++)
      (*it).prepend(QStringLiteral(" "));
  }

  QString output = list.join(QStringLiteral("\n"));
  return output;
}

int newLines(const QString& input)
{
  QStringList list = input.split(QRegExp("\\n"), QString::SkipEmptyParts);
  return list.size();
}

void writeMultiLineString(QString* content, const QString& token, const QString& body, int tabCount)
{
  Q_ASSERT(content);
  if(body.isEmpty())
    return;

  AddPtrString(content) << nextLine(tabCount) +
                           token +
                           QStringLiteral(": ");
  if(newLines(body) > 1){
    AddPtrString(content) <<  QStringLiteral("{") +
                              nextLine(0) +
                              newLineTabHandler(body, tabCount + 2) +
                              nextLine(tabCount) +
                              QStringLiteral("}");
  }
  else{
    AddPtrString(content) << body;
    if(body.right(1) != QStringLiteral(";") && body.right(1) != QStringLiteral("}"))
      AddPtrString(content) << QStringLiteral(";");
  }
}

} //common
} //dslparser
