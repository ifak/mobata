#ifndef VIEW_SPENAT_COMREADDECLGRAPH_HPP
#define VIEW_SPENAT_COMREADDECLGRAPH_HPP

#include "../../modeling_global.hpp"

#include <QByteArray>
#include <QScopedPointer>

namespace model{ namespace spenat{
class DeclModel;
}}

namespace view
{

namespace spenat{

class DeclScene;

class MODELINGSHARED_EXPORT ComReadDeclGraph
{
public:
  ComReadDeclGraph(const QByteArray& graphJsonData,
                   model::spenat::DeclModel* declModel,
                   DeclScene* graphScene);
  virtual ~ComReadDeclGraph();

public:
  bool execute(QString* errorString);

private:
  Q_DISABLE_COPY(ComReadDeclGraph)
  class Private;
  QScopedPointer<Private>	_d;
};

}//end namespace spenat

}//end namespace view

#endif // VIEW_SPENAT_COMREADDECLGRAPH_HPP
