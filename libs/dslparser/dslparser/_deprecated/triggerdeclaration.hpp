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
