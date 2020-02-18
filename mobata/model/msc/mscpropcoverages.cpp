#include "mscpropcoverages.hpp"

namespace model {
namespace msc {

MscPropCoverages::MscPropCoverages()
{}

MscPropCoverages::MscPropCoverages(const MscPropCoverages& orig)
  : _coverageItems(orig._coverageItems)
{}

MscPropCoverages::~MscPropCoverages()
{}

void  MscPropCoverages::addCoverageItem(const MscCoverageItem& coverageItem)
{
  this->_coverageItems.push_back(coverageItem);

  return;
}

void  MscPropCoverages::addCoverageItem(const QString& name,
                                        const QUuid& uuid,
                                        const MscCoverageType coverageType)
{
  this->_coverageItems.push_back(MscCoverageItem(name, uuid, coverageType));

  return;
}

const MscPropCoverages::CoverageItemSet&  MscPropCoverages::coverageItems() const
{
  return this->_coverageItems;
}

void  MscPropCoverages::resetCoverageItems()
{
  this->_coverageItems.clear();

  return;
}

} // namespace msc
} // namespace model
