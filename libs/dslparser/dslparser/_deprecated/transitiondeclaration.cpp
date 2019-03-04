#include "transitiondeclaration.hpp"

#define QT_NO_KEYWORDS
#include "TransitionLexer.hpp"
#include "TransitionParser.hpp"
#undef QT_NO_KEYWORDS

#include<QObject>

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

TransitionDeclaration TransitionDeclaration::parse(const QString& transitionString)
{
  using namespace declParser;

  TransitionLexer::InputStreamType input((ANTLR_UINT8*)transitionString.toStdString().c_str(),
                                          ANTLR_ENC_UTF8,
                                          transitionString.size(),
                                          0);
  TransitionLexer lxr(&input);
  TransitionParser::TokenStreamType tstream(ANTLR_SIZE_HINT, lxr.get_tokSource() );
  TransitionParser psr(&tstream);

  psr.transition();

  if(lxr.hasException())
    throw std::runtime_error(lxr.get_exception()->get_message());
  if(psr.hasException())
    throw std::runtime_error(psr.get_exception()->get_message());

  return psr.getTransitionDeclaration();
}


TransitionDeclaration::TransitionDeclaration():trigger(""), guard(""), actions("")
{}

TransitionDeclaration::~TransitionDeclaration()
{}

void TransitionDeclaration::reset()
{
  this->trigger="";
  this->guard="";
  this->actions="";
  this->_fromPlaces.clear();
  this->_toPlaces.clear();

  return;
}

void TransitionDeclaration::addSourcePlace(const QString& placeName)
{
  foreach(const QString& existSourcePlace, this->_fromPlaces)
  {
    if(existSourcePlace==placeName)
      throw std::runtime_error(QObject::tr("There is already a source-place '%1'"
                                           "for this transition!")
                               .arg(placeName)
                               .toStdString());
  }

  this->_fromPlaces.push_back(placeName);

  return;
}

const QStringList& TransitionDeclaration::sourcePlaces() const
{
  return this->_fromPlaces;
}

void TransitionDeclaration::addTargetPlace(const QString& placeName)
{
  foreach(const QString& existTargetPlace, this->_toPlaces)
  {
    if(existTargetPlace==placeName)
      throw std::runtime_error(QObject::tr("There is already a target-place '%1'"
                                           " for this transition!")
                               .arg(placeName)
                               .toStdString());
  }

  this->_toPlaces.push_back(placeName);

  return;
}

const QStringList& TransitionDeclaration::targetPlaces() const
{
  return this->_toPlaces;
}

QString TransitionDeclaration::labelString() const
{
  QString declaration="";

  if(!this->trigger.isEmpty()
     || !this->guard.isEmpty()
     || !this->actions.isEmpty())
  {
    if(!this->trigger.isEmpty())
      declaration+=this->trigger;

    if(!this->guard.isEmpty())
    {
      declaration+="[";
      declaration+=this->guard;
      declaration+="]";
    }

    if(!this->actions.isEmpty())
    {
      declaration+="/";
      declaration+=this->actions;
    }
  }

  return declaration;
}

QString TransitionDeclaration::formattedLabelString() const
{
  QString formattedLabelString=this->labelString();
  formattedLabelString.replace("/","/\n");
  formattedLabelString.replace(";",";\n");

  return formattedLabelString;
}

}//end namespace decl

}//end namespace parser
