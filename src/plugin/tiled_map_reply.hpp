////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QNetworkReply>
#include <QPointer>
#include <QtLocation/private/qgeotiledmapreply_p.h>

QT_BEGIN_NAMESPACE

class QGeoTiledMapReplyTieton : public QGeoTiledMapReply
{
    Q_OBJECT

private:
    QPointer<QNetworkReply> _reply {nullptr};

public:
    explicit QGeoTiledMapReplyTieton (QNetworkReply * reply, QGeoTileSpec const & spec
        , QObject *parent = nullptr);

    ~QGeoTiledMapReplyTieton ();

    void abort () override;

private:
    Q_SLOT void onNetworkFinished ();
    Q_SLOT void onNetworkError (QNetworkReply::NetworkError error);
    Q_SLOT void onReplyDestroyed ();
};

QT_END_NAMESPACE

