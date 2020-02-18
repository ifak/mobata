#include "mscloopfragmentitem.hpp"

namespace model {
namespace msc {

class MscLoopFragmentItem::Private
{
  friend class MscLoopFragmentItem;

  Private(const QString cond)
    : _cond(cond)
  {}
  const QString _cond;
public:
  ~Private(){

  }
};

MscLoopFragmentItem::MscLoopFragmentItem(const QString cond)
  :MscFragmentItem(LoopFragment),_d(new Private(cond)){
  this->addRegion(cond);
}

MscLoopFragmentItem::~MscLoopFragmentItem()
{}

const QString& MscLoopFragmentItem::condition() const{
  return _d->_cond;
}

MscFragmentRegionItem* MscLoopFragmentItem::region()
{
  Q_ASSERT(regions().size());
  return regions().at(0);
}

}
}
