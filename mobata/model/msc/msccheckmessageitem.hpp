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
#ifndef MODEL_MSC_MSCCHECKMESSAGEITEM_HPP
#define MODEL_MSC_MSCCHECKMESSAGEITEM_HPP

#include "mscmessageitem.hpp"

namespace model {
namespace msc {

class MscCheckMessageItem : public MscMessageItem
{
public:
  MscCheckMessageItem(PortItem const* sourcePort,
                      PortItem const* targetPort,
                      const QString& guard=QStringLiteral(""),
                      const int timeout = -1,
                      const double accuracy = 0.0);
  virtual ~MscCheckMessageItem();

public:
  virtual int     stepType() const { return CheckMessageStep;}
  virtual QString stepTypeString() const { return constants::CheckMessageStepId;}

public:
  const QString&  guard() const;
  void            setGuard(const QString& guard);
  int             timeout() const;
  void            setTimeout(const int timeout);
  double          accuracy() const;
  void            setAccuracy(const double accuracy);
  QHash<QString,QString> assign() const;
  void            appendAssign(QString attribute, QString signalParam);
  QString         toString() const;

private:
  Q_DISABLE_COPY(MscCheckMessageItem)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace model

#endif // MODEL_MSC_CHECKMESSAGEITEM_HPP
