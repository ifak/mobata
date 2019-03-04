#include "declarations.hpp"

#include "DeclarationLexer.hpp"
#include "DeclarationParser.hpp"

#include<QObject>

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

Declarations Declarations::parse(const QString& declString)
{
  using namespace declParser;

  try
  {
    DeclarationLexer::InputStreamType input((ANTLR_UINT8*)declString.toStdString().c_str(),
                                            ANTLR_ENC_UTF8,
                                            declString.size(),
                                            0);
    DeclarationLexer lxr(&input);
    DeclarationParser::TokenStreamType tstream(ANTLR_SIZE_HINT, lxr.get_tokSource() );
    DeclarationParser psr(&tstream);

    psr.declarations();

    if(lxr.hasException())
      throw std::runtime_error(lxr.get_exception()->get_message());
    if(psr.hasException())
      throw std::runtime_error(psr.get_exception()->get_message());

    return psr.getDeclarations();
  }
  catch(DeclarationParser::ExceptionBaseType& exc)
  {
    throw std::runtime_error(exc.get_message());
  }
  catch(std::exception& exc)
  {
    throw;
  }
  catch(...)
  {
    throw std::runtime_error("Unknown error during declaration parsing!");
  }
}

bool Declarations::isKeyWord(const QString& text)
{
  if(text=="at" || text=="after" || text=="at" || text=="attribute" || text=="ms" || text=="s"
     || text=="port" || text=="signal" || text=="type" || text=="int" || text=="real"
     || text=="bool" || text=="string" || text=="enum" || text=="inf" || text=="place"
     || text=="transition" || text=="junction" || text=="from" || text=="to" || text=="with"
     || text=="send" || text=="and" || text=="or" || text=="not" || text=="msg" || text=="this"
     || text=="true" || text=="false")
    return true;

  return false;
}

Declarations::Declarations()
{}

UuidType Declarations::addTypeDeclaration(const TypeDeclaration &typeDeclaration)
{
  if(!typeDeclaration.name.isEmpty())
  {
    if(this->getTypeDeclaration(typeDeclaration.name))
      throw std::runtime_error(QObject::tr("There is already a type with name '%1'!")
                               .arg(typeDeclaration.name)
                               .toStdString());

    this->_typeDeclarations.push_back(typeDeclaration);
    return typeDeclaration.uuid();
  }

  foreach(const TypeDeclaration& existTypeDeclaration, this->_typeDeclarations)
  {
    if(existTypeDeclaration.isSemanticallyEqual(typeDeclaration))
      return existTypeDeclaration.uuid();
  }

  this->_typeDeclarations.push_back(typeDeclaration);

  return typeDeclaration.uuid();
}

const Declarations::TypeDeclarationSet &Declarations::getTypeDeclarations() const
{
  return this->_typeDeclarations;
}

TypeDeclaration const* Declarations::getTypeDeclaration(const QString &typeName)
{
  if(typeName.isEmpty())
    return 0;

  foreach(const TypeDeclaration& typeDeclaration, this->_typeDeclarations)
    if(typeDeclaration.name==typeName)
      return &typeDeclaration;

  return 0;
}

TypeDeclaration const* Declarations::getTypeDeclaration(const UuidType &typeUuid)
{
  foreach(const TypeDeclaration& typeDeclaration, this->_typeDeclarations)
    if(typeDeclaration.uuid()==typeUuid)
      return &typeDeclaration;

  return 0;
}

const Declarations::SignalDeclarationSet &Declarations::getSignalDeclarations() const
{
  return this->_signalDeclarations;
}

TypeDeclaration const* detectTypeDeclaration(const TypeDeclaration& triggerParamType,
                                             const Declarations& declarations)
{
  foreach(const TypeDeclaration& typeDecl, declarations.getTypeDeclarations())
  {
    if(!triggerParamType.name.isEmpty())
    {
      if(typeDecl.name==triggerParamType.name)
        return &typeDecl;
    }
    else
    {
      if(typeDecl.isSemanticallyEqual(triggerParamType))
        return &typeDecl;
    }
  }

  return 0;
}

SignalDeclaration const* Declarations::getSignalDeclaration(const TriggerDeclaration &triggerDecl)
{
  foreach(const SignalDeclaration& signalDecl, this->_signalDeclarations)
  {
    if(signalDecl.signalName!=triggerDecl.signalName)
      continue;

    if(signalDecl.parameters.size()!=triggerDecl.parameters.size())
      continue;

    if(signalDecl.parameters.size()==0
       &&triggerDecl.parameters.size()==0)
      return &signalDecl;

    int pos=0;
    bool success=true;
    foreach(const Parameter& signalParam, signalDecl.parameters)
    {
      const TriggerDeclaration::Param& triggerParam=triggerDecl.parameters.at(pos);
      TypeDeclaration const* paramType=detectTypeDeclaration(triggerParam.type, *this);
      if(!paramType)
        throw std::runtime_error(QObject::tr("type for param '%1' "
                                 "of trigger '%2' not found!")
                                 .arg(triggerParam.name)
                                 .arg(triggerDecl.toString())
                                 .toStdString());
      if(signalParam.typeUuid!=paramType->uuid())
      {
        success=false;
        break;
      }

      ++pos;
    }

    if(success)
      return &signalDecl;
  }

  return 0;
}

const Declarations::PortDeclarationSet &Declarations::getPortDeclarations() const
{
  return this->_portDeclarations;
}

const Declarations::AttributeDeclarationSet &Declarations::getAttributeDeclarations() const
{
  return this->_attributeDeclarations;
}

const Declarations::PlaceDeclarationSet &Declarations::getPlaceDeclarations() const
{
  return this->_placeDeclarations;
}

const Declarations::TransitionDeclarationSet &Declarations::getTransitionDeclarations() const
{
  return this->_transitionDeclarations;
}

const Declarations::JunctionDeclarationSet &Declarations::getJunctionDeclarations() const
{
  return this->_junctionDeclarations;
}

//const Declarations::StringSet &Declarations::getInitPlaces() const
//{
//	return this->_initPlaces;
//}

void Declarations::addPortDeclaration(const QString &portName)
{
  foreach(const PortDeclaration& existPortDeclaration, this->_portDeclarations)
    if(existPortDeclaration.name==portName)
      throw std::runtime_error(QObject::tr("There is already a port with name '%1'!")
                               .arg(portName)
                               .toStdString());

  this->_portDeclarations.push_back(PortDeclaration(portName));

  return;
}

void Declarations::addAttributeDeclaration(const AttributeDeclaration &attributeDeclaration)
{
  foreach(const AttributeDeclaration& existAttributeDeclaration, this->_attributeDeclarations)
    if(existAttributeDeclaration.name==attributeDeclaration.name)
      throw std::runtime_error(QObject::tr("There is already an attribute with name '%1'!")
                               .arg(attributeDeclaration.name)
                               .toStdString());

  this->_attributeDeclarations.push_back(attributeDeclaration);

  return;
}

void Declarations::addPlaceDeclaration(const QString &placeName, bool initMarking)
{
  foreach(const PlaceDeclaration& existPlaceDeclaration, this->_placeDeclarations)
    if(existPlaceDeclaration.name==placeName)
      throw std::runtime_error(QObject::tr("There is already a place with name '%1'!")
                               .arg(placeName)
                               .toStdString());

  this->_placeDeclarations.push_back(PlaceDeclaration(placeName,initMarking));

  return;
}

void Declarations::addTransitionDeclaration(const TransitionDeclaration &transitionDeclaration)
{
  this->_transitionDeclarations.push_back(transitionDeclaration);

  return;
}

void Declarations::addJunctionDeclaration(const JunctionDeclaration &junctionDeclaration)
{
  foreach(const JunctionDeclaration& existJunctionDecl, this->_junctionDeclarations)
    if(existJunctionDecl == junctionDeclaration)
      throw std::runtime_error(QObject::tr("There is already a junction with this declaration '%1'!")
                               .arg(junctionDeclaration.toString())
                               .toStdString());

  this->_junctionDeclarations.push_back(junctionDeclaration);

  return;
}

void Declarations::addSignalDeclaration(const SignalDeclaration &signalDeclaration)
{
  foreach(const SignalDeclaration& existSignalDeclaration, this->_signalDeclarations)
  {
    if(isSemanticallyEqual(existSignalDeclaration, signalDeclaration))
      throw std::runtime_error(QObject::tr("There is already a signal with declaration '%1'!")
                               .arg(signalDeclaration.toString())
                               .toStdString());
  }

  this->_signalDeclarations.push_back(signalDeclaration);

  return;
}

}//end namespace decl

}///end namespace parser
