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
#ifndef VIEW_MSC_COMCREATEMSCPIX_HPP
#define VIEW_MSC_COMCREATEMSCPIX_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <QObject>
#include <QPixmap>
#include <QString>

class QNetworkAccessManager;

namespace model{ namespace msc{
class MscSequence;
}}

namespace view{
namespace msc{

/*!
 * \brief The ComCreateMscPix class command creates a png-pic of a msc
*/
class MOBATAWIDGETSSHARED_EXPORT ComCreateMscPix
    : public QObject
{
  Q_OBJECT

public:
  /*!
   * \brief ComCreateMscPix constructor of the command class
   * \param msc  message sequence chart
   */
  ComCreateMscPix(model::msc::MscSequence const* msc,
                  QObject* parent=0);
  virtual ~ComCreateMscPix();

public:
  /*!
   * \brief execute operation executes the command
   * \param networkManager	network manager for requesting the msc pix
   */
  virtual void execute(QNetworkAccessManager* networkManager);

  /*!
   * \brief	adds a port-lifeline to the msc,
   *				determines the sequence of port-lifelines.
   * \param port	port of the port lifeline
   */
  void addPortLifeline(model::base::PortItem const* port);

  /*!
   * \brief mscSequence returns the msc-sequence of this command
   * \return msc-sequence of this command
   */
  virtual model::msc::MscSequence const* mscSequence() const;

signals:
  void result(model::msc::MscSequence const*,
              const QPixmap&);
  void error(model::msc::MscSequence const*,
             const QString&);

protected:
  model::msc::MscSequence const* msc() const;

protected slots:
  void resultSlot(QPixmap mscPix);
  void errorSlot(QString errorText);

private:
  Q_DISABLE_COPY(ComCreateMscPix)
  class Private;
  Private*  _d;
};

}/// end namespace msc
}/// end namespace view

#endif // VIEW_MSC_COMCREATEMSCPIX_HPP
