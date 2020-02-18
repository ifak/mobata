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

#include "../base/modelitem.hpp"
#include "../base/propdatatypes.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"
#include "../../prop/nameproperty.hpp"

#include "diagcomponentitem.hpp"

namespace model{

namespace diagnosis{

class DiagnosisItem
    : public base::ModelItem,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals,
    public prop::NameProperty
{
public:
  DiagnosisItem(const QString name=QStringLiteral("diagnosis"));
  virtual ~DiagnosisItem();

public:
  virtual void                      reset();
  const QList<base::ModelItem *>&   rules();
  void                              addRule(base::ModelItem* rule);
  const QList<DiagnosisItem*>&      importItems();
  void                              addImportItem(DiagnosisItem* item);
  void                              addComponent(DiagComponentItem* item);
  const QList<DiagComponentItem*>&  components();

private:
  Q_DISABLE_COPY(DiagnosisItem)
  class Private;
  Private*  _d;
};

}///end namespace diagnosis
}/// end namespace model
