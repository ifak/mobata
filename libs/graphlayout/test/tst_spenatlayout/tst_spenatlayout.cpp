#include <QtTest>

#include <graphlayout/comcreatedeclgraph.hpp>
#include <graphlayout/graphquickwidget.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/transitionitem.hpp>

#include <QQuickWidget>
#include <QQuickItem>

class SpenatLayoutTest
        : public QObject
{
    Q_OBJECT

public:
    SpenatLayoutTest();
private:
    model::spenat::SpenatDeclModel* _model;
    graphlayout::LayoutGraph* _graph;
    void initModel();
private Q_SLOTS:
    void initTestCase();
    void Seq1Test();
    void Seq2Test();
    void cleanupTestCase();
};

SpenatLayoutTest::SpenatLayoutTest()
{}

void SpenatLayoutTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
    this->initModel();
}

void SpenatLayoutTest::initModel(){
    QString errorString;

    this->_model = new model::spenat::SpenatDeclModel("exampleModel");

    model::spenat::PlaceItem* initPlace=this->_model->addPlace(QStringLiteral("init"));
    QVERIFY(initPlace);
    this->_model->addInitPlace(initPlace);

    model::spenat::PlaceItem* place_1=this->_model->addPlace(QStringLiteral("place_1"));
    QVERIFY(place_1);

    model::spenat::PlaceItem* place_2=this->_model->addPlace(QStringLiteral("place_2"));
    QVERIFY(place_2);

    model::spenat::PlaceItem* place_3=this->_model->addPlace(QStringLiteral("place_3"));
    QVERIFY(place_3);

    model::spenat::PlaceItem* place_4=this->_model->addPlace(QStringLiteral("place_4"));
    QVERIFY(place_4);

    model::spenat::TransitionItem* trans_1=new model::spenat::TransitionItem(QStringLiteral("start"),
                                               0,
                                               QStringLiteral("all zero"),
                                               QStringLiteral("do nothing"));
    this->_model->addTransition(trans_1);

    model::spenat::TransitionItem* trans_2=new model::spenat::TransitionItem(QStringLiteral("left"), 0);
    this->_model->addTransition(trans_2);

    model::spenat::TransitionItem* trans_3=new model::spenat::TransitionItem(QStringLiteral("right"), 0);
    this->_model->addTransition(trans_3);

    model::spenat::TransitionItem* trans_4=this->_model->addSignalTransition(QStringLiteral("reset"),
                                                      0, 0,
                                                      QStringLiteral(""),
                                                      QStringLiteral(""));

    trans_1->addPrePlaceArc(initPlace);
    trans_1->addPostPlaceArc(place_1);
    trans_1->addPostPlaceArc(place_2);

    trans_2->addPrePlaceArc(place_1);
    trans_2->addPostPlaceArc(place_3);

    trans_3->addPrePlaceArc(place_2);
    trans_3->addPostPlaceArc(place_4);

    trans_4->addPrePlaceArc(place_3);
    trans_4->addPrePlaceArc(place_4);
    trans_4->addPostPlaceArc(initPlace);

    QVERIFY(this->_model);
    QCOMPARE(errorString,QString(""));
}

void SpenatLayoutTest::Seq1Test(){
    this->_graph = new graphlayout::LayoutGraph("");
    graphlayout::ComCreateDeclGraph comGraph(this->_graph,this->_model);
    QString errorString;
    comGraph.execute(&errorString);
    QCOMPARE(errorString,QString(""));
    QCOMPARE(this->_graph->allNodes().length(),7);
    QCOMPARE(this->_graph->edges().length(),8);
}

void SpenatLayoutTest::Seq2Test(){
    graphlayout::GraphQuickWidget* graphwidget = new graphlayout::GraphQuickWidget(this->_graph,graphlayout::Fdp);
    QString errorString;
    graphwidget->layout(&errorString);
    QCOMPARE(errorString,QString(""));
    QVERIFY(graphwidget->rootObject()->findChild<QObject*>("drawArea"));
    QCOMPARE(graphwidget->rootObject()->findChildren<QObject*>("node").length(),7);
    QCOMPARE(graphwidget->rootObject()->findChildren<QObject*>("edge").length(),8);

    delete graphwidget;
}

void SpenatLayoutTest::cleanupTestCase(){
    delete this->_model;
    delete this->_graph;
}


QTEST_MAIN(SpenatLayoutTest)

#include "tst_spenatlayout.moc"
