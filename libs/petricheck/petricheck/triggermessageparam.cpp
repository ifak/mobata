#include "triggermessageparam.h"

TriggerMessageParam::TriggerMessageParam(const QString &name,
                                         const model::base::CompOp &compOp,
                                         const QString &targetVal):
  name(name),
  targetVal(targetVal),
  compOp(compOp),
  actualVal("")
{
  saveId();
  saveLayerInfo();
}

QString const& TriggerMessageParam::getName()
{
  return name;
}

/** Check if param is correct: Compare target with actual value via comparison operator. But if
 *  param is not mandatory, this doesn't matter and check is always true. This is used to just save
 *  the value, e.g. to display it later.
 */
bool TriggerMessageParam::checkParam(const QString &actualVal)
{
  this->actualVal = actualVal;
  return compareValues(actualVal);
}

const QString &TriggerMessageParam::getId()
{
  return this->id;
}

const QString &TriggerMessageParam::getLayer()
{
  return this->layer;
}

QString TriggerMessageParam::getFieldName(const std::size_t pos)
{
  if (fieldNames.size() >= pos)
    return fieldNames[pos];
  else
    return "";
}

const QString &TriggerMessageParam::getTargetVal()
{
  return this->targetVal;
}

model::base::CompOp TriggerMessageParam::getCompOp()
{
  return this->compOp;
}

void TriggerMessageParam::setActualVal(const QString &actualVal)
{
  this->actualVal = actualVal;
}

const QString &TriggerMessageParam::getActualVal()
{
  return this->actualVal;
}

/** Create an identifier to quickly find this param (or it's parent signal) in a map.
 */
void TriggerMessageParam::saveId()
{
  QString compOpStr("");
  switch (compOp)
  {
    // NOTE A 'toStr' method would be good...
    case model::base::CompOp::Equals:
      compOpStr = "==";
      break;
    case model::base::CompOp::GrThan:
      compOpStr = ">";
      break;
    case model::base::CompOp::LeThan:
      compOpStr = "<";
      break;
    case model::base::CompOp::GrEquals:
      compOpStr = ">=";
      break;
    case model::base::CompOp::LeEquals:
      compOpStr = "<=";
      break;
    case model::base::CompOp::Not:
      compOpStr = "!";
      break;
    default:
      compOpStr = "==";
  }
  id = name + compOpStr + targetVal;
}

/** Compare actual value (read from network message) via comparison operator with target value
 *  (given via test case / DSL).
 */
bool TriggerMessageParam::compareValues(const QString &actualVal)
{
  switch (compOp)
  {
    case model::base::CompOp::Equals:
      return (actualVal == targetVal);
    case model::base::CompOp::GrEquals:
      // TODO
      return false;
    case model::base::CompOp::GrThan:
      // TODO
      return false;
    case model::base::CompOp::LeEquals:
      // TODO
      return false;
    case model::base::CompOp::LeThan:
      // TODO
      return false;
    case model::base::CompOp::Not:
      return (actualVal != targetVal);
    default:
      return false;
  }
}

/** The protocol handler saves dissected packet data with layer and field name. A data field could
 *  also be separated into several blocks. To prepare a comparison, assume a well defined param name
 *  and separate it into layer and fields.
 */
void TriggerMessageParam::saveLayerInfo()	// NOTE Add unit test
{
  const QString SEPARATOR = ".";
  int separatorPos = name.indexOf(SEPARATOR);
  if (separatorPos == -1)
    return;
  this->layer = name.left(separatorPos);

  QString rest = name.mid(separatorPos + SEPARATOR.size());
  separatorPos = rest.indexOf(SEPARATOR);

  while(separatorPos != -1)
  {	QString fieldName = rest.left(separatorPos);
    this->fieldNames.push_back(fieldName);
    rest = rest.mid(separatorPos + SEPARATOR.size());
  }
  this->fieldNames.push_back(rest);
}
