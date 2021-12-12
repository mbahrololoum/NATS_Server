#ifndef CLASSNATS_H
#define CLASSNATS_H

#include <QObject>
#include "natsclient.h"

class ClassNats : public QObject
{
    Q_OBJECT

public:
    explicit ClassNats(QObject *parent = nullptr);
    ~ClassNats();
    void startListen();

signals:
    void signalConnectNatsServer(QString message);

public slots:
    void publishMessage(const QString msg);

private:
    Nats::Client* nats;
    QString subject = "foo";

};

#endif // CLASSNATS_H
