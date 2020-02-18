#include "importrhapsodyutils.hpp"

template<typename NumberType>
bool hresultFailed(const HRESULT& hr,
                   QString* errorMessage,
                   const NumberType number)
{
  if (FAILED(hr)){
    utils::AddPtrString(errorMessage) << number;
    return true;
  }
  else
    return false;
}

template<class PointerType, typename NumberType>
bool hresultFailed2(const PointerType pointerType,
                    const HRESULT& hr,
                    QString* errorMessage,
                    const NumberType number)
{
  if ((FAILED(hr) || pointerType == nullptr) && errorMessage != nullptr){
    utils::AddPtrString(errorMessage) << number;
    return true;
  }
  else
    return false;
}
