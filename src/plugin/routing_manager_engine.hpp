////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QObject>
#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/QGeoRoutingManagerEngine>

QT_BEGIN_NAMESPACE

// class QNetworkAccessManager;

class QGeoRoutingManagerEngineTieton : public QGeoRoutingManagerEngine
{
    Q_OBJECT

public:
    QGeoRoutingManagerEngineTieton (QVariantMap const & parameters, QGeoServiceProvider::Error * error
        , QString * errorString, QObject * parent = nullptr);

    ~QGeoRoutingManagerEngineTieton ();

    QGeoRouteReply * calculateRoute (QGeoRouteRequest const & request) override;

// private Q_SLOTS:
//     void replyFinished();
//     void replyError(QGeoRouteReply::Error errorCode, const QString &errorString);
//
// private:
//     QNetworkAccessManager *m_networkManager;
//     QByteArray m_userAgent;
//     QString m_urlPrefix;
//     QString m_apiKey;
};

QT_END_NAMESPACE
