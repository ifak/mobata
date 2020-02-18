#include "msctabwidget.hpp"

#include <mobata/model/msc/mscsequence.hpp>

#include <mobatawidgets/msc/mscpixwidget.hpp>

#include <QNetworkAccessManager>

class MscTabWidget::Private
{
  friend class MscTabWidget;
  
  QNetworkAccessManager* _networkManager;
};

MscTabWidget::MscTabWidget(QWidget *parent)
  : QTabWidget(parent), _d(new Private())
{
  this->_d->_networkManager=new QNetworkAccessManager(this);
}

MscTabWidget::~MscTabWidget()
{}

view::msc::MscPixWidget *MscTabWidget::mscPixWidget(MscSequence const* mscSequence)
{
	int count=this->count();
	for(int i=0; i<count; ++i)
	{
		QWidget* tabWidget=this->widget(i);
		MscPixWidget* mscPixView=dynamic_cast<MscPixWidget*>(tabWidget);
		Q_ASSERT(mscPixView);
		if(mscPixView->modelItem()==mscSequence)
			return mscPixView;
	}
	
	return 0;
}

void MscTabWidget::currentMscSequenceSlot(const MscSequence *currMscSequence)
{
	if(!currMscSequence)
		return;
	
	if(MscPixWidget* existMscPixView=this->mscPixWidget(currMscSequence))
	{
		this->setCurrentWidget(existMscPixView);
		return;
	}
	
	MscPixWidget* newMscPixView=new MscPixWidget(currMscSequence, this);
	this->addTab(newMscPixView, newMscPixView->modelItem()->text());
	this->setCurrentWidget(newMscPixView);
	newMscPixView->renderModeItem(this->_d->_networkManager);
	
	return;
}
