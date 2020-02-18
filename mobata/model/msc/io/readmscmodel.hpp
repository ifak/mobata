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
#ifndef MODEL_MSC_IO_READMSCMODEL_HPP
#define MODEL_MSC_IO_READMSCMODEL_HPP

#include "../msc_types.hpp"

class QJsonObject;
class QJsonArray;

namespace model {
namespace msc {
namespace io {

///read objects//////////
bool readMscModel(const QJsonObject& jsonObject,
                  MscModel* mscModel,
                  QString* errorMessage);

template<class MscComponentsModel>
struct ReadMscComponent
{
  bool operator() (const QJsonObject& jsonObject,
                   MscComponentsModel* componentsModel,
                   QString* errorMessage);
};

template<class MscSequencseModel>
bool readMscSequences(const QJsonObject& jsonObject,
                      MscSequencseModel* sequenceModel,
                      QString* errorMessage);

template<class MscSequencseModel, class ReadMscSequenceFunctor>
bool readMscSequences(const QJsonObject& jsonObject,
                      MscSequencseModel* sequenceModel,
                      ReadMscSequenceFunctor readMscSequenceFunctor,
                      QString* errorMessage);

template<class MscSequencseModel>
struct ReadMscSequence
{
  bool operator()(const QJsonObject& jsonObject,
                  MscSequencseModel* sequenceModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
bool readMscSteps(const QJsonObject& jsonObject,
                  SystemModel* systemModel,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);

template<class MscStepsModel, class ReadMscStepFunctor>
bool readMscSteps(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  ReadMscStepFunctor readMscStepFunctor,
                  QString* errorMessage);

template<class SystemModel, class MscStepsModel>
struct ReadMscStep
{
  SystemModel* _systemModel;

  ReadMscStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadMessageStep
{
  SystemModel* _systemModel;

  ReadMessageStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadCheckMessageStep
{
  SystemModel* _systemModel;

  ReadCheckMessageStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadStatementStep
{
  SystemModel* _systemModel;

  ReadStatementStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadTimeoutStep
{
  SystemModel* _systemModel;

  ReadTimeoutStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadTimerStep
{
  SystemModel* _systemModel;

  ReadTimerStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadSleepTimerStep
{
  SystemModel* _systemModel;

  ReadSleepTimerStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscStepsModel>
struct ReadFragmentStep
{
  SystemModel* _systemModel;

  ReadFragmentStep(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage);
};

template<class SystemModel, class MscFragmentModel>
bool readMscRegions(const QJsonObject& jsonObject,
                  SystemModel* systemModel,
                  MscFragmentModel* mscFragmentModel,
                  QString* errorMessage);

template<class MscFragmentModel, class ReadMscFragmentFunctor>
bool readMscRegions(const QJsonObject& jsonObject,
                  MscFragmentModel* mscFragmentModel,
                  ReadMscFragmentFunctor readMscFragmentFunctor,
                  QString* errorMessage);

template<class SystemModel, class MscFragmentModel>
struct ReadFragmentRegion
{
  SystemModel* _systemModel;

  ReadFragmentRegion(SystemModel* systemModel)
    : _systemModel(systemModel)
  {Q_ASSERT(this->_systemModel);}

  bool operator()(const QJsonObject& jsonObject,
                  MscFragmentModel* mscFragmentModel,
                  QString* errorMessage);
};

} // namespace io
} // namespace msc
} // namespace model

#include "readmscmodel.inl"

#endif // MODEL_MSC_IO_WRITEMSCMODEL_HPP
