#include <QString>
#include <QtTest>

#include <petrigenerator.hpp>
#include <QSharedPointer>


class PetriGeneration : public QObject
{
  Q_OBJECT

public:

private Q_SLOTS:
  void generateFromExampleSeq();
};

void PetriGeneration::generateFromExampleSeq()
{
  PetriGenerator petriGen;
  // NOTE Pass real MSC model instead of nullptr for test to succeed
//  QSharedPointer<model::spenat::SpenatModel> result = petriGen.generatePetriFromDiagSequence(nullptr);
//  QCOMPARE(result.isNull(), false);
}

QTEST_GUILESS_MAIN(PetriGeneration)

#include "tst_petrigeneration.moc"
