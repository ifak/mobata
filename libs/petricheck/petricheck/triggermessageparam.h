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
#ifndef TRIGGERMESSAGEPARAM_H
#define TRIGGERMESSAGEPARAM_H

#include <mobata/model/base/base_types.hpp>

#include <QString>
#include <vector>

/** Defines a single parameter for a TriggerMessage instance (with several params). A target value can
 *  be compared to an actual value during runtime.
 */
class TriggerMessageParam
{
public:
  TriggerMessageParam(const QString &name, model::base::CompOp const& compOp, const QString &targetVal);
	const QString &getName();
	bool checkParam(const QString &actualVal);
	const QString &getId();
	const QString &getLayer();
    QString getFieldName(const std::size_t pos);
	const QString &getTargetVal();
    model::base::CompOp getCompOp();
	void setActualVal(const QString &actualVal);
	const QString &getActualVal();

private:
  void saveId();
  bool compareValues(const QString &actualVal);
  void saveLayerInfo();

private:
  QString name;
  QString targetVal;
  model::base::CompOp compOp;
  QString actualVal;
  QString id;
  QString layer;
  std::vector<QString> fieldNames;
};

#endif // TRIGGERMESSAGEPARAM_H
