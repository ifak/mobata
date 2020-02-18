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
#ifndef VIEW_MSC_MSCPIXWIDGET_HPP
#define VIEW_MSC_MSCPIXWIDGET_HPP

#include "../mobatawidgets_global.hpp"

#include "../base/pixmapwidget.hpp"

class QNetworkAccessManager;

namespace model{namespace msc{class MscSequence;}}

namespace view{
namespace msc{

class MOBATAWIDGETSSHARED_EXPORT MscPixWidget
		: public base::PixmapWidget
{
	Q_OBJECT
  
private:
  typedef model::msc::MscSequence  MscSequence;
  
public:
	explicit MscPixWidget(const MscSequence *modelItem,
                        QWidget *parent = 0);
	virtual ~MscPixWidget();

public:
	MscSequence const* modelItem() const;
	void renderModeItem(QNetworkAccessManager *networkManager);
	
public slots:
	void mscPixSlot(const MscSequence*, const QPixmap& mscPix);
	void errorSlot(const MscSequence*, const QString& errorString);
	
private:
	Q_DISABLE_COPY(MscPixWidget)
	class Private;
	QScopedPointer<Private> _d;
};

}/// end namespace msc
}/// end namespace view

#endif // VIEW_MSC_MSCPIXWIDGET_HPP
