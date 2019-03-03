#ifndef PARSER_DECL_SIGNALDECLARATION_HPP
#define PARSER_DECL_SIGNALDECLARATION_HPP

#include "../../modeling_global.hpp"

#include "types.hpp"
#include "parameter.hpp"

#include <QVector>

namespace parser
{

namespace decl
{

class MODELINGSHARED_EXPORT SignalDeclaration
{
public:
	typedef QVector<Parameter> ParameterSet;
	
public:
	SignalDeclaration();
	virtual ~SignalDeclaration();
	
public:
	friend bool isSemanticallyEqual(const SignalDeclaration& orig,
																	const SignalDeclaration& other);
	QString toString() const;

public:
	QString		signalName;
	ParameterSet	parameters;
};

}//end namespace decl

}//end namespace parser

#endif // PARSER_DECL_SIGNALDECLARATION_HPP
