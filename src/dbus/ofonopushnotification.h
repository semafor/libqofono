/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c OfonoPushNotification -p ofonopushnotification -N ofono_push_notification.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef OFONOPUSHNOTIFICATION_H_1357940298
#define OFONOPUSHNOTIFICATION_H_1357940298

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.ofono.PushNotification
 */
class OfonoPushNotification: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.ofono.PushNotification"; }

public:
    OfonoPushNotification(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OfonoPushNotification();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> RegisterAgent(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QLatin1String("RegisterAgent"), argumentList);
    }

    inline QDBusPendingReply<> UnregisterAgent(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QLatin1String("UnregisterAgent"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
