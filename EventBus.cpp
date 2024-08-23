#include "EventBus.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
EventBus& EventBus::instance()
{
    static EventBus instance;
    return instance;
}

EventBus::EventBus(QObject* parent)
    : QObject(parent)
{
}
EventBus::~EventBus()
{
}

void EventBus::postEvent(const QString& eventName, const QVariant& data)
{
    // 先将 QVariant 转换为 QVariantMap
    QVariantMap variantMap = data.toMap();

    // 再将 QVariantMap 转换为 QJsonObject
    QJsonObject jsonObject = QJsonObject::fromVariantMap(variantMap);

    // 将 QJsonObject 转换成 QJsonDocument 以便输出
    QJsonDocument doc(jsonObject);
    qDebug().noquote() << "cpp send Json:" << doc.toJson(QJsonDocument::Indented);
    emit cppSignal(eventName, data);
}

void EventBus::cppSlot(const QString& eventName, const QVariant& data)
{
    emit transitEvent(eventName, data);
}
