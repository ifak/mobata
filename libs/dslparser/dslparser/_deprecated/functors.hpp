#ifndef MODEL_SPENAT_FUNCTORS_HPP
#define MODEL_SPENAT_FUNCTORS_HPP

#include "types.hpp"

namespace model{
namespace spenat{

class SpenatBaseModel;

struct BuildTransProperties
{
  bool operator()(const QString& transDeclString,
                  TransitionProperties* transProperties,
                  SpenatBaseModel* spenatModel,
                  QString* errorString);
};

} // namespace spenat
} // namespace model

#endif // MODEL_SPENAT_FUNCTORS_HPP
