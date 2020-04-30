#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QUdpSocket>

class Receiver : public QObject {
  Q_OBJECT
public:
  Receiver();

  void start();

private:
  QUdpSocket *_socket = nullptr;

private slots:
  void onReadyRead();
};

#endif // RECEIVER_H
