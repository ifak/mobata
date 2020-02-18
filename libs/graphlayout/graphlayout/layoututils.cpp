#include "layoututils.hpp"
#include "layoutnode.hpp"

namespace graphlayout {

QString recursiveNodeName(LayoutNode const* node)
{
  QString path = node->name();
  LayoutNode* parentNode = node->parentNode();
  while(parentNode != nullptr){
    path.prepend(QStringLiteral("."));
    path.prepend(parentNode->name());
    parentNode = parentNode->parentNode();
  }

  return path;
}

} //end of namespace graphlayout
