#include "ClassNats.h"
#include "natsclient.h"

#include <QDebug>

ClassNats::ClassNats(QObject *parent) : QObject{parent}
{
    nats = new Nats::Client();
    startListen();
}

ClassNats::~ClassNats()
{
    nats->disconnect();
}

void ClassNats::startListen()
{
    nats->connect("localhost", 4222, [&] {
        emit signalConnectNatsServer("Connect to server");

        // simple subscribe message
        nats->subscribe(subject, [this](QString message, QString inbox, QString subject) {
            qDebug() << "received: " << message << inbox << subject;
            emit signalConnectNatsServer(message);
        });
    });
}

void ClassNats::publishMessage(const QString msg)
{
    // simple send message
    nats->publish(subject, msg);
}

