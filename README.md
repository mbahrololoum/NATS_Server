# Qt-NATS
A [Qt5](https://www.qt.io) C++11 client for the [NATS messaging system](https://nats.io).

[![License MIT](https://cdn.rawgit.com/pkoretic/qt-nats/badges/license.svg)](http://opensource.org/licenses/MIT)
[![Language (C++)](https://cdn.rawgit.com/pkoretic/qt-nats/badges/powered_by-C%2B%2B-blue.svg)](http://en.cppreference.com/w/cpp/language)

## Installation
This is a header-only library that depends on Qt5. All you have to do is include it inside your project. It depends on the Qt network module so don't forget to add it to your project-name.pro file (QT += network).


## Usage examples

```
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
```
