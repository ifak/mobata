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
#ifndef VIEW_MSC_MSCWEBSEQUCHARTCLIENT_HPP
#define VIEW_MSC_MSCWEBSEQUCHARTCLIENT_HPP

#include "../mobatawidgets_global.hpp"

#include <QObject>
#include <QNetworkReply>

namespace view{
namespace msc{

class MOBATAWIDGETSSHARED_EXPORT MscWebSequChartClient
    : public QObject
{
  Q_OBJECT

public:
  explicit MscWebSequChartClient(QNetworkAccessManager *networkManager,
                                 QObject *parent = 0);
  virtual ~MscWebSequChartClient();

public:
  void request(const QString &sequChartText);

signals:
  void error(const QString&);
  void result(const QPixmap&);

protected slots:
  void slotError(QNetworkReply::NetworkError networkError);
  void slotRequestFinished();
  void slotImageFinished();

protected:
  QNetworkAccessManager*	_networkManager;
  QNetworkReply*					_requestReply;
  QNetworkReply*					_imgReply;
};

}/// end namespace msc
}/// end namespace view

#endif // VIEW_MSC_MSCWEBSEQUCHARTCLIENT_HPP
