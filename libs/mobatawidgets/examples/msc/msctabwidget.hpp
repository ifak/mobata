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
#ifndef MSCTABWIDGET_HPP
#define MSCTABWIDGET_HPP

#include <QTabWidget>

namespace model{namespace msc{class MscSequence;}}
namespace view{namespace msc{class MscPixWidget;}}

class MscTabWidget : public QTabWidget
{
	Q_OBJECT
	
	typedef model::msc::MscSequence MscSequence;
  typedef view::msc::MscPixWidget MscPixWidget;

public:
  explicit MscTabWidget(QWidget *parent = 0);
  virtual ~MscTabWidget();
  
public:  
  MscPixWidget* mscPixWidget(MscSequence const* mscSequence);
  
public slots:
  void currentMscSequenceSlot(MscSequence const* currMscSequence);
	
private:
  Q_DISABLE_COPY(MscTabWidget)
	class Private;
	QScopedPointer<Private> _d;
};

#endif // MSCTABWIDGET_HPP
