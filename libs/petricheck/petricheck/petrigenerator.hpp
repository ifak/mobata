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
#ifndef PETRIGENERATOR_HPP
#define PETRIGENERATOR_HPP

#include <mobata/model/msc/mscsequence.hpp>

#include <QSharedPointer>
#include <utility>        // std::pair

class MarkingHandler;
namespace model
{	namespace spenat
  {	class SpenatModel;
    class PlaceItem;
    class TransitionItem;
  }
  namespace diagnosis
  { class DiagnosisItem;
    class DiagnosisSequenceRuleItem;
  }
}
typedef std::pair<model::spenat::PlaceItem *, model::spenat::PlaceItem *> StartAndEndPlace;


class PetriGenerator
{
public:
  PetriGenerator();
  ~PetriGenerator();

public:
  model::spenat::SpenatModel *generatePetriFromDiagSequence(model::diagnosis::DiagnosisItem *diagModel);
  MarkingHandler *getMarkingHandler();

public:
  int parsedActionId;
  // test

private:
  void processSignalDeclarations(model::diagnosis::DiagnosisSequenceRuleItem* rule);
  void processComponentDeclarations(model::diagnosis::DiagnosisSequenceRuleItem* rule);
  StartAndEndPlace preparePetriNet();
  void createIntermediatePlaces(int seqItemListSize, QVector<model::spenat::PlaceItem *> *places);
  QString getUniquePlaceName(const QString &baseName);
  void processMscLevelNew(const model::msc::MscSequence::ConstSequenceItems &seqItemList, QVector<model::spenat::PlaceItem *> *places);
  model::spenat::TransitionItem *processMsg(model::msc::MscCheckMessageItem const* msgItem, model::spenat::PlaceItem* prevPlace, model::spenat::PlaceItem* nextPlace);
  QString getUniqueTransName(const QString &baseName);

private:
  struct Private;
  Private* _d;   // opaque pointer
};

#endif // PETRIGENERATOR_HPP
