#include "combuildtestcasefile.hpp"

#include <mobata/model/testcase/testcasemodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/propparams.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>

#include <mobata/model/ts/testcaseitem.hpp>
#include <mobata/model/msc/mscsequenceitem.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/msc/mscstatementitem.hpp>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace model::msc;
using namespace utils;
//using namespace antlr4;

namespace dslparser {
namespace testcase {

class ComBuildTestCaseFile::Private
{
    friend class ComBuildTestCaseFile;

    QString&                  _testcaseDocText;
    TestCaseItem*        _testcaseDeclModel;
    DslErrorList              _testcaseErrors;

    Private(QString& testcaseDocText,
            TestCaseItem* testcaseDeclModel)
        : _testcaseDocText(testcaseDocText),
          _testcaseDeclModel(testcaseDeclModel)
    {}
};

ComBuildTestCaseFile::ComBuildTestCaseFile(QString &testcaseDocText,
                                           TestCaseItem* testcaseDeclModel,
                                           QObject* parent)
    : QObject(parent), _d(new Private(testcaseDocText, testcaseDeclModel))
{}

ComBuildTestCaseFile::~ComBuildTestCaseFile()
{
    delete  this->_d;
}

bool ComBuildTestCaseFile::execute(QString* errorString)
{
    //  qDebug()<<"ComBuildTestCaseFile::execute()!";

    Q_ASSERT(this->_d->_testcaseDeclModel);
    this->_d->_testcaseDocText = "";
    testCaseDecl(this->_d->_testcaseDocText,this->_d->_testcaseDeclModel);
}

const DslErrorList& ComBuildTestCaseFile::errors() const
{
    return this->_d->_testcaseErrors;
}

void ComBuildTestCaseFile::testCaseDecl(QString &content, TestCaseItem *model, int anzTabs)
{
    content = QString("TestCase {") + nextLine(anzTabs + 1);
    QString newContent = "";
    testCaseBody(newContent,model,anzTabs+1);
    content += newContent + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::testCaseBody(QString &content, TestCaseItem *model, int anzTabs)
{
    QString optional = QString("");
    declarations(optional,model,anzTabs+1);
    QString stepsStr = QString("");
    stepsDecl(stepsStr,model->sequenceItems(),anzTabs);
    content = QString("declarations {") + nextLine(anzTabs+1) + optional + nextLine(anzTabs) + QString("}") + nextLine(anzTabs) + stepsStr;
    content = name + nextLine(anzTabs) + optional;
}

void ComBuildTestCaseFile::declarations(QString &content, TestCaseItem *model, int anzTabs)
{
    QString name = QString("");
    QString common = QString("");
    QString enabled = QString("");

    nameDecl(name,model->name(),anzTabs);
    enabledDecl(enabled,model->isEnabled(),anzTabs);
    content = name + nextLine(anzTabs) + common + nextLine(anzTabs) + enabled;
}

void ComBuildTestCaseFile::signalDecl(QString &content, model::base::SignalItem *model, int anzTabs)
{
    content = QString("Signal ") + model->name() + QString("(");
    foreach (auto param, model->params()) {
        QString paramStr("");
        paramDecl(paramStr,param);
        content += paramStr + QString(" ,");
    }
    if(content.at(content.size()-1) == QChar(',')) content.chop(2);
    content += QString(");");

}

void ComBuildTestCaseFile::stepsDecl(QString &content,  QList<MscSequenceItem const*> modelList, int anzTabs)
{
    content = QString("");
    foreach (auto model, modelList) {
        QString stepStr("");
        if(auto item = dynamic_cast<CheckMessageItem*>(model)){
            checkDecl(stepStr,item,anzTabs);
        }
        else if(auto item = dynamic_cast<MessageItem*>(model)){
            messageDecl(stepStr,item,anzTabs);
        }
        else if(auto item = dynamic_cast<TimerItem*>(model)){
            timerDecl(content,item);
        }
        else if(auto item = dynamic_cast<MscFragmentItem*>(model)){
            altDecl(stepStr,item,anzTabs);
        }
        else if(auto item = dynamic_cast<MscStatementItem*>(model)){
            statementDecl(stepStr,item,anzTabs);
        }
        content += stepStr + nextLine(anzTabs);
    }
}

void ComBuildTestCaseFile::assignmentDecl(QString &content, MscStatementItem *model, int anzTabs)
{
    if(model->entryAction()!=QString("") || model->exitAction()!=QString("")){
        QString body("");
        simpleStateBody(body,model,anzTabs+1);
        content = QString("SimpleState ") + QString("{") + nextLine(anzTabs + 1) + body + nextLine(anzTabs) + QString("}");
    }
    else{
        content = QString("SimpleState ") + model->name() + QString(";");
    }
}

void ComBuildTestCaseFile::simpleStateBody(QString &content, AbstractStateItem *model, int anzTabs)
{
    nameDecl(content,model->name(), anzTabs);
    PropEntryAction* entryItem = dynamic_cast<PropEntryAction*>(model);
    PropExitAction* exitItem = dynamic_cast<PropExitAction*>(model);
    if(entryItem->entryAction()!=QString("")){
        QString entry("");
        entryActionDecl(entry,entryItem->entryAction(),anzTabs);
        content += nextLine(anzTabs) + entry;
    }
    else if(exitItem->exitAction()!=QString("")){
        QString exit("");
        exitActionDecl(exit,exitItem->exitAction(),anzTabs);
        content += nextLine(anzTabs) + exit;
    }
}

void ComBuildTestCaseFile::junctionStateDecl(QString &content, JunctionStateItem *model, int anzTabs)
{
    content = QString("JunctionState ") + model->name() + QString(";");
}

//void ComBuildTestCaseFile::parallelStateDecl(QString &content, model::testcase::ParallelStateItem *model)
//{

//}

//void ComBuildTestCaseFile::parallelStateBody(QString &content, model::testcase::ParallelStateItem *model)
//{

//}

//void ComBuildTestCaseFile::parallelStateBodyOptional(QString &content, model::testcase::ParallelStateItem *model)
//{

//}

//void ComBuildTestCaseFile::regionDecl(QString &content)
//{

//}

void ComBuildTestCaseFile::regionBody(QString &content, AbstractStateItem *model, int anzTabs)
{
    if(auto item = dynamic_cast<CompositeStateItem*>(model)){
        initStateDecl(content,item->initState(),anzTabs);
        QString simpleStateContent("");
        simpleStateBody(simpleStateContent,item,anzTabs);

        QString statesStr("");
        auto states = item->states();
        foreach (auto state, states) {
            QString stateStr("");
            stateDecl(stateStr,state,anzTabs);
            statesStr += stateStr + nextLine(anzTabs);
        }
        content += nextLine(anzTabs) + simpleStateContent + nextLine(anzTabs) + statesStr;
    }
}

void ComBuildTestCaseFile::compositeStateDecl(QString &content, CompositeStateItem *model, int anzTabs)
{
    QString region("");
    regionBody(region,model,anzTabs+1);
    content = QString("CompositeState {") + nextLine(anzTabs+1) + region + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::finalStateDecl(QString &content, FinalStateItem *model, int anzTabs)
{
    content = QString("FinalState ") + model->name() + QString(";");
}

void ComBuildTestCaseFile::initStateDecl(QString &content, const InitStateItem *model, int anzTabs)
{
    content = QString("initState: ") + model->name() + QString(";");
}

void ComBuildTestCaseFile::guardDecl(QString &content, const QString &guard, int anzTabs)
{
    content = QString("guard: {") + nextLine(anzTabs+1) + guard + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::actionDecl(QString &content, const QString &action, int anzTabs)
{
    content = QString("action: {") + nextLine(anzTabs+1) + action + QString(";") + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::transitionDecl(QString &content, TransitionItem *model, int anzTabs)
{
    signalTransitionDecl(content,model,anzTabs);
}

void ComBuildTestCaseFile::signalTransitionDecl(QString &content, TransitionItem *model, int anzTabs)
{
    QString signalBody("");
    signalTransitionBody(signalBody,model,anzTabs);
    content = QString("SignalTransition {") + nextLine(anzTabs+1) + signalBody + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::signalTransitionBody(QString &content, TransitionItem *model, int anzTabs)
{
    nameDecl(content,model->name(),anzTabs);
    if(model->signal()){
        QString refSignal("");
        refSignalDecl(refSignal,model->signal());
        content += nextLine(anzTabs) + refSignal;
    }
    if(model->guard() != QString("")){
        QString guard("");
        guardDecl(guard,model->guard(),anzTabs);
        content += nextLine(anzTabs) + guard;
    }
    if(model->action() != QString("")){
        QString action("");
        actionDecl(action,model->action(),anzTabs);
        content += nextLine(anzTabs) + action;
    }
    if(model->source()){
        QString source("");
        sourceStateDecl(source,model->source()->name(),anzTabs);
        content += nextLine(anzTabs) + source;
    }
    if(model->target()){
        QString target("");
        targetStateDecl(target,model->target()->name(),anzTabs);
        content += nextLine(anzTabs) + target;
    }
}

void ComBuildTestCaseFile::refSignalDecl(QString &content, model::base::SignalItem *model, int anzTabs)
{
    content = QString("signal: ") + model->name() + QString(";");
}

void ComBuildTestCaseFile::refPortDecl(QString &content, model::base::SignalItem *model, int anzTabs)
{
    content = QString("port: ") + model->name() + QString(";");
}

void ComBuildTestCaseFile::entryActionDecl(QString &content, const QString &action, int anzTabs)
{
    content = QString("EntryAction: {") + nextLine(anzTabs+1) + action + QString(";") + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::exitActionDecl(QString &content, const QString &action, int anzTabs)
{
    content = QString("EntryAction: {") + nextLine(anzTabs+1) + action + QString(";") + nextLine(anzTabs) + QString("}");
}

void ComBuildTestCaseFile::sourceStateDecl(QString &content, const QString &source, int anzTabs)
{
    content = QString("sourceState: ") + source + QString(";");
}

void ComBuildTestCaseFile::targetStateDecl(QString &content, const QString &target, int anzTabs)
{
    content = QString("targetState: ") + target + QString(";");
}

void ComBuildTestCaseFile::nameDecl(QString &content, const QString &name, int anzTabs)
{
    content = QString("name: ") + name + QString(";");
}

void ComBuildTestCaseFile::commonDecl(QString &content, TestCaseItem *model, int i, int anzTabs)
{
    content = QString("");
    if(i<model->dataTypes().size()){
        if(!(model->dataTypes().at(i)->name() == QString("int") ||
             model->dataTypes().at(i)->name() == QString("real") ||
             model->dataTypes().at(i)->name() == QString("bool") ||
             model->dataTypes().at(i)->name() == QString("string"))){
            QString typeDefStr("");
            typeDefDecl(typeDefStr,model->dataTypes().at(i));
        }
    }
    else if (i < (model->dataTypes().size() + model->attributes().size())) {
        QString attributeStr("");
        attributeDecl(attributeStr, model->attributes().at(i-model->dataTypes().size()));
    }
    else if (i < (model->dataTypes().size() + model->attributes().size() + model->getSignals().size())) {
        QString signalStr("");
        signalDecl(signalStr, model->getSignals().at(i - model->dataTypes().size() - model->attributes().size()));
    }
}

void ComBuildTestCaseFile::portDecl(QString &content, const QString &port, int anzTabs)
{
    content = QString("port ") + port + QString(";");
}

void ComBuildTestCaseFile::paramDecl(QString &content, model::base::ParamItem *model, int anzTabs)
{
    typeDecl(content,model->dataType());
    content += QString(" ") + model->name();
}

void ComBuildTestCaseFile::typeDefDecl(QString &content, model::base::DataTypeItem *model, int anzTabs)
{
    QString typeDeclStr("");
    typeDecl(typeDeclStr,model);
    content = QString("type ") + typeDeclStr + QString(" ") + model->name() + QString(";");
}

void ComBuildTestCaseFile::typeDecl(QString &content, const model::base::DataTypeItem *model, int anzTabs)
{
    content = model->typeDeclString();
    //    switch(model->typeEnum()){
    //        case prop::Int:
    //            intTypeDecl(content,model);
    //        break;
    //        case prop::Real:
    //            realTypeDecl(content,model);
    //        break;
    //        case prop::Enum:
    //            enumTypeDecl(content,model);
    //        break;
    //        case prop::Bool:
    //            content = QString("bool");
    //        break;
    //        case prop::String:
    //            content = QString("string");
    //        break;
    //        default:
    //            content = model->typeDeclString();
    //        break;
    //    }
}

//void ComBuildTestCaseFile::intTypeDecl(QString &content, model::base::DataTypeItem *model)
//{
//    content = QString("int");
//}

//void ComBuildTestCaseFile::realTypeDecl(QString &content, model::base::DataTypeItem *model)
//{

//}

//void ComBuildTestCaseFile::enumTypeDecl(QString &content, model::base::DataTypeItem *model)
//{

//}

void ComBuildTestCaseFile::attributeDecl(QString &content, model::base::AttributeItem *model, int anzTabs)
{
    content = QString("Attribute ") + model->dataType()->typeDeclString() + QString(" ") + model->name() +
            (model->initValue()==QString("") ? QString("") : QString(" = ") + model->initValue()) +
            QString(";");
}

} // namespace testcase
} // namespace dslparser
