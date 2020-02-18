#include "importrhapsodyprop.hpp"
#include "importrhapsodyutils.hpp"
#include "importrhapsodyelements.hpp"
#include "importrhapsodyworker.hpp"

#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <importrhapsody/importrhapsodypointer.hpp>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QCoreApplication>
#include <QEventLoop>

using namespace model::statemachine;
using namespace utils;

namespace rhapsody {

class ImportRhapsodyProp::Private
{
  friend class ImportRhapsodyProp;

  IRPStatechartPtr    _rhapsodyStatechart;
  IRPPackagePtr       _statechartPackage;
  IRPClassPtr         _statechartClass;
  bool                _comInitialized;
  bool                _eventError;
  QString             _projectFilePath;
  IStream*            _appStream;
  IStream*            _projectStream;

  Private()
    : _rhapsodyStatechart(nullptr),
      _statechartPackage(nullptr),
      _statechartClass(nullptr),
      _comInitialized(false),
      _eventError(false)
  {}
};

ImportRhapsodyProp::ImportRhapsodyProp()
  :_d(new Private())
{}

ImportRhapsodyProp::~ImportRhapsodyProp()
{
  delete this->_d;
  if(this->_d->_comInitialized)
    CoUninitialize();
}

//initializing the com library
bool ImportRhapsodyProp::initCom(QString* errorMessage){

  if(this->_d->_comInitialized == true){
    AddPtrString(errorMessage) << "Com library is already initialized.";
    return false;
  }

  HRESULT hr;
  hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED );
  if(hresultFailed(hr, errorMessage, "Failed to initialize COM."))
    return false;

  this->_d->_comInitialized = true;

  return true;
}

//load rhapsody project from a project file or load current project in an open rhapsody instance
bool ImportRhapsodyProp::loadRhapsodyProjectMain(RhapsodyPointer* rhapsodyPointer,
                                                 const QString& projectFilePath,
                                                 QString* errorMessage)
{
  if(projectFilePath.isEmpty()){
    if(!this->loadRhapsodyProjectInstance(rhapsodyPointer->_rhapsodyProject,
                                          errorMessage))
      return false;
  }
  else{
    if(!this->loadRhapsodyProjectFile(rhapsodyPointer,
                                      projectFilePath,
                                      errorMessage))
      return false;
  }

  return true;
}

bool ImportRhapsodyProp::loadRhapsodyProjectInstance(IRPProjectPtr& rhapsodyProject,
                                                     QString* errorMessage)
{
  this->initCom(errorMessage);

  //load active project
  HRESULT hr;
  IUnknownPtr rhpunk = 0;
  IRPApplicationPtr activeApp;
  hr = GetActiveObject(CLSID_RPApplication, NULL, &rhpunk);
  if(hresultFailed(hr, errorMessage, "Failed to access rhapsody application."))
    return false;

  hr = rhpunk->QueryInterface(IID_IRPApplication, (void **)&activeApp);
  if(hresultFailed(hr, errorMessage, "Failed to access rhapsody query interface."))
    return false;

  rhapsodyProject = 0;
  hr = activeApp->activeProject(&rhapsodyProject);
  if(hresultFailed2(rhapsodyProject, hr, errorMessage, "Could not open active project."))
    return false;

  return true;
}

bool ImportRhapsodyProp::loadRhapsodyProjectFile(RhapsodyPointer* rhapsodyPointer,
                                                 const QString& projectFilePath,
                                                 QString* errorMessage)
{
  if(rhapsodyPointer->_rhapsodyApplication == nullptr || rhapsodyPointer->_rhapsodyProject == nullptr){

    QThread thread;
    QTimer timer;
    QEventLoop loop;
    ImportRhapsodyWorker worker(projectFilePath);
    worker.moveToThread(&thread);
    this->_d->_eventError = false;

    connect(this, SIGNAL (startWorker(QString*)), &worker, SLOT (startRhapsody(QString*)));
    connect(&worker, SIGNAL(sendResultData(IStream*, IStream*, bool)), this, SLOT (receiveResultData(IStream*, IStream*, bool)));
    connect(this, SIGNAL (stopWorker()), &thread, SLOT (quit()));
    connect(&timer, SIGNAL (timeout()), &thread, SLOT (quit()));
    connect(&thread, SIGNAL (finished()), &loop, SLOT (quit()));

    timer.setSingleShot(true);
    timer.start(180000);
    thread.start();
    emit startWorker(errorMessage);
    loop.exec();

    if(this->_d->_eventError){
      utils::AddPtrString(errorMessage) << "Thread failed to load rhapsody project.";
      return false;
    }
    HRESULT hr;

    this->initCom(errorMessage);

    hr = CoGetInterfaceAndReleaseStream(this->_d->_appStream, IID_IRPApplication, (void**)&rhapsodyPointer->_rhapsodyApplication);
    if(hresultFailed2(rhapsodyPointer->_rhapsodyApplication, hr, errorMessage, "Could not get pointer to rhapsody application from IStream"))
      return false;

    hr = CoGetInterfaceAndReleaseStream(this->_d->_projectStream, IID_IRPProject, (void**)&rhapsodyPointer->_rhapsodyProject);
    if(hresultFailed2(rhapsodyPointer->_rhapsodyProject, hr, errorMessage, "Could not get pointer to rhapsody project from IStream"))
      return false;
  }

  return true;
}

//return pointer to a rhapsody statechart nested in a given path of the currently opened project
bool ImportRhapsodyProp::loadRhapsodyStatechart(IRPProjectPtr& rhapsodyproject,
                                                StateMachineModel* smModel,
                                                const QList<QString>& importPath,
                                                QString* errorMessage)
{
  Q_ASSERT(rhapsodyproject);
  if(!this->_d->_comInitialized){
    AddPtrString(errorMessage) << "Com library was not initialized.";
    return false;
  }

  IRPModelElementPtr currentElement = rhapsodyproject;
  //iterate over remaining list to find the statechart element
  for(QList<QString>::const_iterator it = importPath.constBegin(); it != importPath.constEnd(); it++)
  {
    HRESULT hr;
    IRPCollectionPtr collection;

    hr = currentElement->getNestedElements(&collection);
    if(hresultFailed2(collection, hr, errorMessage, "Rhapsody element contains no more nested elements!"))
      return false;

    currentElement = findModelElement(*it, collection, errorMessage);
    if(currentElement != nullptr){

      //get rhapsody package and class where the statechart is nested in
      //get name of StateMachineModel according to last rhapsody class item in the rhapsody item tree
      if(elementInterface(currentElement, errorMessage) == "IRPPackage")
        this->_d->_statechartPackage = currentElement;
      else if(elementInterface(currentElement, errorMessage) == "IRPClass")
        this->_d->_statechartClass = currentElement;

      if(*it == importPath.last()){
        if(elementInterface(currentElement, errorMessage) == QStringLiteral("IRPStatechart")){
          this->_d->_rhapsodyStatechart = currentElement;
          smModel->setName(elementName(this->_d->_statechartClass, errorMessage));
          return true;
        }
        else{
          AddPtrString(errorMessage) << "Last rhapsody element \""
                                     << (*it)
                                     << "\" in list is not a statechart.";
          return false;
        }
      }
    }
    else{
      AddPtrString(errorMessage) << "Rhapsody element \""
                                 << (*it)
                                 << "\" from the given list could not be found in the opened project.";
      return false;
    }
  }

  return false;
}

//get all states from current rhapsody project and convert them to mobata statemachine states
bool ImportRhapsodyProp::importRhapsodyStates(StateMachineModel* smModel,
                                              ImportRhapsodyElements* importElements,
                                              QString* errorMessage)
{
  Q_ASSERT(this->_d->_rhapsodyStatechart);
  Q_ASSERT(smModel);

  HRESULT hr;

  IRPStatePtr rootState;
  hr = this->_d->_rhapsodyStatechart->get_rootState(&rootState);
  if(hresultFailed2(rootState, hr, errorMessage, "Could not get root state of statechart item."))
    return false;

  if(!importElements->createSubStates(smModel,
                                      this->_d->_rhapsodyStatechart,
                                      rootState,
                                      errorMessage))
    return false;

  return true;
}

//convert all rhapsody transitions to mobata statemachine transitions
bool ImportRhapsodyProp::importRhapsodyTransitions(StateMachineModel* smModel,
                                                   ImportRhapsodyElements* importElements,
                                                   QString* errorMessage)
{
  Q_ASSERT(this->_d->_rhapsodyStatechart);
  Q_ASSERT(smModel);

  QStringList transitionNameList;

  for(TransitionList::const_iterator it = importElements->_transitionList.constBegin();
      it != importElements->_transitionList.constEnd();
      it++)
  {
    if(it->source == nullptr || it->target == nullptr)
      continue;

    QString transitionName;
    transitionName.append("transition_");
    if(!it->source->name().isEmpty())
      transitionName.append(it->source->name());
    transitionName.append("_to_");
    if(!it->target->name().isEmpty())
      transitionName.append(it->target->name());

    //check if transition name is unique
    int count = 2;
    QString tmpString("");
    bool duplicateName;
    do{
      duplicateName = false;
      foreach(QString nameIt, transitionNameList){
        if(nameIt == transitionName + tmpString){
          tmpString = QStringLiteral("_") + QString::number(count);
          count++;
          duplicateName = true;
          break;
        }
      }
    } while(duplicateName);

    transitionName.append(tmpString);
    transitionNameList.append(transitionName);

    TransitionItem* transition;
    SignalTriggerItem* signalTrigger;

    if(it->source->stateType() == Junction){
      //creating junction transition
      JunctionStateItem* junctionItem = static_cast<JunctionStateItem*>(it->source);
      transition = junctionItem->addJunctionTransition(transitionName,
                                                       it->target,
                                                       it->guard,
                                                       it->action,
                                                       QUuid::createUuid(),
                                                       errorMessage);
    }
    else{
      //creating signal transition
      const SignalItem* signal = smModel->signal(it->signal);
      if(!signal)
        signalTrigger = nullptr;
      else
      {
        const PortItem* port = smModel->port(QStringLiteral("defaultPort"));
        Q_ASSERT(port);
        signalTrigger = new SignalTriggerItem(signal, port);
      }

      transition = new TransitionItem(signalTrigger,
                                      it->source,
                                      it->target,
                                      it->guard,
                                      it->action);
      transition->setName(transitionName);
      transition->setText(transitionName);

      if(!smModel->addTransition(transition,
                                 errorMessage))
        return false;
    }

    if(!transition)
      return false;

    importElements->importTransitionLayout(transition,
                                           it->transition,
                                           errorMessage);
  }

  return true;
}

//convert rhapsody events to mobata statemachine signals
//imports all events for every packages on root level
//additionally imports events in subpackage that contains statechart
bool ImportRhapsodyProp::importRhapsodyEvents(IRPProjectPtr& rhapsodyProject,
                                              StateMachineModel* smModel,
                                              ImportRhapsodyElements* importElements,
                                              QString* errorMessage)
{
  Q_ASSERT(this->_d->_rhapsodyStatechart);
  Q_ASSERT(smModel);

  HRESULT hr;
  IRPCollectionPtr collection;
  IRPPackagePtr localPackage;
  VARIANT variant;
  long count;

  hr = rhapsodyProject->get_packages(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get package collection in rhapsody project."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of packages in rhapsody project."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody package item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPPackage, (void**)&localPackage);

    if(!importElements->importEvent(smModel,
                                    localPackage,
                                    errorMessage))
      return false;
  }

  //import events of package which contains statechart of interest
  if(this->_d->_statechartPackage != nullptr)
    if(!importElements->importEvent(smModel,
                                    this->_d->_statechartPackage,
                                    errorMessage))
      return false;

  return true;
}

//convert rhapsody dataTypes to mobata statemachine signals
//imports all dataTypes from every packages on root level
//additionally imports dataTypes in subpackage that contains statechart
bool ImportRhapsodyProp::importRhapsodyDataTypes(IRPProjectPtr& rhapsodyProject,
                                                 StateMachineModel* smModel,
                                                 ImportRhapsodyElements* importElements,
                                                 QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(this->_d->_statechartPackage);

  HRESULT hr;
  IRPCollectionPtr packageCollection, classifierCollection;
  IRPPackagePtr localPackage;
  VARIANT variant;
  long count;

  hr = rhapsodyProject->get_packages(&packageCollection);
  if(hresultFailed2(packageCollection, hr, errorMessage, "Failed to get package collection in rhapsody project."))
    return false;

  hr = packageCollection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of packages in rhapsody project."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = packageCollection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody package item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPPackage, (void**)&localPackage);

    hr = localPackage->get_types(&classifierCollection);
    if(hresultFailed2(classifierCollection, hr, errorMessage, "Failed to get list of all dataTypes in rhapsody project."))
      return false;

    if(!importElements->importDataType(smModel,
                                       classifierCollection,
                                       errorMessage))
      return false;
  }

  //import events of package which contains statechart of interest
  if(this->_d->_statechartPackage != nullptr){
    //Object _statechartClass of class IRPClass has no method get_type()
    hr = this->_d->_statechartClass->get_nestedClassifiers(&classifierCollection);
    if(hresultFailed2(classifierCollection, hr, errorMessage, "Failed to get list of all dataTypes in rhapsody project."))
      return false;
    if(!importElements->importDataType(smModel,
                                       classifierCollection,
                                       errorMessage))
      return false;
  }

  return true;
}

//get all attributes from current rhapsody project and convert them to mobata statemachine attributes
bool ImportRhapsodyProp::importRhapsodyAttributes(StateMachineModel* smModel,
                                                  ImportRhapsodyElements* importElements,
                                                  QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(this->_d->_statechartClass);

  if(!importElements->importAttribute(smModel,
                                      this->_d->_statechartClass,
                                      errorMessage))
    return false;

  return true;
}

//get all operations from current rhapsody project and convert them to mobata statemachine functions
bool ImportRhapsodyProp::importRhapsodyOperations(StateMachineModel* smModel,
                                                  ImportRhapsodyElements* importElements,
                                                  QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(this->_d->_statechartClass);

  if(!importElements->importOperation(smModel,
                                      this->_d->_statechartClass,
                                      errorMessage))
    return false;

  return true;
}

//get all ports from current rhapsody project and convert them to mobata statemachine ports
bool ImportRhapsodyProp::importRhapsodyPorts(StateMachineModel* smModel,
                                             ImportRhapsodyElements* importElements,
                                             QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(this->_d->_statechartClass);

  if(!importElements->importPort(smModel,
                                 this->_d->_statechartClass,
                                 errorMessage))
    return false;

  return true;
}

void ImportRhapsodyProp::receiveResultData(IStream *appStream, IStream *projectStream, bool error)
{
  this->_d->_eventError = error;
  this->_d->_appStream = appStream;
  this->_d->_projectStream = projectStream;

  emit stopWorker();
}

} // namespace rhapsody
