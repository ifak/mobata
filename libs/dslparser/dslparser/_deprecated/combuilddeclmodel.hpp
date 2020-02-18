/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
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
