#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "remoteuserapp.hpp"

int main(int argc, char *argv[])
{
  qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  RemoteUserApp userApp("example remote user app",
                        new RemoteUserService);
  QString errorString;
  bool result=userApp.run(&errorString);
  if(!result)
  {
    qWarning()<<"user app cannot be started! error: "<<errorString;
    return -1;
  }

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("app", &userApp);
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  return app.exec();
}
