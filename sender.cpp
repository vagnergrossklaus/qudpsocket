#include "sender.h"

#include <QDateTime>

Sender::Sender() : _socket(new QUdpSocket(this)) {
  QObject::connect(&_timer, &QTimer::timeout, this, &Sender::onTimerTimeout);
}

void Sender::start() { _timer.start(1000); }

void Sender::send() {
  QByteArray datagram = "Broadcast message " +
                        QByteArray::number(QDateTime::currentSecsSinceEpoch()) +
                        "";
  qInfo() << "send:" << datagram;
  _socket->writeDatagram(datagram, QHostAddress::Broadcast, 45454);
}

void Sender::onTimerTimeout() { send(); }
