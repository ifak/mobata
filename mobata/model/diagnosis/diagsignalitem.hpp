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
#ifndef MODEL_DIAGNOSIS_DIAGSIGNALITEM_HPP
#define MODEL_DIAGNOSIS_DIAGSIGNALITEM_HPP

#include "../../mobata_global.hpp"

#include "../base/signalitem.hpp"

namespace model{
namespace diagnosis{

class MOBATASHARED_EXPORT DiagSignalItem
        : public base::SignalItem
{

public:
    DiagSignalItem(const QString& name=QLatin1String(""),
                   const QString necguard=QLatin1String(""),
                   const QString suffguard=QLatin1String(""),
                   const QUuid& uuid=QUuid::createUuid());
    void setBaseSignal(DiagSignalItem *baseSignal);
    DiagSignalItem *BaseSignal();
    QString condition();
    QString check();
    void addAlias(QString original, QString alias);
    QHash<QString,QString> aliases();
    virtual ~DiagSignalItem();
    ParameterSet params() const;
private:
    Q_DISABLE_COPY(DiagSignalItem)
    class Private;
    Private* _d;

    // ModelItem interface
public:
    QString toString() const;
};

}/// end namespace msc
}/// end namespace model

#endif // MODEL_DIAGNOSIS_DIAGSIGNALITEM_HPP
