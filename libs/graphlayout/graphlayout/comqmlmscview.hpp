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

class GRAPHLAYOUTSHARED_EXPORT ComQmlMscView:public QObject//, public QMainWindow
{
    Q_OBJECT
public:
    ComQmlMscView(QQuickView *view,
                    model::msc::MscSequence *mscSeq,
                    QObject *parent = 0);

    ComQmlMscView(QQuickWidget *widget,
                    model::msc::MscSequence *mscSeq,
                    QObject *parent = 0);

    ~ComQmlMscView(){
    }
    bool execute(QString* errorString);

    void setBackgroundColor(QColor color);
    void setTitleColor(QColor color);
    void setTitleSize(int textsize);
    void setTitleShape(ShapeEnum shape);
    void setTitleBorderColor(QColor color);
    void setTitleBorderWidth(double width);
    void setTitleBackgroundColor(QColor color);

public slots:
    void updateLifeLines();
    void updateOverlay();
    void updateRegionLines();
private:
    class ComQmlMscViewVars;
    ComQmlMscViewVars* _d;

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

    QObject* nodeFromUuid(const QString& Uuid);
    QObject* labelFromUuid(const QString& Uuid);

};
}

