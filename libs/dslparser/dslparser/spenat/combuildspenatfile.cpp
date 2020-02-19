#include "combuildspenatfile.hpp"
#include "../dslerror.hpp"

#include <dslparser/common/buildbasemodelfile.hpp>

#include <mobata/model/base/atriggeritem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/initplaceitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/spenat/preplacearc.hpp>
#include <mobata/model/spenat/postplacearc.hpp>

#include <mobata/utils/functors.hpp>

using namespace model::base;
using namespace model::spenat;
using namespace dslparser::common;
using namespace utils;

namespace dslparser {
namespace spenat {

class ComBuildSpenatFile::Private
{
  friend class ComBuildSpenatFile;

  const QString          _filePath;
  const SpenatDeclModel* _spenatDeclModel;
  DslErrorList           _spenatErrors;

  Private(const QString& filePath,
          const SpenatDeclModel* spenatDeclModel)
    : _filePath(filePath),
      _spenatDeclModel(spenatDeclModel)
  {}
};

ComBuildSpenatFile::ComBuildSpenatFile(const QString& filePath,
                                       const model::spenat::SpenatDeclModel* spenatDeclModel,
                                       QObject* parent)
  : QObject(parent), _d(new Private(filePath, spenatDeclModel))
{
}

ComBuildSpenatFile::~ComBuildSpenatFile()
{
  delete this->_d;
}

bool ComBuildSpenatFile::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_spenatDeclModel);

  QString spenatDocText;
  spenatDecl(&spenatDocText);
  if(spenatDocText.isEmpty())
    return false;

  if(!saveSpecificationModel(&spenatDocText,
                             this->_d->_filePath,
                             errorString))
    return false;

  return true;
}

QString ComBuildSpenatFile::toDocText()
{
  Q_ASSERT(this->_d->_spenatDeclModel);

  QString spenatDocText;
  spenatDecl(&spenatDocText);

  return spenatDocText;
}

void ComBuildSpenatFile::spenatDecl(QString* content, int tabCount)
{
  Q_ASSERT(content);

  AddPtrString(content) << QStringLiteral("Spenat {") + nextLine(tabCount + 2);
  nameDecl(content, this->_d->_spenatDeclModel->name());
  AddPtrString(content) << nextLine(tabCount + 2);

  const model::base::PropPorts* propPorts = dynamic_cast<const model::base::PropPorts*>(this->_d->_spenatDeclModel);
  Q_ASSERT(propPorts);
  portsDecl(propPorts,
            content,
            tabCount + 2);

  commonDecl(this->_d->_spenatDeclModel,
             content,
             tabCount + 2);

  for(const PlaceItem* place : this->_d->_spenatDeclModel->places())
  {
    placeDecl(content, place, tabCount + 2);
    if(place != this->_d->_spenatDeclModel->places().back())
      AddPtrString(content) << doubleNextLine(tabCount + 2);
  }

  if(!this->_d->_spenatDeclModel->transitions().isEmpty())
    AddPtrString(content) << doubleNextLine(tabCount + 2);

  for(const TransitionItem* transition : this->_d->_spenatDeclModel->transitions()) {
    transitionDecl(content, transition, tabCount + 2);
    if(transition != this->_d->_spenatDeclModel->transitions().back())
      AddPtrString(content) << doubleNextLine(tabCount + 2);
  }

  AddPtrString(content) << nextLine(tabCount) + "}";

  return;
}

void ComBuildSpenatFile::placeDecl(QString* content, const PlaceItem* model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("Place {") + nextLine(tabCount + 2);
  nameDecl(content, model->name());

  if(this->_d->_spenatDeclModel->isInitPlace(model))
    AddPtrString(content) << nextLine(tabCount + 2) + QStringLiteral("initial: true;");

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");

  return;
}

void ComBuildSpenatFile::transitionDecl(QString* content, const TransitionItem* model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  const model::base::ATriggerItem* trigger = model->triggerItem();
  if(trigger == nullptr)
  {
    AddPtrString(content) << QStringLiteral("SignalTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());
  }
  else if(trigger->triggerType() == ATriggerItem::EventTrigger)
  {
    AddPtrString(content) << QStringLiteral("SignalTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());

      const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
      Q_ASSERT(signalTrigger);
      if(!signalTrigger->triggerSignal()->name().isEmpty())
        AddPtrString(content) << nextLine(tabCount + 2) +
                                 QStringLiteral("signal: ") +
                                 signalTrigger->triggerSignal()->name() +
                                 QStringLiteral(";");

      if(!signalTrigger->port()->name().isEmpty())
        AddPtrString(content) << nextLine(tabCount + 2) +
                                 QStringLiteral("port: ") +
                                 signalTrigger->port()->name() +
                                 QStringLiteral(";");
  }
  else if(trigger->triggerType() == ATriggerItem::TimeoutTrigger)
  {
    const TimeoutTriggerItem* timeoutTrigger = static_cast<const TimeoutTriggerItem*>(trigger);
    Q_ASSERT(timeoutTrigger);
    AddPtrString(content) << QStringLiteral("TimeoutTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());
    AddPtrString(content) << nextLine(tabCount + 2) +
                             QStringLiteral("value: ") +
                             QString::number(timeoutTrigger->value(), 'f', 1) +
                             QStringLiteral(";");

  }

  writeMultiLineString(content,
                       QStringLiteral("guard"),
                       model->guard(),
                       tabCount + 2);

  writeMultiLineString(content,
                       QStringLiteral("action"),
                       model->actions(),
                       tabCount + 2);

  if(!model->prePlaceArcs().isEmpty())
  {
    AddPtrString(content) << nextLine(tabCount + 2) +
                             QStringLiteral("pre: ");
    for(const PrePlaceArc* prePlace : model->prePlaceArcs())
    {
      AddPtrString(content) << prePlace->place()->name();
      if(prePlace != model->prePlaceArcs().back())
        AddPtrString(content) << QStringLiteral(",");
      else
        AddPtrString(content) << QStringLiteral(";");
    }
  }

  if(!model->postPlaceArcs().isEmpty())
  {
    AddPtrString(content) << nextLine(tabCount + 2) +
                             QStringLiteral("post: ");
    for(const PostPlaceArc* postPlace : model->postPlaceArcs())
    {
      AddPtrString(content) << postPlace->place()->name();
      if(postPlace != model->postPlaceArcs().back())
        AddPtrString(content) << QStringLiteral(",");
      else
        AddPtrString(content) << QStringLiteral(";");
    }
  }

  AddPtrString(content) << nextLine(tabCount) +
                           QStringLiteral("}");
}

} // namespace statemachine
} // namespace dslparser
