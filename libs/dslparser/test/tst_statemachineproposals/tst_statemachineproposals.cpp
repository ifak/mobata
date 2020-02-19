#include <QtTest>

#include <dslparser/diagnosis/comcreatediagnosisproposals.hpp>
#include <dslparser/diagnosis/combuilddiagnosismodel.hpp>

#include <mobata/model/diagnosis/diagnosisitem.hpp>

using namespace dslparser;
using namespace dslparser::diagnosis;
using namespace model::diagnosis;

class diagnosisProposalsTest
        : public QObject
{
    Q_OBJECT

public:
    diagnosisProposalsTest();

private Q_SLOTS:
    void initTest();
    void cleanupTest();
    void DiagnosisProposalEmptyTextTest_1();
    void DiagnosisProposalTest_1();
    void DiagnosisProposalTest_2();
    void DiagnosisProposalTest_2_1();
    void DiagnosisProposalTest_3();
    void DiagnosisProposalTest_4();
    void DiagnosisProposalTest_5();
    void DiagnosisProposalTest_6();
    void DiagnosisProposalTest_7();
    void DiagnosisProposalTest_8();
    void DiagnosisProposalTest_9();
    void DiagnosisProposalTest_10();
    void DiagnosisProposalTest_11();
    void DiagnosisProposalTest_12();
    void DiagnosisProposalTest_13();
    void DiagnosisProposalTest_14();
    void DiagnosisProposalTest_15();
    void DiagnosisProposalTest_16();
    void DiagnosisProposalTest_17();
    void includeDiagnosisProposalTest1();
    void includeDiagnosisProposalTest2();
    void includeDiagnosisProposalTest3();
    void includeDiagnosisProposalTest4();
    void includeDiagnosisProposalErrorTest();
    void DiagnosisProposalAfterCommentTest_1();
    void DiagnosisProposalAfterCommentTest_2();
    void DiagnosisProposalAfterCommentTest_3();
    void DiagnosisProposalAfterCommentTest_4();
    void DiagnosisProposalWithinCommentTest_1();
    void DiagnosisProposalWithinCommentTest_2();
};

diagnosisProposalsTest::diagnosisProposalsTest()
{}

void diagnosisProposalsTest::initTest()
{}

void diagnosisProposalsTest::cleanupTest()
{}

void diagnosisProposalsTest::DiagnosisProposalEmptyTextTest_1()
{
    QString docText("");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
//    QCOMPARE(2, command.diagnosisProposals().count());

//    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
//    QCOMPARE(QString("Rule"), firstProposal.proposalText);
//    QCOMPARE((int)Diagnosis, firstProposal.proposalType);

//    DiagnosisProposal secProposal = command.diagnosisProposals().at(1);
//    QCOMPARE(QString("import"), secProposal.proposalText);
//    QCOMPARE((int)Import, secProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_1()
{
    QString docText(L'\u2029');
    docText+=" ";
    docText+=QChar(L'\u2029');
    docText+=" ";

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(/*2*/0, command.diagnosisProposals().count());

//    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
//    QCOMPARE(QString("Rule"), firstProposal.proposalText);
//    QCOMPARE((int)Diagnosis, firstProposal.proposalType);

//    DiagnosisProposal secProposal = command.diagnosisProposals().at(1);
//    QCOMPARE(QString("import"), secProposal.proposalText);
//    QCOMPARE((int)Import, secProposal.proposalType);
    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_2()
{
    QString docText(L'\u2029');
    docText+=" ";
    docText+=QChar(L'\u2029');
    docText+=" Rule";

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("{"), firstProposal.proposalText);
    QCOMPARE((int)LeftBrace, firstProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_2_1()
{
    QString docText("Rule");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("{"), firstProposal.proposalText);
    QCOMPARE((int)LeftBrace, firstProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_3()
{
    QString docText("Rule{");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("name"), firstProposal.proposalText);
    QCOMPARE((int)Name, firstProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_4()
{
    QString docText("Rule{name");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal firstProposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString(":"), firstProposal.proposalText);
    QCOMPARE((int)Colon, firstProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_5()
{
    QString docText("Rule{Declaration{name:");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.diagnosisProposals().count());

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_6()
{
    QString docText("Rule{name:mydiagnosis; description:\"test\";enabled:true;Declaration{");

    ComCreateDiagnosisProposals command(docText);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(5, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("Attribute"), proposal.proposalText);
    QCOMPARE((int)Attribute, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("Component"), proposal.proposalText);
    QCOMPARE((int)Component, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("Signal"), proposal.proposalText);
    QCOMPARE((int)Signal, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("use"), proposal.proposalText);
    QCOMPARE((int)Use, proposal.proposalType);

    proposal = command.diagnosisProposals().at(4);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_7()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_1.rule";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(4, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("Loop"), proposal.proposalText);
    QCOMPARE((int)Loop, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("Message"), proposal.proposalText);
    QCOMPARE((int)Message, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("Parallel"), proposal.proposalText);
    QCOMPARE((int)Parallel, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_8()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_2.rule";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(4, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("Loop"), proposal.proposalText);
    QCOMPARE((int)Loop, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("Message"), proposal.proposalText);
    QCOMPARE((int)Message, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("Parallel"), proposal.proposalText);
    QCOMPARE((int)Parallel, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_9()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_3.rule";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("data"), proposal.proposalText);
    QCOMPARE((int)Data, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("from"), proposal.proposalText);
    QCOMPARE((int)From, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("to"), proposal.proposalText);
    QCOMPARE((int)To, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_10()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_4.rule";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(5, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("TimeOut"), proposal.proposalText);
    QCOMPARE((int)Timeout, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("from"), proposal.proposalText);
    QCOMPARE((int)From, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("result"), proposal.proposalText);
    QCOMPARE((int)Result, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("to"), proposal.proposalText);
    QCOMPARE((int)To, proposal.proposalType);

    proposal = command.diagnosisProposals().at(4);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_11()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_5.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(11, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("!"), proposal.proposalText);
    QCOMPARE((int)Not, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("&&"), proposal.proposalText);
    QCOMPARE((int)And, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString(")"), proposal.proposalText);
    QCOMPARE((int)RightParen, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString(","), proposal.proposalText);
    QCOMPARE((int)Comma, proposal.proposalType);

    proposal = command.diagnosisProposals().at(4);
    QCOMPARE(QString("<"), proposal.proposalText);
    QCOMPARE((int)LessThan, proposal.proposalType);

    proposal = command.diagnosisProposals().at(5);
    QCOMPARE(QString("="), proposal.proposalText);
    QCOMPARE((int)Assign, proposal.proposalType);

    proposal = command.diagnosisProposals().at(6);
    QCOMPARE(QString(">"), proposal.proposalText);
    QCOMPARE((int)GreaterThan, proposal.proposalType);

    proposal = command.diagnosisProposals().at(7);
    QCOMPARE(QString("and"), proposal.proposalText);
    QCOMPARE((int)And, proposal.proposalType);

    proposal = command.diagnosisProposals().at(8);
    QCOMPARE(QString("not"), proposal.proposalText);
    QCOMPARE((int)Not, proposal.proposalType);

    proposal = command.diagnosisProposals().at(9);
    QCOMPARE(QString("or"), proposal.proposalText);
    QCOMPARE((int)Or, proposal.proposalType);

    proposal = command.diagnosisProposals().at(10);
    QCOMPARE(QString("||"), proposal.proposalText);
    QCOMPARE((int)Or, proposal.proposalType);
    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_12()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_6.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(2, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("."), proposal.proposalText);
    QCOMPARE((int)Dot, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString(";"), proposal.proposalText);
    QCOMPARE((int)Semi, proposal.proposalType);
    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_13()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_7.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(2, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("RSE_App"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("sut_comp_2"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_14()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_8.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(6, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("device_1"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("response"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("stimuli"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(4);
    QCOMPARE(QString("testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(5);
    QCOMPARE(QString("winmodVar"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_15()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_9.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(4, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("."), proposal.proposalText);
    QCOMPARE((int)Dot, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString(";"), proposal.proposalText);
    QCOMPARE((int)Semi, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("="), proposal.proposalText);
    QCOMPARE((int)Assign, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("sage"), proposal.proposalText);
    QCOMPARE((int)Message, proposal.proposalType);
    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_16()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_10.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString(":"), proposal.proposalText);
    QCOMPARE((int)Colon, proposal.proposalType);
    return;
}

void diagnosisProposalsTest::DiagnosisProposalTest_17()
{
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis_11.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    ComCreateDiagnosisProposals command(docText,praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(7, command.diagnosisProposals().count());

    DiagnosisProposal proposal = command.diagnosisProposals().at(0);
    QCOMPARE(QString("check1"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(1);
    QCOMPARE(QString("device_1"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(2);
    QCOMPARE(QString("response"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(3);
    QCOMPARE(QString("stimuli"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(4);
    QCOMPARE(QString("sut"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(5);
    QCOMPARE(QString("testsystem"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);

    proposal = command.diagnosisProposals().at(6);
    QCOMPARE(QString("winmodVar"), proposal.proposalText);
    QCOMPARE((int)Identifier, proposal.proposalType);
    return;
}

void diagnosisProposalsTest::includeDiagnosisProposalTest1(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example2.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();

    ComCreateDiagnosisProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(17,propCommand.diagnosisProposals().size());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(2);
    QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(3);
    QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(4);
    QCOMPARE(QString("example_diagnosis_1.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(5);
    QCOMPARE(QString("example_diagnosis_10.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(6);
    QCOMPARE(QString("example_diagnosis_11.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(7);
    QCOMPARE(QString("example_diagnosis_2.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(8);
    QCOMPARE(QString("example_diagnosis_3.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(9);
    QCOMPARE(QString("example_diagnosis_4.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(10);
    QCOMPARE(QString("example_diagnosis_5.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(11);
    QCOMPARE(QString("example_diagnosis_6.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(12);
    QCOMPARE(QString("example_diagnosis_7.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(13);
    QCOMPARE(QString("example_diagnosis_8.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(14);
    QCOMPARE(QString("example_diagnosis_9.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(15);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(16);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void diagnosisProposalsTest::includeDiagnosisProposalTest2(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example3.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();

    ComCreateDiagnosisProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(8,propCommand.diagnosisProposals().size());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("example2.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(2);
    QCOMPARE(QString("example3.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(3);
    QCOMPARE(QString("example4.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(4);
    QCOMPARE(QString("example5.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(5);
    QCOMPARE(QString("sutExample2.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(6);
    QCOMPARE(QString("sutExample3.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(7);
    QCOMPARE(QString("sutExample4.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void diagnosisProposalsTest::includeDiagnosisProposalTest3(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "testpath/example4.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();

    ComCreateDiagnosisProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(4,propCommand.diagnosisProposals().size());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("2.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(2);
    QCOMPARE(QString("3.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(3);
    QCOMPARE(QString("4.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void diagnosisProposalsTest::includeDiagnosisProposalTest4(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/../");

    ComCreateDiagnosisProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(17,propCommand.diagnosisProposals().size());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("example1.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(2);
    QCOMPARE(QString("example1_2.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(3);
    QCOMPARE(QString("example1_3.testsystem"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(4);
    QCOMPARE(QString("example_diagnosis_1.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(5);
    QCOMPARE(QString("example_diagnosis_10.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(6);
    QCOMPARE(QString("example_diagnosis_11.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(7);
    QCOMPARE(QString("example_diagnosis_2.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(8);
    QCOMPARE(QString("example_diagnosis_3.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(9);
    QCOMPARE(QString("example_diagnosis_4.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(10);
    QCOMPARE(QString("example_diagnosis_5.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(11);
    QCOMPARE(QString("example_diagnosis_6.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(12);
    QCOMPARE(QString("example_diagnosis_7.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(13);
    QCOMPARE(QString("example_diagnosis_8.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(14);
    QCOMPARE(QString("example_diagnosis_9.diagnosis"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(15);
    QCOMPARE(QString("sutExample.sut"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(16);
    QCOMPARE(QString("testpath"), proposal.proposalText);
    QCOMPARE((int)RefSignal, proposal.proposalType);
}

void diagnosisProposalsTest::includeDiagnosisProposalErrorTest(){
    QString praefix = ":/Examples/";
    QString docText("import <testpath/huivva/");

    ComCreateDiagnosisProposals propCommand(docText,praefix);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(1,propCommand.diagnosisProposals().size());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString(".."), proposal.proposalText);
    QCOMPARE((int)Range, proposal.proposalType);
}

void diagnosisProposalsTest::DiagnosisProposalAfterCommentTest_1()
{
    QString docText("\n diagnosis{\n Declaration{ name: mydiagnosis;\n\n /*comment*/ ");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(7, propCommand.diagnosisProposals().count());

    DiagnosisProposal proposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString("Attribute"), proposal.proposalText);
    QCOMPARE((int)Attribute, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("Check"), proposal.proposalText);
    QCOMPARE((int)Check, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(2);
    QCOMPARE(QString("Component"), proposal.proposalText);
    QCOMPARE((int)Component, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(3);
    QCOMPARE(QString("Signal"), proposal.proposalText);
    QCOMPARE((int)Signal, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(4);
    QCOMPARE(QString("enabled"), proposal.proposalText);
    QCOMPARE((int)Enabled, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(5);
    QCOMPARE(QString("name"), proposal.proposalText);
    QCOMPARE((int)Name, proposal.proposalType);

    proposal = propCommand.diagnosisProposals().at(6);
    QCOMPARE(QString("}"), proposal.proposalText);
    QCOMPARE((int)RightBrace, proposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalAfterCommentTest_2()
{
    QString docText("/*it has to start with diagnosis */");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(2, propCommand.diagnosisProposals().count());

    DiagnosisProposal firstProposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString("Rule"), firstProposal.proposalText);
    QCOMPARE((int)Diagnosis, firstProposal.proposalType);

    DiagnosisProposal secProposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("import"), secProposal.proposalText);
    QCOMPARE((int)Import, secProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalAfterCommentTest_3()
{
    QString docText("/*it has to start with 'diagnosis' */");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(2, propCommand.diagnosisProposals().count());

    DiagnosisProposal firstProposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString("Rule"), firstProposal.proposalText);
    QCOMPARE((int)Diagnosis, firstProposal.proposalType);

    DiagnosisProposal secProposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("import"), secProposal.proposalText);
    QCOMPARE((int)Import, secProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalAfterCommentTest_4()
{
    QString docText("/*it has to start with \"Rule\" */");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(2, propCommand.diagnosisProposals().count());

    DiagnosisProposal firstProposal = propCommand.diagnosisProposals().at(0);
    QCOMPARE(QString("Rule"), firstProposal.proposalText);
    QCOMPARE((int)Diagnosis, firstProposal.proposalType);

    DiagnosisProposal secProposal = propCommand.diagnosisProposals().at(1);
    QCOMPARE(QString("import"), secProposal.proposalText);
    QCOMPARE((int)Import, secProposal.proposalType);

    return;
}

void diagnosisProposalsTest::DiagnosisProposalWithinCommentTest_1()
{
    QString docText("\n diagnosis{\n Declaration{name: mydiagnosis;\n\n //comment  ");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(0, propCommand.diagnosisProposals().count());

    return;
}

void diagnosisProposalsTest::DiagnosisProposalWithinCommentTest_2()
{
    QString docText("\n diagnosis{\n name: mydiagnosis;\n\n /*comment \n further comment \n ");

    ComCreateDiagnosisProposals propCommand(docText);
    QString errorString;
    bool result = propCommand.execute(&errorString);
    QCOMPARE(result, true);
    qDebug()<<"errorString: "<<errorString;
    QCOMPARE(0, propCommand.diagnosisProposals().count());

    return;
}

QTEST_APPLESS_MAIN(diagnosisProposalsTest)

#include "tst_statemachineproposals.moc"
