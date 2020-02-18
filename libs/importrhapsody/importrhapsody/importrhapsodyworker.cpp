#include "importrhapsodyworker.hpp"
#include "importrhapsodyutils.hpp"

using namespace rhapsody;

class ImportRhapsodyWorker::Private
{
  friend class ImportRhapsodyWorker;
  QString _projectFilePath;
  IStream* _appStream;
  IStream* _projectStream;

  Private(const QString& projectFilePath)
    : _projectFilePath(projectFilePath)
  {}
};

ImportRhapsodyWorker::ImportRhapsodyWorker(const QString& projectFilePath)
    : _d(new Private(projectFilePath))
{}

ImportRhapsodyWorker::~ImportRhapsodyWorker()
{
  delete _d;
}

void ImportRhapsodyWorker::startRhapsody(QString *errorMessage)
{
  HRESULT hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED );
  if(hresultFailed(hr, errorMessage, "Failed to initialize COM."))
    return;

  bool retVal = !this->process(errorMessage);
  emit sendResultData(this->_d->_appStream, this->_d->_projectStream, retVal);

  CoUninitialize();
}

bool ImportRhapsodyWorker::process(QString *errorMessage)
{
  HRESULT hr;
  CLSID clsid;
  IRPApplicationPtr appPtr;
  IRPProjectPtr projectPtr;

  hr = CLSIDFromProgID(OLESTR("Rhapsody.Application"), &clsid);
  if(hresultFailed(hr, errorMessage, "Could not get CLSID of rhapsody."))
    return false;

  // Create CoClass instance from ClassId, using dispatch iid
  hr = CoCreateInstance( clsid, NULL, CLSCTX_ALL, IID_IRPApplication, (void**)&appPtr );
  if(hresultFailed2(appPtr, hr, errorMessage, "Could not open a new rhapsody instance."))
    return false;

  //load projectfile if given
  std::string tempString = this->_d->_projectFilePath.toStdString();
  const char* filename = tempString.c_str();
  Q_ASSERT(filename);
  int len = MultiByteToWideChar(CP_ACP, 0, filename, static_cast<int>(strlen(filename)), NULL, NULL);
  BSTR projectFileName = SysAllocStringLen(NULL, len);
  MultiByteToWideChar(CP_ACP, 0, filename, static_cast<int>(strlen(filename)), projectFileName, len);
  hr = appPtr->openProject(projectFileName, &projectPtr);
  SysFreeString(projectFileName);
  if(hresultFailed2(projectPtr, hr, errorMessage, "Could not get project of rhapsody instance."))
    return false;

  IUnknownPtr rhpunk = 0;
  hr = CoMarshalInterThreadInterfaceInStream(IID_IRPApplication, appPtr, &this->_d->_appStream);
  if(hresultFailed2(this->_d->_appStream, hr, errorMessage, "Could not marshal pointer of rhapsody application."))
    return false;

  rhpunk = 0;
  hr = CoMarshalInterThreadInterfaceInStream(IID_IRPProject, projectPtr, &this->_d->_projectStream);
  if(hresultFailed2(this->_d->_projectStream, hr, errorMessage, "Could not marshal pointer of rhapsody project."))
    return false;

  return true;
}
