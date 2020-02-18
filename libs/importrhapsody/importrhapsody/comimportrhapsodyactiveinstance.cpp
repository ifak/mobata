#include "comimportrhapsodyactiveinstance.hpp"
#include "importrhapsodyutils.hpp"

namespace rhapsody {

ComImportRhapsodyActiveInstance::ComImportRhapsodyActiveInstance()
  : ImportRhapsodyProp()
{

}

ComImportRhapsodyActiveInstance::~ComImportRhapsodyActiveInstance()
{
}

bool ComImportRhapsodyActiveInstance::execute(QString* errorMessage)
{
  if(!this->initCom(errorMessage))
    return false;

  IRPProjectPtr ptr;
  if(!this->loadRhapsodyProjectInstance(ptr, errorMessage))
    return false;

  return true;
}

} //end of namespace rhapsody
