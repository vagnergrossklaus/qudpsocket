#include <QCoreApplication>

#include "receiver.h"
#include "sender.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Sender sender;
  Receiver receiver;

  QString arg = QCoreApplication::arguments().count() > 1
                    ? QCoreApplication::arguments().at(1)
                    : "";
  if (arg == "receiver")
    receiver.start();
  else if (arg == "sender")
    sender.start();
  else {
    qDebug() << "QUDPSocket use one o this options: \n"
                "   receiver Listen UDP data\n"
                "   sender Send UDP data\n";
    return 0;
  }
  return a.exec();
}
