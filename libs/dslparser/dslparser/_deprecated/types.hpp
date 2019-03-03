#ifndef PARSER_DECL_TYPES_HPP
#define PARSER_DECL_TYPES_HPP

#include <string>
#include <vector>
#include <set>

#include <QUuid>

namespace parser
{

namespace decl
{
	typedef QUuid UuidType;
	static inline UuidType createUuid() {return QUuid::createUuid();}
	
enum TypeEnum
{
	Bool,
	Enum,
	Int,
	Real,
	String
};

enum TriggerTypeEnum
{
	EventTrigger,
	TimeoutTrigger
};


inline
QString typeEnum2String(TypeEnum typeEnum)
{
	if(typeEnum==Bool)
			return QLatin1String("bool");
	else if(typeEnum==Enum)
		return QLatin1String("enum");
	else if(typeEnum==Int)
		return QLatin1String("int");
	else if (typeEnum==Real)
		return QLatin1String("real");
	else if(typeEnum==String)
		return QLatin1String("string");
	
	return QLatin1String("unknown");
}

inline
QString triggerTypeEnum2String(TriggerTypeEnum typeEnum)
{
	if(typeEnum==EventTrigger)
			return QLatin1String("EventTrigger");
	else if(typeEnum==TimeoutTrigger)
		return QLatin1String("TimeoutTrigger");
	
	return QLatin1String("unknown");
}

}//end namespace decl

}//end namespace parser

#endif // TYPES_HPP
