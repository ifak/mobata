#include "functors.hpp"

#include "signaltriggeritem.hpp"
#include "timeouttriggeritem.hpp"
#include "spenatbasemodel.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

using namespace utils;

namespace model{
namespace spenat{

bool BuildTransProperties::operator()(const QString& transDeclString,
                                      TransitionProperties* transProperties,
                                      SpenatBaseModel* spenatModel,
                                      QString* errorString)
{
  Q_ASSERT(transProperties);
  Q_ASSERT(spenatModel);

  QString triggerString(QStringLiteral(""));
  QString guardString(QStringLiteral(""));
  QString actionString(QStringLiteral(""));

  int leftBracketPos=transDeclString.indexOf(QLatin1String("["));
  int rightBracketPos=transDeclString.indexOf(QLatin1String("]"));
  int slashPos=transDeclString.indexOf(QLatin1String("/"));

  if(leftBracketPos>=0)
  {
    if(rightBracketPos<=leftBracketPos)
    {
      AddPtrString(errorString)<<QString(QStringLiteral("wrong format of transition declaration '%1'"
                                                        " it should be trigger[guard]/actions"))
                                 .arg(transDeclString);
      return false;
    }

    triggerString=transDeclString.mid(0,leftBracketPos).trimmed();
    guardString=transDeclString.mid(leftBracketPos+1,
                                    rightBracketPos-(leftBracketPos+1)).trimmed();
    if(slashPos>=0)
    {
      if(slashPos<=rightBracketPos)
      {
        AddPtrString(errorString)<<QString(QStringLiteral("wrong format of transition declaration '%1'"
                                                          " it should be trigger[guard]/actions"))
                                   .arg(transDeclString);
        return false;
      }

      actionString=transDeclString.mid(slashPos+1,
                                       transDeclString.length()
                                       -(slashPos+1)).trimmed();
    }
  }
  else if(slashPos>=0)
  {
    triggerString=transDeclString.mid(0,slashPos).trimmed();
    actionString=transDeclString.mid(slashPos+1,
                                     transDeclString.length()
                                     -(slashPos+1)).trimmed();
  }
  else
    triggerString=transDeclString.trimmed();

  if(!triggerString.isEmpty())
  {
    TriggerDeclaration triggerDecl=TriggerDeclaration::parse(triggerString);
    if(triggerDecl.type==parser::decl::EventTrigger)
    {
      base::SignalItem const* triggerSignal=spenatModel->signal(triggerDecl.signalName);
      base::PortItem const* triggerPort = 0;
      if(!triggerSignal)
      {
        AddPtrString(errorString) << QString(QStringLiteral("signal '%1' for trigger '%2' "
                                                            "could not be found!"))
                                     .arg(triggerDecl.signalName)
                                     .arg(triggerString);
        return false;
      }
      if(!triggerDecl.portName.isEmpty())
      {
        triggerPort=spenatModel->port(triggerDecl.portName);
        if(!triggerPort)
        {
          AddPtrString(errorString) <<QString(QStringLiteral("port '%1' for trigger '%2' "
                                                             "could not be found!"))
                                      .arg(triggerDecl.portName)
                                      .arg(triggerString);
          return false;
        }
      }
      transProperties->trigger.reset(new SignalTriggerItem(triggerSignal,
                                                           triggerPort));
    }
    else if(triggerDecl.type==parser::decl::TimeoutTrigger)
    {
      bool result;
      double timeoutValue = triggerDecl.timeout.toDouble(&result);
      if(!result)
      {
        AddPtrString(errorString) << QString(QStringLiteral("timout valur '%1' for trigger '%2' "
                                                            "is not a real value!"))
                                     .arg(triggerDecl.timeout)
                                     .arg(triggerString);
        return false;
      }
      if(triggerDecl.timeoutUnit == "s")
        timeoutValue*=1000;
      else if(triggerDecl.timeoutUnit == "min")
        timeoutValue*=1000*60;
      else if(triggerDecl.timeoutUnit == "h")
        timeoutValue*=1000*60*60;
      else if(triggerDecl.timeoutUnit == "ns")
        timeoutValue*=0.001;

      transProperties->trigger.reset(new TimeoutTriggerItem(timeoutValue));
    }
  }
  else
    transProperties->trigger.reset();

  transProperties->guard=guardString.trimmed();
  transProperties->actions=actionString.trimmed();

  return true;
}

}///end namespace spenat
}///end namespace model
