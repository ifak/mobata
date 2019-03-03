#ifndef PARSER_DECL_TRIGGERDECLARATION_HPP
#define PARSER_DECL_TRIGGERDECLARATION_HPP

#include "../../modeling_global.hpp"

#include "types.hpp"
#include "typedeclaration.hpp"

#define QT_NO_KEYWORDS
#include <QVector>
#undef QT_NO_KEYWORDS

namespace parser{
namespace decl{

class MODELINGSHARED_EXPORT TriggerDeclaration
{
public:
	struct Param
	{
    Param() : type(), name(QLatin1String(""))
    {}
		Param(const TypeDeclaration& t, const QString& n)
			: type(t), name(n)
		{}
		TypeDeclaration type;
		QString         name;
	};

public:
	typedef QVector<Param> ParameterSet;
	
public:
	TriggerDeclaration();
	virtual ~TriggerDeclaration();
	
public:
	static TriggerDeclaration parse(const QString& triggerString);
	
public:
	QString toString() const;
	void addParam(const TypeDeclaration& type, const QString& name);

public:
	TriggerTypeEnum type;
	QString         timeout;
	QString         timeoutUnit;
	QString         signalName;
	QString         portName;
	ParameterSet    parameters;
};

}//end namespace decl

}//end namespace parser

#endif // PARSER_DECL_TRIGGERDECLARATION_HPP
