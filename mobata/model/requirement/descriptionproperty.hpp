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
#ifndef PROP_DESCRIPTIONPROPERTY_HPP
#define PROP_DESCRIPTIONPROPERTY_HPP

#include "../../mobata_global.hpp"

#include <QString>

namespace prop{

  class MOBATASHARED_EXPORT DescriptionProperty
  {
  public:
    DescriptionProperty(const QString& description=QLatin1String(""))
      : _description(description)
    {}
    virtual ~DescriptionProperty()
    {}

  public:
    const QString& description() const
    {
      return this->_description;
    }

    void setDescription(const QString& description)
    {
      this->_description = description;

      return;
    }

  protected:
    QString _description;
  };

}/// namespace Prop

#endif // PROP_DESCRIPTIONPROPERTY_HPP
