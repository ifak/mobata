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
#ifndef VIEW_BASE_PIXMAPWIDGET_HPP
#define VIEW_BASE_PIXMAPWIDGET_HPP

#include "../mobatawidgets_global.hpp"

#include <QScrollArea>

namespace view{
namespace base{

class MOBATAWIDGETSSHARED_EXPORT PixmapWidget
    : public QScrollArea
{
  Q_OBJECT
public:
  explicit PixmapWidget(const QPixmap& pixmap,
                        QWidget *parent = 0);
  explicit PixmapWidget(QWidget *parent = 0);
  virtual ~PixmapWidget();

signals:
  void zoomValueChanged(int zoomValue);

public:
  int				zoomValue() const;
  int				zoomMin() const;
  int				zoomMax() const;
  void			setZoomRange(const int zoomMin,
                         const int zoomMax);

public slots:
  void	zoomInView();
  void	zoomIn();
  void	zoomOut();
  void	zoomReset();
  void	zoomWidth();
  void	zoomHeight();
  void	doScaling();
  void	print();
  void	setZoomValue(int zoomValue);

public:
  const		QPixmap &pixmap() const;
  void		setPixmap(const QPixmap& pixmap);
  QString	text() const;
  void		setText(const QString& text);

protected:
  virtual void wheelEvent (QWheelEvent* event);
  //	virtual void keyPressEvent(QKeyEvent* event);

private:
  void init();

private:
  Q_DISABLE_COPY(PixmapWidget)
  class Private;
  QScopedPointer<Private> _d;
};

}/// namespace base
}/// namespace view

#endif // VIEW_BASE_PIXMAPWIDGET_HPP
