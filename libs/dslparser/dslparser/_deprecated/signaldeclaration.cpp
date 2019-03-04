#include "signaldeclaration.hpp"

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

SignalDeclaration::SignalDeclaration()
{}
	
SignalDeclaration::~SignalDeclaration()
{}

QString SignalDeclaration::toString() const
{
	QString signalString=this->signalName;
	
	int pos=0;
	foreach(const Parameter& parameter, this->parameters)
	{
		if(pos==0)
			signalString+="(";
		else
			signalString+=",";
		
		signalString+=parameter.name;
		
		++pos;
	}
	if(pos)
		signalString+=")";
	
	return signalString;
}

bool isSemanticallyEqual(const SignalDeclaration& orig,
												 const SignalDeclaration& other)
{
	if(orig.signalName!=other.signalName)
		return false;
	
	if(orig.parameters.size()!=other.parameters.size())
		return false;
	
	int pos=0;
	foreach(const Parameter& parameter, orig.parameters)
	{
		const Parameter& otherParameter=other.parameters.at(pos);
		if(parameter.typeUuid!=otherParameter.typeUuid)
			return false;
	}
	
	return true;
}

}//end namespace decl

}//end namespace parser
