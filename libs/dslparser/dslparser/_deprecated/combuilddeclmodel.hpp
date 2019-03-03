#ifndef MODEL_SPENAT_COMBUILDDECLMODEL_HPP
#define MODEL_SPENAT_COMBUILDDECLMODEL_HPP

#include "../../modeling_global.hpp"

namespace parser{namespace decl{class Declarations;}}

namespace model{
namespace spenat{

class DeclModel;

class MODELINGSHARED_EXPORT ComBuildDeclModel
{
public:
	ComBuildDeclModel(DeclModel *declModel, 
										const parser::decl::Declarations &declText);
	
public:
  bool execute(QString* errorString);

private:	
  bool processText(QString* errorString);
	
private:
  DeclModel*                        _declModel;
  const parser::decl::Declarations& _declText;
};
	
}/// namespace spenat
}///end namespace model

#endif // MODEL_SPENAT_COMBUILDDECLMODEL_HPP
