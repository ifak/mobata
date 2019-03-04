/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "msc_types.hpp"

#include "mscstepitem.hpp"
#include "../../prop/referenceidproperty.hpp"

#include <QString>

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscMessageItem
    : public MscStepItem,
    public prop::ReferenceIdProperty
{
public:
  typedef QList<ParamValueItem const*>  ConstParamValues;
  typedef QList<ParamValueItem*>        ParamValues;

public:
  MscMessageItem(PortItem const* sourcePort,
                 PortItem const* targetPort,
                 const QString& text=QString());
  virtual ~MscMessageItem();

public:
  virtual int     stepType() const        { return MessageStep;}
  virtual QString stepTypeString() const  { return QLatin1String(constants::MessageStepId);}

public:
  PortItem const*   sourcePort() const;
  PortItem const*   targetPort() const;

public:
  void                  setSignal(SignalItem const* signal);
  SignalItem const*     signal() const;

  ParamValueItem*       addParamValue(ParamItem const* parameter,
                                      const QVariant& value);
  ParamValueItem const* paramValue(const QString& paramName) const;
  ParamValueItem *      paramValue(const QString& paramName);
  ConstParamValues      paramValues() const;
  ParamValues           paramValues();

public:
  virtual QString toString() const;
  virtual QString toString(bool prettyPrint) const;

private:
  Q_DISABLE_COPY(MscMessageItem)
  class Private;
  Private* _d;
};

}/// end namespace msc
}/// end namespace model
