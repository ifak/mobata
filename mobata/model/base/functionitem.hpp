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

#include "../../mobata_global.hpp"

#include "modelitem.hpp"
#include "propparams.hpp"
#include "propattributes.hpp"

#include "../../prop/nameproperty.hpp"

namespace model{
namespace base{

class MOBATASHARED_EXPORT FunctionItem
    : public ModelItem,
    public PropParams,
    public PropAttributes,//for local variables
    public prop::NameProperty
{
public:
  FunctionItem(const QString& name=QLatin1String(""),
               const QString& returnType=nullptr,
               const QString& statementBody=QLatin1String(""),
               const QUuid& uuid=QUuid::createUuid());
  virtual ~FunctionItem();

public:
  QString returnType() const;
  void                  setReturnType(const QString &returnType);
  const	QString&        statementBody() const;
  void                  setStatementBody(const QString& statementBody);
  virtual	QString       toString() const;
  virtual	QString       declarationToString() const;
  FunctionItem*         clone() const;

private:
  Q_DISABLE_COPY(FunctionItem)
  class Private;
  Private* _d;
};

}///end namespace base
}///end namespace model
