// EventBus.h
#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <QObject>
#include <QVariant>
class EventBus : public QObject
{
    Q_OBJECT

public:
    static EventBus& instance();
    explicit EventBus(QObject* parent = nullptr);
    ~EventBus();

signals:
    void cppSignal(const QString& eventName, const QVariant& data);
    void transitEvent(const QString& eventName, const QVariant& data);

public slots:
    void postEvent(const QString& eventName, const QVariant& data);
    void cppSlot(const QString& eventName, const QVariant& data);
};

#endif // EVENTBUS_H
