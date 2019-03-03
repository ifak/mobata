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

#include "spenat2declmapping.hpp"

namespace model{
namespace spenat{

Spenat2DeclMapping::Spenat2DeclMapping(const SpenatModel *spenatModel, 
																				 const SpenatDeclModel *declModel)
	:	_spenatModel(spenatModel), _declModel(declModel)
{}

Spenat2DeclMapping::~Spenat2DeclMapping()
{}

void Spenat2DeclMapping::addTypeMapping(DataTypeItem const* spenatType, DataTypeItem const* declType)
{
	if(!(spenatType&&declType))
		return;
	
	this->_typeMappings.insert(spenatType, declType);
	
	return;
}

void Spenat2DeclMapping::addSignalMapping(SignalItem const* spenatSignal, 
																					 SignalItem const* declSignal)
{
	if(!(spenatSignal&&declSignal))
		return;
	
	this->_signalMappings.insert(spenatSignal, declSignal);
	
	return;
}

void Spenat2DeclMapping::addPortMapping(PortItem const* spenatPort, 
																				 PortItem const* declPort)
{
	if(!(spenatPort&&declPort))
		return;
	
	this->_portMappings.insert(spenatPort, declPort);
	
	return;
}

void Spenat2DeclMapping::addAttributeMapping(AttributeItem const* spenatAttribute, 
																							AttributeItem const* declAttribute)
{
	if(!(spenatAttribute&&declAttribute))
		return;
	
	this->_attributeMappings.insert(spenatAttribute, declAttribute);
	
	return;
}

void Spenat2DeclMapping::addPlaceMapping(PlaceItem const* spenatPlace, 
																					PlaceItem const* declPlace)
{
	if(!(spenatPlace&&declPlace))
		return;
	
	this->_placeMappings.insert(spenatPlace, declPlace);
	
	return;
}

void Spenat2DeclMapping::addTransitionMapping(TransitionItem const* spenatTransition, 
																							 ModelItem const* declModelItem)
{
	if(!(spenatTransition&&declModelItem))
		return;
	
	this->_transitionMappings[spenatTransition].append(declModelItem);
	
	return;
}

}///end namespace model
}///end namespace spenat
