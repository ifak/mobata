#include "msctabwidget.hpp"

#include <mobata/model/msc/mscsequence.hpp>
#include <mobatawidgets/msc/mscscene.hpp>
#include <mobatawidgets/msc/mscview.hpp>
#include <mobatawidgets/msc/comrendermscsequence.hpp>

#include <QNetworkAccessManager>

#include <mobata/memory_leak_start.hpp>

class MscTabWidget::Private
{
  friend class MscTabWidget;
  
  QMap<MscSequence const*, view::msc::KMscView*>  _sequenceWidgets;
};

MscTabWidget::MscTabWidget(QWidget *parent)
  : QTabWidget(parent), _d(new Private())
{}

MscTabWidget::~MscTabWidget()
{}

void MscTabWidget::currentMscSequenceSlot(MscSequence const* currMscSequence)
{
  if(!currMscSequence)
    return;

  if(view::msc::KMscView* mscView=this->_d->_sequenceWidgets.value(currMscSequence))
  {
    this->setCurrentWidget(mscView);
    return;
  }
  else
  {
    view::msc::KMscScene* newMscScene=new view::msc::KMscScene(this);
    view::msc::KMscView* newMscView=new view::msc::KMscView(newMscScene, this);
    this->addTab(newMscView, currMscSequence->name());
    this->setCurrentWidget(newMscView);
    this->_d->_sequenceWidgets.insert(currMscSequence, newMscView);

    view::msc::ComRenderMscSequence renderCommand(newMscScene, currMscSequence);
    QString errorMessage;
    bool result=renderCommand.execute(&errorMessage);
    Q_ASSERT(result);
    Q_ASSERT(errorMessage.isEmpty());
  }

  return;
}
