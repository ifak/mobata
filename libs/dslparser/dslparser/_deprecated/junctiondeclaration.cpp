#include "junctiondeclaration.hpp"

#include <QObject>

#include <stdexcept>

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

JunctionDeclaration::JunctionDeclaration() : _source(""), _trigger("")
{}

JunctionDeclaration::~JunctionDeclaration()
{}

bool JunctionDeclaration::operator ==(const JunctionDeclaration &other) const
{
	if(this->_source!=other._source)
		return false;
	if(this->_trigger!=other._trigger)
		return false;
	if(this->_targets.size()!=other._targets.size())
		return false;
	
	foreach(const JunctionTarget& target, this->_targets)
	{
		bool success=false;
		foreach(const JunctionTarget& otherTarget, other._targets)
		{
			if(target.targetPlace==otherTarget.targetPlace
				 && target.guard == otherTarget.guard
				 && target.actions == otherTarget.actions)
			{
				success=true;
				break;
			}
		}
		if(!success)
			return false;
	}
	
	return true;
}

void JunctionDeclaration::reset()
{
	this->_source="";
	this->_trigger="";
	this->_targets.clear();
	
	return;
}

void JunctionDeclaration::setSource(const QString &placeName)
{
	this->_source=placeName;
	
	return;
}

void JunctionDeclaration::setTrigger(const QString &triggerString)
{
	this->_trigger=triggerString;
	
	return;
}

const QString &JunctionDeclaration::getSource() const
{
	return this->_source;
}

const QString &JunctionDeclaration::getTrigger() const
{
	return this->_trigger;
}

void JunctionDeclaration::addTarget(const QString &placeName, 
																		const QString &guardString, 
																		const QString &actionString)
{
	foreach(const JunctionTarget& existTarget, this->_targets)
		if(existTarget.targetPlace==placeName
			 && existTarget.guard==guardString)
			throw std::runtime_error(QObject::tr("There is already a junction-target for place '%1'"
                                           " with guard '%2'!")
                               .arg(placeName)
                               .arg(guardString)
                               .toStdString());
	
	this->_targets.push_back(JunctionTarget(placeName, guardString, actionString));
	
	return;
}

void JunctionDeclaration::addTarget(const JunctionTarget &target)
{
	foreach(const JunctionTarget& existTarget, this->_targets)
			if(existTarget.targetPlace==target.targetPlace
				 && existTarget.guard==target.guard)
				throw std::runtime_error(QObject::tr("There is already a junction-target "
                                             "for place '%1' with guard '%2'!")
                                 .arg(target.targetPlace)
                                 .arg(target.guard)
                                 .toStdString());
	
	this->_targets.push_back(target);
	
	return;
}

const JunctionDeclaration::JunctionTargetSet &JunctionDeclaration::getTargets() const
{
	return this->_targets;
}

QString JunctionDeclaration::toString() const
{
	QString decl="junction from '"+this->_source+"'";
	if(!this->_trigger.isEmpty())
		decl+=" with '"+this->_trigger+"'";
	if(this->_targets.size())
	{
		foreach(const JunctionTarget& target, this->_targets)
			decl+=target.toString();
	}
	
	return decl;
}

}// end namespace decl

}//end namespace parser
