# NATS_Server

NATS Server example

<h1>Installation</h1>
This is a header-only library that depends on Qt5. All you have to do is include it inside your project. It depends on the Qt network module so don't forget to add it to your project-name.pro file (QT += network).





<h1>Usage examples</h1>

#include <QCoreApplication>
#include "natsclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Nats::Client client;
    client.connect("127.0.0.1", 4222, [&]
    {
        // simple subscribe
        client.subscribe("foo", [](QString message, QString inbox, QString subject)
        {
            qDebug() << "received: " << message << inbox << subject;
        });

        // simple publish
        client.publish("foo", "Hello NATS!");
    });
    return a.exec();
}
