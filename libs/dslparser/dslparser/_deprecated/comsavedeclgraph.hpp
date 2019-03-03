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
