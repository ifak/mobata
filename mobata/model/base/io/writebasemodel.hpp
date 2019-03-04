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

#ifndef MODEL_BASE_IO_WRITEBASEMODEL_HPP
#define MODEL_BASE_IO_WRITEBASEMODEL_HPP

class QJsonObject;

namespace model {
namespace base {

class BaseModel;
class ModelItem;
class AttributeItem;
class ComponentItem;
class LinkItem;
class ParamItem;
class ParamValueItem;
class PortItem;
class SignalItem;
class DataTypeItem;

class PropAttributes;
class PropComponents;
class PropLinks;
class PropPorts;
class PropSignals;
class PropDataTypes;

namespace io {

///write objects//////////

void writeBaseModel(BaseModel const* baseModel,
                    QJsonObject& jsonObject);

void writeModelItem(ModelItem const* modelItem,
                    QJsonObject& jsonObject);

void writeAttribute(AttributeItem const* attributeItem,
                    QJsonObject& jsonObject);

void writeComponent(ComponentItem const* componentItem,
                    QJsonObject& jsonObject);

void writeDataType(DataTypeItem const* typeItem,
               QJsonObject& jsonObject);

void writeLink(LinkItem const* linkItem,
               QJsonObject& jsonObject);

void writeParamItem(ParamItem const* paramItem,
                    QJsonObject& jsonObject);

void writeParamValueItem(ParamValueItem const* paramValueItem,
                         QJsonObject& jsonObject);

void writePort(PortItem const* portItem,
               QJsonObject& jsonObject);

void writeSignal(SignalItem const* signalItem,
                 QJsonObject& jsonObject);

//////////write ObjectCollections/////////////

void writePropAttributes(PropAttributes const* propAttributes,
                         QJsonObject& jsonObject);

void writePropComponents(PropComponents const* propComponents,
                         QJsonObject& jsonObject);

void writePropLinks(PropLinks const* propLinks,
                    QJsonObject& jsonObject);

void writePropPorts(PropPorts const* propPorts,
                    QJsonObject& jsonObject);

void writePropSignals(PropSignals const* propSignals,
                      QJsonObject& jsonObject);

void writePropDataTypes(PropDataTypes const* propTypes,
                    QJsonObject& jsonObject);

} // namespace io
} // namespace base
} // namespace model

#endif // MODEL_BASE_IO_WRITEBASEMODEL_HPP
