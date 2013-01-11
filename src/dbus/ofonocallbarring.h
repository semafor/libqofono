/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c OfonoCallBarring -p ofonocallbarring -N ofono_call_barring.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef OFONOCALLBARRING_H_1357940298
#define OFONOCALLBARRING_H_1357940298

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.ofono.CallBarring
 */
class OfonoCallBarring: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.ofono.CallBarring"; }

public:
    OfonoCallBarring(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OfonoCallBarring();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> ChangePassword(const QString &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QLatin1String("ChangePassword"), argumentList);
    }

    inline QDBusPendingReply<> DisableAll(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QLatin1String("DisableAll"), argumentList);
    }

    inline QDBusPendingReply<> DisableAllIncoming(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QLatin1String("DisableAllIncoming"), argumentList);
    }

    inline QDBusPendingReply<> DisableAllOutgoing(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QLatin1String("DisableAllOutgoing"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetProperties()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetProperties"), argumentList);
    }

    inline QDBusPendingReply<> SetProperty(const QString &in0, const QDBusVariant &in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QLatin1String("SetProperty"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void IncomingBarringInEffect();
    void OutgoingBarringInEffect();
    void PropertyChanged(const QString &in0, const QDBusVariant &in1);
};

#endif
