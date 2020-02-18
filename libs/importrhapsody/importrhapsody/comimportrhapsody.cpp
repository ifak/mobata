#include "comimportrhapsody.hpp"
#include "importrhapsodyutils.hpp"
#include "importrhapsodyelements.hpp"
#include <importrhapsody/importrhapsodypointer.hpp>

#include <mobata/model/statemachine/statemachine.hpp>
#include <QDebug>

using namespace model::statemachine;
using namespace utils;

namespace rhapsody {

class ComImportRhapsody::Private
{
  friend class ComImportRhapsody;

  RhapsodyPointer* _rhapsodyPointer;
  StateMachineModel*      _statemachineModel;
  QString                 _rhapsodyProjectFilename;
  QList<QString>          _rhapsodyImportPath;
  QMap<QString, QString>* _rules;

  Private(RhapsodyPointer* rhapsodyPointer,
          StateMachineModel* statemachineModel,
          const QString& rhapsodyProjectFilename,
          const QList<QString>& rhapsodyImportPath,
          QMap<QString, QString>* rules)
    : _rhapsodyPointer(rhapsodyPointer),
      _statemachineModel(statemachineModel),
      _rhapsodyProjectFilename(rhapsodyProjectFilename),
      _rhapsodyImportPath(rhapsodyImportPath),
      _rules(rules)
  {}
};

ComImportRhapsody::ComImportRhapsody(RhapsodyPointer* rhapsodyPointer,
                                     StateMachineModel* statemachineModel,
                                     const QString& rhapsodyProjectName,
                                     const QList<QString>& rhapsodyImportPath,
                                     QMap<QString, QString> *rules)
  : ImportRhapsodyProp(),
    _d(new Private(rhapsodyPointer, statemachineModel, rhapsodyProjectName, rhapsodyImportPath, rules))
{}

ComImportRhapsody::~ComImportRhapsody()
{
  delete this->_d;
}

bool ComImportRhapsody::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_statemachineModel);

  ImportRhapsodyElements importElements(this->_d->_rules);

  this->_d->_statemachineModel->reset();
  this->_d->_statemachineModel->initStandardDataTypes();

  if(!this->initCom(errorMessage))
    return false;

  if(!this->loadRhapsodyProjectMain(this->_d->_rhapsodyPointer,
                                    this->_d->_rhapsodyProjectFilename,
                                    errorMessage))
    return false;

  if(!this->loadRhapsodyStatechart(this->_d->_rhapsodyPointer->_rhapsodyProject,
                                   this->_d->_statemachineModel,
                                   this->_d->_rhapsodyImportPath,
                                   errorMessage))
    return false;

  if(!this->importRhapsodyDataTypes(this->_d->_rhapsodyPointer->_rhapsodyProject,
                                    this->_d->_statemachineModel,
                                    &importElements,
                                    errorMessage))
    return false;

  if(!this->importRhapsodyEvents(this->_d->_rhapsodyPointer->_rhapsodyProject,
                                 this->_d->_statemachineModel,
                                 &importElements,
                                 errorMessage))
    return false;

  if(!this->importRhapsodyAttributes(this->_d->_statemachineModel,
                                     &importElements,
                                     errorMessage))
    return false;

  if(!this->importRhapsodyOperations(this->_d->_statemachineModel,
                                     &importElements,
                                     errorMessage))
    return false;

  if(!this->importRhapsodyPorts(this->_d->_statemachineModel,
                                &importElements,
                                errorMessage))
    return false;

  if(!this->importRhapsodyStates(this->_d->_statemachineModel,
                                 &importElements,
                                 errorMessage))
    return false;

  if(!this->importRhapsodyTransitions(this->_d->_statemachineModel,
                                      &importElements,
                                      errorMessage))
    return false;

  return true;
}

} // namespace rhapsody
