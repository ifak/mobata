#include "placearc.hpp"

#include "placeitem.hpp"

namespace model{
namespace spenat{

class PlaceArc::Private
{
	friend class PlaceArc;
	
public:
	Private() : _place(0)
	{}
	~Private()
	{}
	
private:
	PlaceItem const* _place;
};

PlaceArc::PlaceArc(const QUuid &uuid)
	:	ModelItem(uuid), _d(new Private())
{}

PlaceArc::~PlaceArc()
{}

PlaceItem const* PlaceArc::place() const
{
	return this->_d->_place;
}

void PlaceArc::setPlace(PlaceItem const* place)
{
	this->_d->_place=place;
	
	return;
}

QString PlaceArc::toString() const
{
	if(this->_d->_place)
		return this->_d->_place->name();

	return QLatin1String("");
}

} // namespace model
} // namespace spenat
