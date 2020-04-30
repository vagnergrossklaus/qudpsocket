#include "receiver.h"

Receiver::Receiver() : _socket(new QUdpSocket()) {}

void Receiver::start() {
  _socket->bind(45454, QUdpSocket::ShareAddress);
  connect(_socket, &QIODevice::readyRead, this, &Receiver::onReadyRead);
}

void Receiver::onReadyRead() {
  QByteArray datagram;
  while (_socket->hasPendingDatagrams()) {
    datagram.resize(100);
    _socket->readDatagram(datagram.data(), 100);
    qInfo() << "receive:" << datagram.toStdString().c_str();
  }
}
