#include "EventBusHandler.h"

EventBusHandler::EventBusHandler(QObject* parent)
    : QObject(parent)
{
    // 连接 customEvent 信号
    QObject::connect(&EventBus::instance(), &EventBus::transitEvent, this, &EventBusHandler::handleEvent);
}
void EventBusHandler::handleEvent(const QString& eventName, const QVariant& data)
{
    // 先将 QVariant 转换为 QVariantMap
    QVariantMap variantMap = data.toMap();

    // 再将 QVariantMap 转换为 QJsonObject
    QJsonObject jsonObject = QJsonObject::fromVariantMap(variantMap);

    // 将 QJsonObject 转换成 QJsonDocument 以便输出
    QJsonDocument doc(jsonObject);
    qDebug().noquote() << "cpp recv Json:" << doc.toJson(QJsonDocument::Indented);

    if (eventName == "login")
    {
        QString username = jsonObject.value("username").toString();
        QString passwd = jsonObject.value("passwd").toString();
        // 处理事件后，可以发回一个事件到 QML
        QJsonObject sendjson;
        if (username == "admin" && passwd == "123456")
        {
            sendjson.insert("status", 0);
        }
        else
        {
            sendjson.insert("status", 1);
        }
        //  jsonToQString(sendjson, sendData);

        EventBus::instance().postEvent("loginResp", sendjson);
    }
}
