#include "typedeclaration.hpp"

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

TypeDeclaration::TypeDeclaration() : typeEnum(Int), name(""), lowest(""), highest(""),
	_uuid(createUuid())
{}
	
TypeDeclaration::TypeDeclaration(const TypeDeclaration& other) 
	: typeEnum(other.typeEnum), name(other.name), lowest(other.lowest), highest(other.highest),
		literals(other.literals), _uuid(other._uuid)
{}

TypeDeclaration::~TypeDeclaration()
{}

TypeDeclaration& TypeDeclaration::operator=(const TypeDeclaration &other)
{
	if(this!=&other)
	{
		this->typeEnum=other.typeEnum;
		this->name=other.name;
		this->lowest=other.lowest;
		this->highest=other.highest;
		this->literals=other.literals;
		this->_uuid=other._uuid;
	}
	
	return *this;
}

bool TypeDeclaration::isSemanticallyEqual(const TypeDeclaration& other) const
{
	if(this->typeEnum != other.typeEnum)
		return false;
	
	if(this->lowest != other.lowest)
		return false;
	
	if(this->highest != other.highest)
		return false;
	
	if(this->literals.size() != other.literals.size())
		return false;
	
	foreach(const QString& literal, this->literals)
	{
		if(std::find(other.literals.begin(),
								 other.literals.end(),
								 literal) == other.literals.end())
			return false;
	}
	
	return true;
}

void TypeDeclaration::reset()
{
	this->typeEnum=Int;
	this->name="";
	this->lowest="";
	this->highest="";
	this->literals.clear();
	this->_uuid=createUuid();
}
	
UuidType TypeDeclaration::uuid() const
{
	return this->_uuid;
}

}//end namespace decl

}//end namespace parser
