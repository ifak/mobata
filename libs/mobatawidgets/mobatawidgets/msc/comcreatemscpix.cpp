#include "comcreatemscpix.hpp"

#include <mobata/model/msc/mscsequence.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/msc/mscstatementitem.hpp>
#include <mobata/model/msc/mscmodel.hpp>

#include "mscwebsequchartclient.hpp"

#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/paramvalueitem.hpp>
#include <mobata/model/base/componentitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>

#include <stdexcept>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class ComCreateMscPix::Private
{
  friend class ComCreateMscPix;

private:
  model::msc::MscSequence const*        _mscSequence;
  MscWebSequChartClient*                _mscWebSequChartClient;
  QVector<model::base::PortItem const*> _lifelinePorts;

private:
  Private(model::msc::MscSequence const* mscSequence)
    :	_mscSequence(mscSequence),
      _mscWebSequChartClient(0)
  {}
  ~Private()
  {}
};

ComCreateMscPix::ComCreateMscPix(model::msc::MscSequence const* mscSequence,
                                 QObject *parent)
  :	QObject(parent), _d(new Private(mscSequence))
{}

ComCreateMscPix::~ComCreateMscPix()
{
  delete this->_d;
}

void processSequence(model::msc::MscSequence const* sequence,
                     QString* sequenceText)
{
  Q_ASSERT(sequence);
  Q_ASSERT(sequenceText);

  foreach(model::msc::MscSequenceItem const* sequenceItem,
          sequence->sequenceItems())
  {
    if(model::msc::MscMessageItem const* messageItem=dynamic_cast<model::msc::MscMessageItem const*>(sequenceItem))
    {
      model::base::PortItem const* sourcePort=messageItem->sourcePort();
      Q_ASSERT(sourcePort);

      model::base::PortItem const* targetPort=messageItem->targetPort();
      Q_ASSERT(targetPort);

      *sequenceText+= sourcePort->toString();
      *sequenceText+="->";
      *sequenceText+=targetPort->toString();
      *sequenceText+=":";

      model::base::SignalItem const* messageSignal=messageItem->signal();
      if(messageSignal)
      {
        *sequenceText += messageSignal->name() + "(";
        int pos=0;
        foreach(model::base::ParamValueItem const* parameter,
                messageItem->paramValues())
        {
          Q_ASSERT(parameter->param());
          if(pos)
            *sequenceText += ", \\n";
          *sequenceText += parameter->param()->name() + "="
              + parameter->value().toString();
          ++pos;
        }
        *sequenceText += ")\n";
      }
      else
      {
        *sequenceText+=messageItem->text()+"\n";
      }
    }
    else if(model::msc::MscTimerItem const* timerItem=dynamic_cast<model::msc::MscTimerItem const*>(sequenceItem))
    {
      model::msc::MscComponentItem const* component=timerItem->component();
      Q_ASSERT(component);

      *sequenceText += component->toString();
      *sequenceText += QStringLiteral("->");
      *sequenceText += component->toString();
      *sequenceText += QStringLiteral(":");
      *sequenceText += QStringLiteral("after ");
      *sequenceText += QStringLiteral("%1").arg(timerItem->value());
      *sequenceText += QStringLiteral("ms;\n");
    }
    else if(model::msc::MscFragmentItem const* fragmentItem=dynamic_cast<model::msc::MscFragmentItem const*>(sequenceItem))
    {
      *sequenceText+=model::msc::fragmentType2string(fragmentItem->fragmentType())
          +QStringLiteral(" ");
      int pos=0;
      foreach(model::msc::MscFragmentRegionItem const* region,
              fragmentItem->regions())
      {
        if(pos)
          *sequenceText+=QLatin1String("else ");
        *sequenceText+=region->condition()
            +QLatin1String("\n");
        processSequence(region, sequenceText);

        ++pos;
      }
      *sequenceText += "end\n";
    }
    else if(model::msc::MscStatementItem const* statementItem=dynamic_cast<model::msc::MscStatementItem const*>(sequenceItem))
    {
      throw std::runtime_error("statement sequence type '"
                               +statementItem->text().toStdString()+
                               "' for msc pic not supported yet!");
    }
    else
      throw std::runtime_error("unknown sequence type for test case pic not supported yet!");
  }


  return;
}

void ComCreateMscPix::execute(QNetworkAccessManager* networkManager)
{
  Q_ASSERT(networkManager);

  if(!this->_d->_mscWebSequChartClient)
  {
    this->_d->_mscWebSequChartClient=new MscWebSequChartClient(networkManager,
                                                               this);
    connect(this->_d->_mscWebSequChartClient, &MscWebSequChartClient::result,
            this, &ComCreateMscPix::resultSlot);
    connect(this->_d->_mscWebSequChartClient, &MscWebSequChartClient::error,
            this, &ComCreateMscPix::errorSlot);
  }

  if(!this->_d->_mscSequence)
    return;

  QString mscSequenceText="";

  foreach(model::base::PortItem const* lifelinePort,
          this->_d->_lifelinePorts)
  {
    mscSequenceText+="participant ";
    mscSequenceText+= lifelinePort->toString();
    mscSequenceText+="\n";
  }

  processSequence(this->_d->_mscSequence, &mscSequenceText);
  this->_d->_mscWebSequChartClient->request(mscSequenceText);

  return;
}

void ComCreateMscPix::addPortLifeline(model::base::PortItem const* port)
{
  if(!port)
    return;

  this->_d->_lifelinePorts.append(port);

  return;
}

void ComCreateMscPix::resultSlot(QPixmap mscPix)
{
  emit result(this->_d->_mscSequence, mscPix);

  return;
}

void ComCreateMscPix::errorSlot(QString errorText)
{
  emit error(this->_d->_mscSequence, errorText);

  return;
}

model::msc::MscSequence const* ComCreateMscPix::mscSequence() const
{
  return this->_d->_mscSequence;
}

}/// end namespace msc
}/// end namespace view
