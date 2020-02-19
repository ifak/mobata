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
#ifndef VIEW_SPENAT_COMSAVEDECLGRAPH_HPP
#define VIEW_SPENAT_COMSAVEDECLGRAPH_HPP

#include "../../modeling_global.hpp"

#include <fstream>
#include <QScopedPointer>

namespace model{namespace spenat{class DeclModel;}}

namespace view
{
namespace spenat
{
class DeclScene;

class MODELINGSHARED_EXPORT ComSaveDeclGraph
{
public:
  ComSaveDeclGraph(model::spenat::DeclModel const* declModel,
                   DeclScene const* graphScene,
                   std::ofstream&	graphOutputStream);
  virtual ~ComSaveDeclGraph();

public:
  bool execute(QString* errorString);

private:
  Q_DISABLE_COPY(ComSaveDeclGraph)
  class Private;
  QScopedPointer<Private>	_d;
};

}//end namespace spenat
}//end namespace view

#endif // VIEW_SPENAT_COMSAVEDECLGRAPH_HPP
