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
#pragma once

#if defined(GRAPHLAYOUT_LIBRARY_STATIC)
#  define GRAPHLAYOUTSHARED_EXPORT
#elif(GRAPHLAYOUT_LIBRARY)
#  define GRAPHLAYOUTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GRAPHLAYOUTSHARED_EXPORT Q_DECL_IMPORT
#endif

#include <QtQuick>
#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>
#include <QStringList>
#include <QList>

#include <graphlayout/graphlayout_global.hpp>
#include <graphlayout/layoutglobal.hpp>

#include <mobata/model/msc/msc.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/mscsequence.hpp>
#include <mobata/model/ts/ts.hpp>

#include <QFileDialog>
namespace graphlayout{

class GRAPHLAYOUTSHARED_EXPORT QmlMscView:public QObject//, public QMainWindow
{
    Q_OBJECT
public:
    QmlMscView(QQuickView *view,
                    model::msc::MscSequence *mscSeq,
                    QObject *parent = 0);

    QmlMscView(QQuickWidget *widget,
                    model::msc::MscSequence *mscSeq,
                    QObject *parent = 0);

    ~QmlMscView(){
    }
    bool layout(QString* errorString);

    //Design
    void setComponentColor(const QColor& color);
    void setComponentTextColor(const QColor& color);
    void setComponentRadius(const int& radius);
    void setStatementColor(const QColor& color);
    void setStatementTextColor(const QColor& color);
    void setStatementRadius(const int& radius);
    void setTimerColor(const QColor& color);
    void setTimerTextColor(const QColor& color);
    void setTimerRadius(const int& radius);
    void setMessageColor(const QColor& color);
    void setMessageTextColor(const QColor& color);
    void setLifelineColor(const QColor& color);

public slots:
    void updateLifeLines();
    void updateOverlay();
    void updateRegionLines();
private:
    class QmlMscViewVars;
    QmlMscViewVars* _d;

protected:
    void placeTitle();
    void placeComponents();
    void createComponentList();
    void placeSeq();
    void placeItem(const model::msc::MscSequenceItem *seqItem);
    void addFrames();

    int columnFromComponent(const QUuid uuid);
    int spanFromComponent(const QUuid uuid);
    QQuickItem* component(const QUuid uuid);
    const QString& nameFromComponent(const QUuid uuid);

    void countComponents(const model::msc::MscSequenceItem *seq);

};
}

