#include "triggerdeclaration.hpp"

#define QT_NO_KEYWORDS
#include "TriggerLexer.hpp"
#include "TriggerParser.hpp"
#undef QT_NO_KEYWORDS

#include "../../memory_leak_start.hpp"

namespace parser
{

namespace decl
{

TriggerDeclaration::TriggerDeclaration()	:	signalName(""), portName("")
{}
	
TriggerDeclaration::~TriggerDeclaration()
{}

void TriggerDeclaration::addParam(const TypeDeclaration &type, const QString &name)
{
	this->parameters.push_back(Param(type, name));
	
	return;
}

QString TriggerDeclaration::toString() const
{
	QString signalString=this->signalName;
	
	int pos=0;
	foreach(const Param& param, this->parameters)
	{
		if(pos==0)
			signalString+="(";
		else
			signalString+=",";
		
		signalString+=param.type.name;
		signalString+=" "+param.name;
		
		++pos;
	}
	if(pos)
		signalString+=")";
	
	return signalString;
}

//TriggerDeclaration TriggerDeclaration::parse(const QString &triggerString)
//{
//	using namespace declParser;
	
//	TriggerLexer::InputStreamType input((ANTLR_UINT8*)triggerString.toStdString().c_str(),
//																			 ANTLR_ENC_UTF8,
//																			 triggerString.size(),
//																			 0);
//	TriggerLexer lxr(&input);
//	TriggerParser::TokenStreamType tstream(ANTLR_SIZE_HINT, lxr.get_tokSource() );
//	TriggerParser psr(&tstream);
	
//	psr.trigger();
	
//	if(lxr.hasException())
//		throw std::runtime_error(lxr.get_exception()->get_message());
//	if(psr.hasException())
//		throw std::runtime_error(psr.get_exception()->get_message());
	
//	return psr.getTriggerDeclaration();
//}

TriggerDeclaration TriggerDeclaration::parse(const QString &triggerString)
{
  QString declTriggerString=triggerString.trimmed();

  QStringList triggerTokenList= declTriggerString.split(QRegExp("\\W+"), QString::SkipEmptyParts);

  int size=triggerTokenList.count();
  if(!(size==1 || size==3))
    throw std::runtime_error(std::string("trigger declaration '"
                                         + triggerString.toStdString()
                                         +"' is not sufficient!"));

  TriggerDeclaration triggerDeclaration;
  if(size==1)
  {
    triggerDeclaration.signalName=triggerTokenList.at(0);
    triggerDeclaration.type=EventTrigger;
  }
  else if(size==3)
  {
    if(triggerTokenList.at(0)==QStringLiteral("after"))
    {
      triggerDeclaration.timeout=triggerTokenList.at(2).toInt();
      triggerDeclaration.timeoutUnit=triggerTokenList.at(2);
      triggerDeclaration.type=TimeoutTrigger;
    }
    else
    {
      triggerDeclaration.signalName=triggerTokenList.at(0);
      triggerDeclaration.portName=triggerTokenList.at(2);
      triggerDeclaration.type=EventTrigger;
    }
  }

  return triggerDeclaration;
}

}//end namespace decl

}//end namespace parser
