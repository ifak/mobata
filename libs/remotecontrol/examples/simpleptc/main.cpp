#include <QCoreApplication>

#include "simpleptcservice.hpp"
#include "simpleptccomponent.hpp"

#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  SimplePtcService simplePtcService;
  SimplePtcComponent simplePtcComponent(QStringLiteral("myPtc"),
                                        &simplePtcService);
  QString errorString;
  if(!simplePtcComponent.run(&errorString))
  {
    qDebug() << "error while starting my-ptc: "<<errorString;
    return -1;
  }

  return app.exec();
}

