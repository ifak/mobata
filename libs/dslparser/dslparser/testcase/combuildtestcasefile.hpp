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
#include "../dslparser_types.hpp"
#include "../dslerror.hpp"

#include <QObject>

namespace model{
namespace base {
class PortItem;
class SignalItem;
class ParamItem;
class DataTypeItem;
class AttributeItem;
}
namespace msc {
class MscSequenceItem;
class MscStatementItem;
}
namespace ts{
class TestCaseItem;
}}

namespace dslparser {
namespace testcase{

class DSLPARSERSHARED_EXPORT ComBuildTestCaseFile
        : public QObject
{
public:
    ComBuildTestCaseFile(QString& testcaseDocText,
                             model::ts::TestCaseItem* testcaseDeclModel,
                             QObject* parent =0);
    virtual ~ComBuildTestCaseFile();

public:
    virtual bool  execute(QString* errorString = 0);

public:
    const DslErrorList&  errors() const;

private:
    void testCaseDecl(QString& content,model::ts::TestCaseItem* model,int anzTabs = 0);
    void testCaseBody(QString& content,model::ts::TestCaseItem* model, int anzTabs = 0);
    void declarations(QString& content,model::ts::TestCaseItem* model, int anzTabs = 0);
    void signalDecl(QString& content,model::base::SignalItem* model, int anzTabs = 0);
    void stepsDecl(QString& content,QList<model::msc::MscSequenceItem const*> modelList, int anzTabs = 0);
    void assignmentDecl(QString& content,model::msc::MscStatementItem* model, int anzTabs = 0);
    void simpleStateBody(QString& content, model::testcase::AbstractStateItem *model, int anzTabs = 0);
    void junctionStateDecl(QString& content,model::testcase::JunctionStateItem* model, int anzTabs = 0);
//    void parallelStateDecl(QString& content,model::testcase::ParallelStateItem* model);
//    void parallelStateBody(QString& content,model::testcase::ParallelStateItem* model);
//    void parallelStateBodyOptional(QString& content,model::testcase::ParallelStateItem* model);
//    void regionDecl(QString& content);
    void regionBody(QString& content,model::testcase::AbstractStateItem* model, int anzTabs = 0);
    void compositeStateDecl(QString& content,model::testcase::CompositeStateItem* model, int anzTabs = 0);
    void finalStateDecl(QString& content,model::testcase::FinalStateItem* model, int anzTabs = 0);
    void initStateDecl(QString& content, const model::testcase::InitStateItem *model, int anzTabs = 0);
    void guardDecl(QString& content,const QString& guard, int anzTabs = 0);
//    void sendToStatement(QString& content,const QString& action, int anzTabs = 0);
    void actionDecl(QString& content,const QString& action, int anzTabs = 0);
    void transitionDecl(QString& content,model::testcase::TransitionItem* model, int anzTabs = 0);
    void signalTransitionDecl(QString& content,model::testcase::TransitionItem* model, int anzTabs = 0);
    void signalTransitionBody(QString& content,model::testcase::TransitionItem* model, int anzTabs = 0);
    void refSignalDecl(QString& content,model::base::SignalItem* model, int anzTabs = 0);
    void refPortDecl(QString& content,model::base::SignalItem* model, int anzTabs = 0);
    void entryActionDecl(QString& content,const QString& action, int anzTabs = 0);
    void exitActionDecl(QString& content,const QString& action, int anzTabs = 0);
    void sourceStateDecl(QString& content,const QString& source, int anzTabs = 0);
    void targetStateDecl(QString& content,const QString& target, int anzTabs = 0);
    void nameDecl(QString& content,const QString& name, int anzTabs = 0);
    void commonDecl(QString& content,model::ts::TestCaseItem* model,int i = 0, int anzTabs = 0);
    void portDecl(QString& content, const QString &port, int anzTabs = 0);
    void paramDecl(QString& content, model::base::ParamItem* model, int anzTabs = 0);

    void typeDefDecl(QString& content, model::base::DataTypeItem* model, int anzTabs = 0);
    void typeDecl(QString& content, const model::base::DataTypeItem *model, int anzTabs = 0);
//    void intTypeDecl(QString& content, model::base::DataTypeItem* model);
//    void realTypeDecl(QString& content, model::base::DataTypeItem* model);
//    void enumTypeDecl(QString& content, model::base::DataTypeItem* model);
    void attributeDecl(QString& content, model::base::AttributeItem* model, int anzTabs = 0);
    QString nextLine(int anzTabs){
        QString res("\n");
        for(int i = 0; i < anzTabs; i++){
            res += QString(" ");
        }
        return res;
    }

    Q_DISABLE_COPY(ComBuildTestCaseFile)
    class Private;
    Private* _d;
};

}//namespace testcase
} // namespace dslparser
