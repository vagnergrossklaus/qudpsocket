#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTimer>
#include <QUdpSocket>

class Sender : public QObject {
  Q_OBJECT
public:
  Sender();

  void start();

private:
  QTimer _timer;
  QUdpSocket *_socket = nullptr;

  void send();

private slots:
  void onTimerTimeout();
};

#endif // SENDER_H
