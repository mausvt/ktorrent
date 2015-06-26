/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c KTorrentTorrentFilestreamInterface -p ktorrenttorrentfilestreaminterface org.ktorrent.torrentfilestream.xml
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef KTORRENTTORRENTFILESTREAMINTERFACE_H_1292067316
#define KTORRENTTORRENTFILESTREAMINTERFACE_H_1292067316

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.ktorrent.torrentfilestream
 */
class KTorrentTorrentFilestreamInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.ktorrent.torrentfilestream"; }

public:
    KTorrentTorrentFilestreamInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~KTorrentTorrentFilestreamInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<qlonglong> bytesAvailable()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("bytesAvailable"), argumentList);
    }

    inline QDBusPendingReply<QString> path()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("path"), argumentList);
    }

    inline QDBusPendingReply<qlonglong> pos()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("pos"), argumentList);
    }

    inline QDBusPendingReply<QByteArray> read(qlonglong maxlen)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(maxlen);
        return asyncCallWithArgumentList(QLatin1String("read"), argumentList);
    }

    inline QDBusPendingReply<bool> seek(qlonglong pos)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(pos);
        return asyncCallWithArgumentList(QLatin1String("seek"), argumentList);
    }

    inline QDBusPendingReply<qlonglong> size()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("size"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace ktorrent {
    typedef ::KTorrentTorrentFilestreamInterface torrentfilestream;
  }
}
#endif