#include "basemodel.hpp"

#include "datatypeitem.hpp"
#include "attributeitem.hpp"
#include "signalitem.hpp"
#include "paramitem.hpp"
#include "functionitem.hpp"
#include "statichelpers.hpp"

#include "../../utils/functors.hpp"

#include <QSet>
#include <QJsonArray>
#include <QJsonObject>

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{


class BaseModel::Private
{
    friend class BaseModel;

    BaseModel::ImportedBaseModels  _importModels;

    Private():
        _importModels()
    {}

public:
    ~Private()
    {
        for(auto model : _importModels.values()) {
            delete model;
        }
    }
};

BaseModel::BaseModel(QObject *parent)
    : QStandardItemModel(parent),
      PropDataTypes(this->invisibleRootItem()),
      PropAttributes(this->invisibleRootItem()),
      PropSignals(this->invisibleRootItem()),
      PropFunctions(this->invisibleRootItem()),
      _d(new Private())
{
    this->setColumnCount(1);

    this->setHeaderData(0, Qt::Horizontal,
                        QLatin1String("declaration"),
                        Qt::DisplayRole);
    //  this->setHeaderData(1, Qt::Horizontal,
    //                      QLatin1String("comment"),
    //                      Qt::DisplayRole);
}

BaseModel::BaseModel(const QString& modelName,
                     QObject* parent)
    : QStandardItemModel (parent),
      prop::NameProperty (modelName),
      PropDataTypes(this->invisibleRootItem()),
      PropAttributes(this->invisibleRootItem()),
      PropSignals(this->invisibleRootItem()),
      PropFunctions(this->invisibleRootItem()),
      _d(new Private())
{
    this->setColumnCount(1);

    this->setHeaderData(0, Qt::Horizontal,
                        QLatin1String("declaration"),
                        Qt::DisplayRole);
    //  this->setHeaderData(1, Qt::Horizontal,
    //                      QLatin1String("comment"),
    //                      Qt::DisplayRole);
}

BaseModel::~BaseModel()
{
    delete this->_d;
}

void BaseModel::reset()
{
    this->resetDataTypes();
    this->resetAttributes();
    this->resetSignals();
    this->resetFunctions();

    return;
}

void serializeTypes(BaseModel const* baseModel, QJsonObject* json_baseModel)
{
    QJsonArray json_types;
    for(DataTypeItem const* typeItem : baseModel->dataTypes())
    {
        QJsonObject json_type;
        json_type["uuid"]=typeItem->uuid().toString();
        json_type["typeEnum"]=prop::typeEnum2string(typeItem->typeEnum());
        if(typeItem->typeEnum() == prop::Unknown && !typeItem->customType().isEmpty())
          json_type["customType"]=typeItem->customType();
        json_type["name"]=typeItem->name();
        json_type["lowest"]=typeItem->lowest();
        json_type["highest"]=typeItem->highest();

        if(typeItem->literals().size())
        {
            QJsonArray json_typeLiterals;
            for(const QString& literal : typeItem->literals())
                json_typeLiterals.push_back(literal);
            json_type["literals"]=json_typeLiterals;
        }

        json_types.push_back(json_type);
    }
    json_baseModel->insert("types", json_types);

    return;
}

void serializeAttributes(BaseModel const* ExtBaseModel, QJsonObject* json_baseModel)
{
    QJsonArray json_attributes;
    for(AttributeItem const* attrItem : ExtBaseModel->attributes())
    {
        QJsonObject json_attribute;
        json_attribute["name"]=attrItem->name();
        json_attribute["type"]=attrItem->dataType();
        json_attribute["initValue"]=attrItem->initValue();

        json_attributes.push_back(json_attribute);
    }
    json_baseModel->insert("attributes", json_attributes);

    return;
}

void serializeSignals(BaseModel const* baseModel, QJsonObject* json_baseModel)
{
    QJsonArray json_signals;
    for(SignalItem const* signalItem : baseModel->getSignals())
    {
        QJsonObject json_signal;
        json_signal["uuid"]=signalItem->uuid().toString();
        json_signal["name"]=signalItem->name();

        if(signalItem->params().size())
        {
            QJsonArray json_signalParams;
            for(ParamItem const* paramItem : signalItem->params())
            {
                QJsonObject json_signalParam;

                json_signalParam["name"]=paramItem->name();
                json_signalParam["type"]=paramItem->dataType();

                json_signalParams.push_back(json_signalParam);
            }
            json_signal["params"]=json_signalParams;
        }
        json_signals.push_back(json_signal);
    }
    json_baseModel->insert("signals", json_signals);

    return;
}

void serializeFunctions(BaseModel const* baseModel, QJsonObject* json_baseModel)
{
    QJsonArray json_functions;
    for(FunctionItem const* functionItem : baseModel->functions())
    {
        QJsonObject json_function;
        json_function["uuid"]=functionItem->uuid().toString();
        json_function["name"]=functionItem->name();
        json_function["returnType"]=functionItem->returnType();
        json_function["statementBody"]=functionItem->statementBody();

        if(functionItem->params().size())
        {
            QJsonArray json_functionParams;
            for(ParamItem const* paramItem : functionItem->params())
            {
                QJsonObject json_functionParam;

                json_functionParam["name"]=paramItem->name();
                json_functionParam["type"]=paramItem->dataType();

                json_functionParams.push_back(json_functionParam);
            }
            json_function["params"]=json_functionParams;
        }
        json_functions.push_back(json_function);
    }
    json_baseModel->insert("functions", json_functions);

    return;
}

JsonObjectPtr BaseModel::createJson() const
{
    JsonObjectPtr json_baseModelPtr(new QJsonObject());

    json_baseModelPtr->insert("name", this->name());

    serializeTypes(this, json_baseModelPtr.data());
    serializeAttributes(this, json_baseModelPtr.data());
    serializeSignals(this, json_baseModelPtr.data());
    serializeFunctions(this, json_baseModelPtr.data());

    return json_baseModelPtr;
}

const BaseModel::ImportedBaseModels & BaseModel::importedModels() const
{
    return _d->_importModels;
}

bool BaseModel::addImportedModel(const QString &name, BaseModel *model, QString *errorMessage) const
{
    if(_d->_importModels.contains(name)){
        if(errorMessage)  errorMessage->append(QString("The BaseModel with the name \"%1\" already exists!").arg(name));
        return false;
    }
    _d->_importModels.insert(name,model);
    return true;
}

void BaseModel::removeImportedModel(const QString &name) const
{
    if(_d->_importModels.contains(name)){
        delete _d->_importModels.value(name);
        _d->_importModels.remove(name);
    }
}

}///end namespace base
}///end namespace model
