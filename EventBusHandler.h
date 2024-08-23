#ifndef EVENTBUSHANDLER_H
#define EVENTBUSHANDLER_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "EventBus.h"
class EventBusHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventBusHandler(QObject* parent = nullptr);
signals:
public slots:
    void handleEvent(const QString& eventName, const QVariant& data);
};

#endif // EVENTBUSHANDLER_H
