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

