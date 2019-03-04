/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#pragma once

#include "../../mobata_global.hpp"

#include <QVector>
#include <QMap>

namespace model{

namespace base{

class ModelItem;
class DataTypeItem;
class SignalItem;
class PortItem;
class AttributeItem;
class ParamItem;
}

namespace spenat{

using namespace base;

class SpenatModel;
class SpenatDeclModel;

class PlaceItem;
class TransitionItem;

class MOBATASHARED_EXPORT Spenat2DeclMapping
{
	typedef QVector<ModelItem const*>													ConstModelItems;
	
  typedef QMap<DataTypeItem const*, DataTypeItem const*>						TypeMappings;
	typedef QMap<SignalItem const*, SignalItem const*>				SignalMappings;
	typedef QMap<PortItem const*, PortItem const*>						PortMappings;
	typedef QMap<AttributeItem const*, AttributeItem const*>	AttributeMappings;
	typedef QMap<PlaceItem const*, PlaceItem const*>				PlaceMappings;
	typedef QMap<TransitionItem const*, ConstModelItems>			TransitionMappings;
	
public:
	Spenat2DeclMapping(SpenatModel const* spenatModel,
											SpenatDeclModel const* declModel);
	virtual ~Spenat2DeclMapping();
	
public:
  void addTypeMapping(DataTypeItem const* spenatType, DataTypeItem const* declType);
	void addSignalMapping(SignalItem const* spenatSignal, SignalItem const* declSignal);
	void addPortMapping(PortItem const* spenatPort, PortItem const* declPort);
	void addAttributeMapping(AttributeItem const* spenatAttribute, 
													 AttributeItem const* declAttribute);
	void addPlaceMapping(PlaceItem const* spenatPlace, PlaceItem const* declPlace);
	void addTransitionMapping(TransitionItem const* spenatTransition, 
														ModelItem const* declModelItem);

protected:
	SpenatModel const*	_spenatModel;
	SpenatDeclModel const*		_declModel;
	
protected:
	TypeMappings				_typeMappings;
	SignalMappings			_signalMappings;
	PortMappings				_portMappings;
	AttributeMappings		_attributeMappings;
	PlaceMappings				_placeMappings;
	TransitionMappings	_transitionMappings;
};

}/// namespace spenat
}/// namespace model
