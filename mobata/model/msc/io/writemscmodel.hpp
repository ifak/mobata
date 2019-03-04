/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "../msc_types.hpp"

class QJsonObject;
class QJsonArray;

namespace model {
namespace msc {
namespace io {

///write objects//////////

void writeMscModel(MscModel const* mscModel,
                   QJsonObject& jsonObject);

void writeMscComponent(MscComponentItem const* mscComponent,
                       QJsonObject& jsonObject);

void writeMscSequence(MscSequence const* mscSequence,
                      QJsonObject& jsonObject);

void writeMscStepsArray(MscSequence const* mscSequence,
                        QJsonArray& jsonStepsArray);

void writeMscMessage(MscMessageItem const* mscMessage,
                     QJsonObject& jsonObject);

void writeMscCheckMessage(MscCheckMessageItem const* mscCheckMessage,
                          QJsonObject& jsonObject);

void writeMscStatement(MscStatementItem const* mscStatement,
                       QJsonObject& jsonObject);

void writeMscTimeout(MscTimeoutItem const* mscTimeoutItem,
                     QJsonObject& jsonObject);

void writeMscTimer(MscTimerItem const* mscTimerItem,
                   QJsonObject& jsonObject);

void writeMscSleepTimer(MscSleepTimerItem const* mscSleepTimerItem,
                        QJsonObject& jsonObject);

void writeMscFragment(MscFragmentItem const* mscFragmentItem,
                      QJsonObject& jsonObject);

void writeMscFragmentRegion(MscFragmentRegionItem const* mscFragmentRegion,
                            QJsonObject& jsonObject);

} // namespace io
} // namespace msc
} // namespace model
