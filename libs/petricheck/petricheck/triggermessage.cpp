#include "triggermessage.h"
#include "triggermessageparam.h"

TriggerMessage::~TriggerMessage()
{
	// NOTE Needs to be tested so it doesn't crash
  std::map<QString, TriggerMessageParam*>::iterator it;
	for (it=params.begin(); it!=params.end(); ++it)
		delete it->second;
}

/** Add parameter to list. If a param with this name already exists, delete old one.
 */
void TriggerMessage::addParam(TriggerMessageParam *newParam)
{
	QString name = newParam->getName();
	if (params.count(name) > 0)
		delete params[name];
	params[name] = newParam;
	id += newParam->getId();
}

/** Check if there is a param with the given name and if the actual value matches.
 *  NOTE Nowhere implemented, yet...
 */
bool TriggerMessage::checkParam(const QString &paramName, const QString &actualVal)
{
  TriggerMessageParam *foundParam = findParam(paramName);
	if (foundParam)
	{	bool match = foundParam->checkParam(actualVal);
		return match;
	}
	else
		return false;
}

const QString &TriggerMessage::getName()
{
	return this->name;
}

const QString &TriggerMessage::getId()
{
	return this->id;
}

const std::map<QString, TriggerMessageParam *> &TriggerMessage::getParams()
{
	return this->params;
}

const QString &TriggerMessage::getSender()
{
	return this->sender;
}

const QString &TriggerMessage::getReceiver()
{
  return this->receiver;
}

/** If param with given name exists, return it, else return nullptr.
 */
TriggerMessageParam *TriggerMessage::findParam(const QString &paramName)
{
	if (params.count(paramName) > 0)
		return params[paramName];
	else
		return nullptr;
}
