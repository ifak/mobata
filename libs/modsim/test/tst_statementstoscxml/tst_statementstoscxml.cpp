#include <QtTest>

#include <mobata/model/base/statements/rootstatementmodel.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/base/functionitem.hpp>

#include <dslparser/statemachine/combuildstatemachinemodel.hpp>
#include <dslparser/statement/combuildstatementmodel.hpp>

class StatementsToScxmlTest
    : public QObject
{
  Q_OBJECT

public:
  StatementsToScxmlTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleScxmlStatementTest_1();
  void simpleScxmlStatementTest_2();
  void simpleScxmlStatementTest_3();
  void simpleScxmlStatementTest_4();
  void simpleScxmlStatementTest_5();
  void simpleScxmlStatementTest_6();
  void simpleScxmlStatementTest_7();
  void simpleScxmlStatementTest_8();
  void simpleScxmlStatementTest_9();
};

QString domElementToRawXML(const QDomElement& elem)
{
    QString head = "<"+elem.tagName();
    QDomNamedNodeMap attrs = elem.attributes();
    for(int i = 0; i<attrs.size(); ++i)
    {
        QDomAttr attr = attrs.item(i).toAttr();
        head +=
            QString::fromLatin1(" %0=\"%1\"")
            .arg(attr.name())
            .arg(attr.value());
    }
    head += ">";
    return head + elem.text() + "</"+elem.tagName()+">";
}

StatementsToScxmlTest::StatementsToScxmlTest()
{}

void StatementsToScxmlTest::initTest()
{}

void StatementsToScxmlTest::cleanupTest()
{}

void StatementsToScxmlTest::simpleScxmlStatementTest_1()
{
  QString docText("attribute1 = 1;");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  wholeModel.addAttribute(QString("attribute1"),QString("int"),QString("0"));
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QString str;
  QTextStream stream(&str);
  scxmlDoc.save(stream,2);
  bool test = true;
  test = QString("  <root>\n"
                 "    <assign expr=\"1\" location=\"attribute1\"/>\n"
                 "  </root>\n") == str ||
         QString("  <root>\n"
                       "    <assign location=\"attribute1\" expr=\"1\"/>\n"
                       "  </root>\n") == str;
  QVERIFY(test);
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_2()
{
  QString docText("testFunction(1,2);");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::FunctionItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  wholeModel.addFunction(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QString str;
  QTextStream stream(&str);
  scxmlDoc.save(stream,2);
  QCOMPARE(QString("  <root>\n"
                   "    <script>testFunction(1,2);</script>\n"
                   "  </root>\n"), str);
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_3()
{
  QString docText("send testFunction(1,2);");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::SignalItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  wholeModel.addSignal(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QCOMPARE(1,scxmlDoc.childNodes().size());
  auto sendnode = scxmlDoc.childNodes().at(0);
  QCOMPARE(QString("send"),sendnode.toElement().tagName());

  QCOMPARE(QString("testFunction"),sendnode.toElement().attribute(QString("event")));
  QCOMPARE(2,sendnode.childNodes().size());
  auto param1node = sendnode.childNodes().at(0);
  if(QString("test1") == param1node.toElement().attribute(QString("name"))){
    QCOMPARE(QString("1"),param1node.toElement().attribute(QString("expr")));
    auto param2node = sendnode.childNodes().at(1);
    QCOMPARE(QString("test2"),param2node.toElement().attribute(QString("name")));
    QCOMPARE(QString("2"),param2node.toElement().attribute(QString("expr")));
  }
  else{
    QCOMPARE(QString("test2"),param1node.toElement().attribute(QString("name")));
    QCOMPARE(QString("2"),param1node.toElement().attribute(QString("expr")));
    auto param2node = sendnode.childNodes().at(1);
    QCOMPARE(QString("test1"),param2node.toElement().attribute(QString("name")));
    QCOMPARE(QString("1"),param2node.toElement().attribute(QString("expr")));
  }
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_4()
{
  QString docText("send testFunction(1,2) to port1;");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::SignalItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  model::base::PortItem portItem(QString("port1"));
  wholeModel.addPort(&portItem);
  wholeModel.addSignal(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QCOMPARE(1,scxmlDoc.childNodes().size());
  auto sendnode = scxmlDoc.childNodes().at(0);
  QCOMPARE(QString("send"),sendnode.toElement().tagName());

  QCOMPARE(QString("testFunction"),sendnode.toElement().attribute(QString("event")));
  QCOMPARE(3,sendnode.childNodes().size());
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_5()
{
  QString docText("if(true) send testFunction(1,2) to port1;");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::SignalItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  model::base::PortItem portItem(QString("port1"));
  wholeModel.addPort(&portItem);
  wholeModel.addSignal(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QCOMPARE(1,scxmlDoc.childNodes().size());
  auto ifnode = scxmlDoc.childNodes().at(0);
  QCOMPARE(QString("if"),ifnode.toElement().tagName());
  QCOMPARE(QString("true"),ifnode.toElement().attribute(QString("cond")));
  QCOMPARE(1,ifnode.childNodes().size());
  auto sendnode = ifnode.childNodes().at(0);
  QCOMPARE(QString("send"),sendnode.toElement().tagName());

  QCOMPARE(QString("testFunction"),sendnode.toElement().attribute(QString("event")));
  QCOMPARE(3,sendnode.childNodes().size());
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_6()
{
  QString docText("if(true);"
                  "else send testFunction(1,2) to port1;");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::SignalItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  model::base::PortItem portItem(QString("port1"));
  wholeModel.addPort(&portItem);
  wholeModel.addSignal(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QCOMPARE(1,scxmlDoc.childNodes().size());
  auto ifnode = scxmlDoc.childNodes().at(0);
  QCOMPARE(QString("if"),ifnode.toElement().tagName());
  QCOMPARE(QString("true"),ifnode.toElement().attribute(QString("cond")));

  QCOMPARE(1,ifnode.childNodes().size());
  auto elsenode = ifnode.childNodes().at(0);
  QCOMPARE(QString("else"),elsenode.toElement().tagName());

  QCOMPARE(1,elsenode.childNodes().size());
  auto sendnode = elsenode.childNodes().at(0);
  QCOMPARE(QString("send"),sendnode.toElement().tagName());

  QCOMPARE(QString("testFunction"),sendnode.toElement().attribute(QString("event")));
  QCOMPARE(3,sendnode.childNodes().size());
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_7()
{
  QString docText("if(true);"
                  "else if (false) send testFunction(1,2) to port1;");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::SignalItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  model::base::PortItem portItem(QString("port1"));
  wholeModel.addPort(&portItem);
  wholeModel.addSignal(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QString str;
  QTextStream stream(&str);
  scxmlDoc.save(stream,2);

  QCOMPARE(1,scxmlDoc.childNodes().size());
  auto ifnode = scxmlDoc.childNodes().at(0);
  QCOMPARE(QString("if"),ifnode.toElement().tagName());
  QCOMPARE(QString("true"),ifnode.toElement().attribute(QString("cond")));

  QCOMPARE(1,ifnode.childNodes().size());
  auto elsenode = ifnode.childNodes().at(0);
  QCOMPARE(QString("else"),elsenode.toElement().tagName());

  QCOMPARE(1,elsenode.childNodes().size());
  auto elseifnode = elsenode.childNodes().at(0);
  QCOMPARE(QString("if"),elseifnode.toElement().tagName());
  QCOMPARE(QString("false"),elseifnode.toElement().attribute(QString("cond")));

  QCOMPARE(1,elseifnode.childNodes().size());
  auto sendnode = elseifnode.childNodes().at(0);
  QCOMPARE(QString("send"),sendnode.toElement().tagName());

  QCOMPARE(QString("testFunction"),sendnode.toElement().attribute(QString("event")));
  QCOMPARE(3,sendnode.childNodes().size());
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_8()
{
  QString docText("switch(test){\n"
                  "case 1:testFunction(1,2);\n"
                  "}");
  QDomDocument doc;
  model::statemachine::StateMachineModel wholeModel;
  model::base::FunctionItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  wholeModel.addFunction(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  auto scxmlDoc = statementModel.scxmlElement(doc);

  QString str;
  QTextStream stream(&str);
  scxmlDoc.save(stream,2);
  QCOMPARE(QString("  <root>\n"
                   "    <script>switch(test){\n"
                                "case 1:testFunction(1,2);\n"
                                "}"
                       "</script>\n"
                   "  </root>\n"), str);
  return;
}

void StatementsToScxmlTest::simpleScxmlStatementTest_9()
{
  QString docText("switch(test){\n"
                  "case 1: { send testFunction(1,2);}\n"
                  "}");
  model::statemachine::StateMachineModel wholeModel;
  model::base::FunctionItem item(QString("testFunction"));
  item.addParameter(QString("test1"),QString("int"));
  item.addParameter(QString("test2"),QString("int"));
  wholeModel.addFunction(&item);
  model::base::statement::RootStatementModel statementModel;
  dslparser::base::ComBuildStatementModel command(docText, &wholeModel, &statementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());

  return;
}

QTEST_GUILESS_MAIN(StatementsToScxmlTest)

#include "tst_statementstoscxml.moc"
