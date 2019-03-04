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
