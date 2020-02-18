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

#include "graphlayout_global.hpp"
#include "comexportmscgraph.hpp"

#include <QQuickWidget>

namespace model{namespace msc{
class MscSequence;
class MscSequenceItem;
}}

namespace graphlayout{

class GRAPHLAYOUTSHARED_EXPORT MscQuickWidget
        :public QQuickWidget
{
    Q_OBJECT
public:
    explicit MscQuickWidget(QWidget* parent = nullptr);
    MscQuickWidget(model::msc::MscSequence const* mscSequence,
                   QWidget* parent = nullptr);

    virtual ~MscQuickWidget();
    void setMscSequence(model::msc::MscSequence const* mscSequence);

private:
    void reset();

protected:
    model::msc::MscSequence const* mscSequence() const;

public:
    void addFixMscComponent(model::msc::MscComponentItem const* mscComponent);

public:
    bool layout(QString* errorString, bool simple = false);

public:
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
    void setTimeoutColor(const QColor& color);
    void setTimeoutTextColor(const QColor& color);
    void setTimeoutRadius(const int& radius);
    void setSleeptimerColor(const QColor& color);
    void setSleeptimerTextColor(const QColor& color);
    void setSleeptimerRadius(const int& radius);
    void setMessageColor(const QColor& color);
    void setMessageTextColor(const QColor& color);
    void setCheckmessageColor(const QColor& color);
    void setCheckmessageTextColor(const QColor& color);
    void setFragmentColor(const QColor& color);
    void setFragmentTextColor(const QColor& color);
    void setRegionColor(const QColor& color);
    void setRegionTextColor(const QColor& color);
    void setLifelineColor(const QColor& color);
    void setBackgroundColor(const QColor& color);
    void setHighlightColor(const QColor& color);

    bool savePicture(const QString& path = "");

public slots:
    //Zoom
    void zoomIn();
    void zoomOut();
    void zoomFitAll();
    void zoomFitWidth();
    void zoomFitHeight();
    void zoomYIn();
    void zoomYOut();
    void zoomXIn();
    void zoomXOut();

    //Highlight
    void unhighlightAllGraphicItems();
    void highlightGraphicItemByUuid(const QUuid& itemUuid,
                                    bool highlight,
                                    bool unhighlightOtherItems = false);
    void highlightGraphicItemsByUuids(const QList<QUuid>& itemUuids,
                                      bool highlight,
                                      bool unhighlightOtherItems = true);
    void highlightGraphicItemByName(const QString& itemName,
                                    bool highlight,
                                    bool unhighlightOtherItems = false);
    void highlightGraphicItemsByNames(const QList<QString>& itemNames,
                                      bool highlight,
                                      bool unhighlightOtherItems = true);
    void highlightItemByUuid(const QUuid& itemUuid,
                             const bool highlight);
    void highlightItemByName(const QString& itemName,
                             const bool highlight);
    void saveAsPicture();

    void exportPlantUml(QSettings* settings);
    void exportPlantUml();

    //live create
    bool addMessage(const QUuid& fromPort,
                    const QUuid& toPort,
                    const QString& message,
                    QString* errorString);
    bool addMessage(const model::msc::PortItem* fromPort,
                    const model::msc::PortItem* toPort,
                    const QString& message,
                    QString* errorString);

    bool addStatement(const QUuid& component,
                      const QString& statement,
                      QString* errorString);

private slots:
    void updateLifeLines();
    void updateOverlay();
    void updateRegionLines();
    void clickedObject(const QString& uuid);

signals:
    void selectedItem(const QUuid& uuid);

protected:
    bool placeComponents(QString* errorString);
    bool createComponentList(QString* errorString);
    bool placeSeq(QString* errorString);
    bool placeItem(const model::msc::MscSequenceItem *seqItem,QString* errorString);
    bool addFrames(QString* errorString);

    void connectMouseAreas();

    void highlight(QObject* object, const bool highlight);

    int columnFromComponent(const QUuid uuid);
    int spanFromComponent(const QUuid uuid);
    QQuickItem* component(const QUuid uuid);
    QString nameFromComponent(const QUuid uuid);

    void countComponents();
    void contextMenuEvent(QContextMenuEvent* event);
private:
    Q_DISABLE_COPY(MscQuickWidget)
    class Private;
    Private* _d;
};
}// end namespace graphlayout

