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
#ifndef TRIGGERMESSAGE_H
#define TRIGGERMESSAGE_H

#include <QString>
#include <map>

class TriggerMessageParam;

/** Defines an event of a distributed system - e.g. a network message. Consists of several
 *  parameters with name and target value that can be compared to an actual value during runtime.
 */
class TriggerMessage
{
public:
  TriggerMessage(const QString &name):
		name(name),
		sender("N/A"),
		receiver("N/A"),
		id("") {}
  ~TriggerMessage();
  void addParam(TriggerMessageParam *newParam);
	bool checkParam(const QString &paramName, const QString &actualVal);
	const QString &getName();
	const QString &getId();
  const std::map<QString, TriggerMessageParam *> &getParams();
	const QString &getSender();
	const QString &getReceiver();

private:
  TriggerMessageParam *findParam(const QString &paramName);

private:
	QString name;
  std::map<QString, TriggerMessageParam*> params;
	QString sender;
	QString receiver;
	QString id;
};

#endif // TRIGGERMESSAGE_H
