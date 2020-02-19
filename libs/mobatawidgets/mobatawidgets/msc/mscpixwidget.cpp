#include "mscpixwidget.hpp"

#include <mobata/model/msc/mscsequence.hpp>
#include "comcreatemscpix.hpp"

#include <QLabel>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class MscPixWidget::Private
{
  friend class MscPixWidget;

  Private(MscSequence const* mscSequence)
    :	_mscSequence(mscSequence),
      _createMscPixCommand(mscSequence)
  {}

public:
  ~Private()
  {}

private:
  MscSequence const*  _mscSequence;
  ComCreateMscPix     _createMscPixCommand;
};

MscPixWidget::MscPixWidget(MscSequence const* mscSequence,
                           QWidget *parent)
  :	base::PixmapWidget(parent), _d(new Private(mscSequence))
{
  this->setText("No MSC representation currently available.");

  connect(&this->_d->_createMscPixCommand,
          &ComCreateMscPix::result,
          this,
          &MscPixWidget::mscPixSlot);
  connect(&this->_d->_createMscPixCommand,
          &ComCreateMscPix::error,
          this,
          &MscPixWidget::errorSlot);
}

MscPixWidget::~MscPixWidget()
{}

model::msc::MscSequence const* MscPixWidget::modelItem() const
{
  return this->_d->_mscSequence;
}

void MscPixWidget::renderModeItem(QNetworkAccessManager* networkManager)
{
  if(!networkManager)
  {
    this->setText("no network manager, \n"
                  "test case picture cannot be requested.");
    return;
  }
  this->_d->_createMscPixCommand.execute(networkManager);
  this->setText("picture will be requested.");

  return;
}

void MscPixWidget::mscPixSlot(const MscSequence* mscSequence,
                              const QPixmap & mscPix)
{
  Q_ASSERT(mscSequence==this->_d->_mscSequence);
  Q_UNUSED(mscSequence);

  this->setPixmap(mscPix);

  return;
}

void MscPixWidget::errorSlot(const MscSequence *mscSequence,
                             const QString &errorString)
{
  Q_ASSERT(mscSequence==this->_d->_mscSequence);
  Q_UNUSED(mscSequence);

  this->setText(errorString);

  return;
}

}/// end namespace msc
}/// end namespace view
