#include "mscwebsequchartclient.hpp"

#include <QDebug>
#include <QPixmap>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

MscWebSequChartClient::MscWebSequChartClient(QNetworkAccessManager* networkManager,
                                             QObject *parent)
  :	QObject(parent), _networkManager(networkManager)
{}

MscWebSequChartClient::~MscWebSequChartClient()
{}

void MscWebSequChartClient::request(const QString& sequChartText)
{
  QUrl webSequChartUrl("http://www.websequencediagrams.com/");

  QByteArray data="style=qsd";
  data+="&message="+sequChartText;
  data+="&apiVersion=1";

  QNetworkRequest request;
  request.setUrl(webSequChartUrl);

  this->_requestReply=this->_networkManager->post(request, data);
  connect(this->_requestReply, SIGNAL(finished()),
          this, SLOT(slotRequestFinished()));
  connect(this->_requestReply, SIGNAL(error(QNetworkReply::NetworkError)),
          this, SLOT(slotError(QNetworkReply::NetworkError)));
}

void MscWebSequChartClient::slotError(QNetworkReply::NetworkError /*networkError*/)
{
  if(!this->_requestReply)
    return;

  emit error(this->_requestReply->errorString());

  return;
}

void MscWebSequChartClient::slotRequestFinished()
{
  if(!this->_requestReply)
    return;

  if(this->_requestReply->error()!=QNetworkReply::NoError)
    emit error(this->_requestReply->errorString());

  QString successString=this->_requestReply->readAll();

  int start=successString.indexOf("?png=");
  int end=successString.indexOf("\"", start);
  QString imgQuery=successString.mid(start, end-start);

  this->_requestReply->deleteLater();

  QUrl webSequChartUrl("http://www.websequencediagrams.com/"+imgQuery);
  QNetworkRequest request;
  request.setUrl(webSequChartUrl);

  this->_imgReply=this->_networkManager->get(request);
  connect(this->_imgReply, &QNetworkReply::finished,
          this, &MscWebSequChartClient::slotImageFinished);

  return;
}

void MscWebSequChartClient::slotImageFinished()
{
  QByteArray data=this->_imgReply->readAll();

  QPixmap sequPixmap;
  sequPixmap.loadFromData(data);

  emit result(sequPixmap);

//	this->_imgReply->deleteLater();

  return;
}

}/// end namespace msc
}/// end namespace view
