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
#ifndef MODEL_BASE_IO_READBASEMODEL_HPP
#define MODEL_BASE_IO_READBASEMODEL_HPP

class QJsonObject;
class QJsonValue;
class QString;

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

namespace io {

///read objects//////////

bool readBaseModel(const QJsonObject& jsonObject,
                   BaseModel* baseModel,
                   QString* errorMessage);

bool readModelItem(const QJsonObject& jsonObject,
                   ModelItem* modelItem,
                   QString* errorMessage);

template<class DataTypeModel>
bool readDataTypes(const QJsonObject& jsonObject,
                   DataTypeModel* dataTypeModel,
                   QString* errorMessage);

template<class DataTypeModel>
struct ReadDataType
{
  bool operator()(const QJsonObject& jsonObject,
                  DataTypeModel* dataTypeModel,
                  QString* errorMessage);
};

template<class SignalsModel>
bool readSignals(const QJsonObject& jsonObject,
                 SignalsModel* signalsModel,
                 QString* errorMessage);

template<class SignalsModel>
struct ReadSignal
{
  bool operator()(const QJsonObject& jsonObject,
                  SignalsModel* signalsModel,
                  QString* errorMessage);
};

template<class AttributesModel>
bool readAttributes(const QJsonObject& jsonObject,
                    AttributesModel* attributesModel,
                    QString* errorMessage);

template<class AttributesModel>
struct ReadAttribute
{
  bool operator()(const QJsonObject& jsonObject,
                  AttributesModel* attributesModel,
                  QString* errorMessage);
};

template<class ComponentsModel>
bool readComponents(const QJsonObject& jsonObject,
                    ComponentsModel* componentsModel,
                    QString* errorMessage);

template<class ComponentsModel, class ReadComponentFunctor>
bool readComponents(const QJsonObject& jsonObject,
                    ComponentsModel* componentsModel,
                    ReadComponentFunctor readComponentFunctor,
                    QString* errorMessage);

template<class ComponentsModel>
struct ReadComponent
{
  bool operator()(const QJsonObject& jsonObject,
                  ComponentsModel* componentsModel,
                  QString* errorMessage);
};

template<class PortsModel>
bool readPorts(const QJsonObject& jsonObject,
               PortsModel* portsModel,
               QString* errorMessage);

template<class PortsModel>
struct ReadPort
{
  bool operator()(const QJsonObject& jsonObject,
                  PortsModel* portsModel,
                  QString* errorMessage);
};

template<class LinksModel>
bool readLinks(const QJsonObject& jsonObject,
               LinksModel* linksModel,
               QString* errorMessage);

template<class LinksModel>
struct ReadLink
{
  bool operator()(const QJsonObject& jsonObject,
                  LinksModel* linksModel,
                  QString* errorMessage);
};

template<class ParamsModel, class DataTypeModel>
bool readParams(const QJsonObject& jsonObject,
                ParamsModel* paramsModel,
                DataTypeModel* dataTypeModel,
                QString* errorMessage);

template<class ParamsModel, class DataTypeModel>
struct ReadParam
{
  DataTypeModel* _dataTypeModel;

  ReadParam(DataTypeModel* dataTypeModel)
    : _dataTypeModel(dataTypeModel)
  {}

  bool operator()(const QJsonObject& jsonObject,
                  ParamsModel* paramsMode,
                  QString* errorMessage);
};

template<class ParamsModel, class ParamValuesModel>
bool readParamValues(const QJsonObject& jsonObject,
                     ParamsModel* paramsModel,
                     ParamValuesModel* paramValuesModel,
                     QString* errorMessage);

template<class ParamValuesModel, class ReadParamValueFunctor>
bool readParamValues(const QJsonObject& jsonObject,
                     ParamValuesModel* paramValuesModel,
                     ReadParamValueFunctor readParamValueFunctor,
                     QString* errorMessage);

template<class ParamsModel, class ParamValuesModel>
struct ReadParamValue
{
  ParamsModel const* _paramsModel;
  ReadParamValue(ParamsModel const* paramsModel)
    : _paramsModel(paramsModel)
  {}

  bool operator()(const QJsonObject& jsonObject,
                  ParamValuesModel* paramValuesModel,
                  QString* errorMessage);
};

} // namespace io
} // namespace base
} // namespace model

#include "readhelpers.hpp"
#include "readbasemodel.inl"

#endif // MODEL_BASE_IO_READBASEMODEL_HPP
