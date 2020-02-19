#include "pixmapwidget.hpp"

#include <QLabel>
#include <QHBoxLayout>
#include <QWheelEvent>
#include <QIcon>
#include <QAction>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace base{

class PixmapWidget::Private
{
	friend class PixmapWidget;
	
	Private(const QPixmap& pixmap=QPixmap())
		:	_pixmapLabel(0), _pixmap(pixmap),
      _zoomValue(200), _zoomMin(0), 
      _zoomMax(400), _zoomStep(10)
	{}
	
public:
	~Private()
	{}
	
private:
	QLabel*	_pixmapLabel;
	QPixmap	_pixmap;
	int			_zoomValue;
	int			_zoomMin;
	int			_zoomMax;
	int			_zoomStep;
};

PixmapWidget::PixmapWidget(const QPixmap& pixmap,
													 QWidget *parent)
	:	QScrollArea(parent), _d(new Private(pixmap))
{
	this->init();
	this->setPixmap(pixmap);
}

PixmapWidget::PixmapWidget(QWidget *parent)
	:	QScrollArea(parent), _d(new Private())
{
	this->init();
}

PixmapWidget::~PixmapWidget()
{}

void PixmapWidget::init()
{
	this->setBackgroundRole(QPalette::Dark);
	this->setAlignment(Qt::AlignCenter);
	
	this->_d->_pixmapLabel=new QLabel;
	this->_d->_pixmapLabel->setAlignment(Qt::AlignCenter);
	this->_d->_pixmapLabel->setBackgroundRole(QPalette::Base);
	this->_d->_pixmapLabel->setSizePolicy(QSizePolicy::Expanding,
																				QSizePolicy::Expanding);
	this->_d->_pixmapLabel->setWordWrap(true);
	this->setWidget(this->_d->_pixmapLabel);
}

const QPixmap& PixmapWidget::pixmap() const
{
	return this->_d->_pixmap;
}

void PixmapWidget::setPixmap(const QPixmap &pixmap)
{
	this->_d->_pixmap=pixmap;
	this->_d->_pixmapLabel->setPixmap(this->_d->_pixmap);
	if(this->_d->_pixmap.isNull())
		this->_d->_pixmapLabel->setText(QLatin1String("no pixmap available"));
	
	this->_d->_pixmapLabel->adjustSize();
	
	return;
}

QString PixmapWidget::text() const
{
	return this->_d->_pixmapLabel->text();
}

void PixmapWidget::setText(const QString &text)
{
	this->_d->_pixmapLabel->setText(text);
	this->_d->_pixmapLabel->adjustSize();
	
	return;
}

void PixmapWidget::zoomInView()
{
	if(this->_d->_pixmap.isNull())
		return;
	
	QPixmap scaledPix=this->_d->_pixmap.scaled(this->size(),
																						 Qt::KeepAspectRatio);
	if(scaledPix.isNull())
		return;
	
	this->_d->_pixmapLabel->setPixmap(scaledPix);
	this->_d->_pixmapLabel->adjustSize();
	
	QSizeF scaledPixSize=scaledPix.size();
	QSizeF normalPixSize=this->_d->_pixmap.size();
	
	qreal zoomFactor=(scaledPixSize.width()/normalPixSize.width()
									 +scaledPixSize.height()/normalPixSize.height())
									 /2;
	
	this->_d->_zoomValue=this->_d->_zoomValue*zoomFactor;

	emit zoomValueChanged(this->_d->_zoomValue);

	return;
}

void PixmapWidget::zoomIn()
{
	if(this->_d->_zoomValue>=this->_d->_zoomMax)
		return;
	
	this->_d->_zoomValue+=this->_d->_zoomStep;
	if(this->_d->_zoomValue>this->_d->_zoomMax)
		this->_d->_zoomValue=this->_d->_zoomMax;
	emit zoomValueChanged(this->_d->_zoomValue);
	
	this->doScaling();

	return;
}

void PixmapWidget::zoomOut()
{
	if(this->_d->_zoomValue<=this->_d->_zoomMin)
		return;
	
	this->_d->_zoomValue-=this->_d->_zoomStep;
	if(this->_d->_zoomValue<this->_d->_zoomMin)
		this->_d->_zoomValue=this->_d->_zoomMin;
	emit zoomValueChanged(this->_d->_zoomValue);
	
	this->doScaling();

	return;
}

void PixmapWidget::doScaling()
{
	int zoomRange=this->_d->_zoomMax-this->_d->_zoomMin;
	qreal resetZoomValue=this->_d->_zoomMin + zoomRange/2;
	qreal zoomFactor=this->_d->_zoomValue/resetZoomValue;
	
	QPixmap scaledPix=this->_d->_pixmap.scaled(this->_d->_pixmap.size().width()*zoomFactor,
																						 this->_d->_pixmap.size().height()*zoomFactor,
																						 Qt::KeepAspectRatio);
	if(scaledPix.isNull())
		return;
	
	this->_d->_pixmapLabel->setPixmap(scaledPix);
	this->_d->_pixmapLabel->adjustSize();

	return;
}

void PixmapWidget::zoomReset()
{
	int range=this->_d->_zoomMax-this->_d->_zoomMin;
	this->_d->_zoomValue=this->_d->_zoomMin+range/2;
	emit zoomValueChanged(this->_d->_zoomValue);
	
	this->_d->_pixmapLabel->setPixmap(this->_d->_pixmap);
	this->_d->_pixmapLabel->adjustSize();

	return;
}

void PixmapWidget::zoomWidth()
{
	if(this->_d->_pixmap.isNull())
		return;
	
	QPixmap scaledPix=this->_d->_pixmap.scaledToWidth(this->width(),
																										Qt::SmoothTransformation);
	if(scaledPix.isNull())
		return;
	
	this->_d->_pixmapLabel->setPixmap(scaledPix);
	this->_d->_pixmapLabel->adjustSize();
	
	QSizeF scaledPixSize=scaledPix.size();
	QSizeF normalPixSize=this->_d->_pixmap.size();
	
	qreal zoomFactor=(scaledPixSize.width()/normalPixSize.width()
									 +scaledPixSize.height()/normalPixSize.height())
									 /2;
	
	this->_d->_zoomValue=this->_d->_zoomValue*zoomFactor;

	emit zoomValueChanged(this->_d->_zoomValue);
	return;
}

void PixmapWidget::zoomHeight()
{
	if(this->_d->_pixmap.isNull())
		return;
	
	QPixmap scaledPix=this->_d->_pixmap.scaledToHeight(this->height(),
																										 Qt::SmoothTransformation);
	if(scaledPix.isNull())
		return;
	
	this->_d->_pixmapLabel->setPixmap(scaledPix);
	this->_d->_pixmapLabel->adjustSize();
	
	QSizeF scaledPixSize=scaledPix.size();
	QSizeF normalPixSize=this->_d->_pixmap.size();
	
	qreal zoomFactor=(scaledPixSize.width()/normalPixSize.width()
									 +scaledPixSize.height()/normalPixSize.height())
									 /2;
	
	this->_d->_zoomValue=this->_d->_zoomValue*zoomFactor;

	emit zoomValueChanged(this->_d->_zoomValue);
	return;
}

void PixmapWidget::print()
{

	return;
}

void PixmapWidget::wheelEvent(QWheelEvent *event)
{
	if(event->modifiers()==Qt::CTRL)
	{
		int numDegrees = event->delta() / 8;
		int numSteps = numDegrees / 15;
		this->_d->_zoomValue+=numSteps;
		emit zoomValueChanged(this->_d->_zoomValue);
		
		this->doScaling();
		return event->accept();
	}

	return QScrollArea::wheelEvent(event);
}

int PixmapWidget::zoomValue() const
{
	return this->_d->_zoomValue;
}

int PixmapWidget::zoomMin() const
{
	return this->_d->_zoomMin;
}

int PixmapWidget::zoomMax() const
{
	return this->_d->_zoomMax;
}

void PixmapWidget::setZoomRange(const int zoomMin, const int zoomMax)
{
	if(zoomMin<0)
		this->_d->_zoomMin=0;
	else
		this->_d->_zoomMin=zoomMin;
	
	if(zoomMax<=this->_d->_zoomMin)
		this->_d->_zoomMax=this->_d->_zoomMin;
	else
		this->_d->_zoomMax=zoomMax;
	
	return;
}

void PixmapWidget::setZoomValue(int zoomValue)
{
	this->_d->_zoomValue=zoomValue;
	emit zoomValueChanged(this->_d->_zoomValue);
	
	this->doScaling();
	
	return;
}

}///end namespace base
}///end namespace view
