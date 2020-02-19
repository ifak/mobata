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
#ifndef PARSER_DECL_TRANSITIONDECLARATION_HPP
#define PARSER_DECL_TRANSITIONDECLARATION_HPP

#include "../../modeling_global.hpp"

#include "types.hpp"

#define QT_NO_KEYWORDS
#include <QStringList>
#undef QT_NO_KEYWORDS

namespace parser
{

namespace decl
{

class MODELINGSHARED_EXPORT TransitionDeclaration
{
public:
  TransitionDeclaration();
  virtual ~TransitionDeclaration();

public:
  static TransitionDeclaration parse(const QString& transitionString);

public:
  void                reset();
  void                addSourcePlace(const QString& placeName);
  const QStringList&	sourcePlaces() const;
  void                addTargetPlace(const QString& placeName);
  const QStringList&  targetPlaces() const;
  QString             labelString() const;
  QString             formattedLabelString() const;

public:
  QString         trigger;
  TriggerTypeEnum triggerType;
  QString         guard;
  QString         actions;

private:
  QStringList	_fromPlaces;
  QStringList	_toPlaces;
};

}//end namespace decl

}//end namespace parser

#endif // PARSER_DECL_TRANSITIONDECLARATION_HPP
