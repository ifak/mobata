#include "isrdlmodel.hpp"

#include "isrdlitem.hpp"

#include <model/base/attributeitem.hpp>
#include <model/base/datatypeitem.hpp>

#include <model/msc/msccheckmessageitem.hpp>
#include <model/msc/mscfragmentitem.hpp>
#include <model/msc/mscmessageitem.hpp>
#include <model/msc/mscsleeptimeritem.hpp>
#include <model/msc/mscstatementitem.hpp>
#include <model/msc/msctimeoutitem.hpp>
#include <model/msc/msctimeritem.hpp>
#include <model/msc/mscfragmentregionitem.hpp>

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
  namespace isrdl{

    class IsrdlModel::Private
    {
      friend class IsrdlModel;

      Private()
      {}

    public:
      ~Private()
      {}

    private:
    };

    IsrdlModel::IsrdlModel(QObject *parent)
      :	base::BaseModel(parent),
        PropIsrdl(this->invisibleRootItem()),
        _d(new Private)
    {
      this->setName("isrdl_model");

      this->setHeaderData(0, Qt::Horizontal, this->name(), Qt::DisplayRole);
    }

    IsrdlModel::~IsrdlModel()
    {
      delete this->_d;
    }

    void IsrdlModel::reset()
    {
      base::BaseModel::reset();
      this->resetIsrdlItems();
      this->resetSignals();
      this->resetAttributes();


      this->setName("isrdl_model");

      return;
    }
  }///end namespace isrdl
}///end namespace model
