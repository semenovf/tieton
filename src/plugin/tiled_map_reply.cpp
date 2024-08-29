////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "tiled_map_reply.hpp"
#include <QtLocation/private/qgeotilespec_p.h>

#include <pfs/log.hpp>

QGeoTiledMapReplyTieton::QGeoTiledMapReplyTieton (QNetworkReply * reply, QGeoTileSpec const & spec
    , QObject * parent)
    : QGeoTiledMapReply(spec, parent)
    , _reply(reply)
{
    connect(_reply, SIGNAL(finished()), this, SLOT(onNetworkFinished()));
    connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onNetworkError(QNetworkReply::NetworkError)));
    connect(_reply, SIGNAL(destroyed()), this, SLOT(onReplyDestroyed()));
}

QGeoTiledMapReplyTieton::~QGeoTiledMapReplyTieton () = default;

void QGeoTiledMapReplyTieton::abort ()
{
    if (_reply == nullptr)
        return;

    _reply->abort();
}

void QGeoTiledMapReplyTieton::onNetworkFinished ()
{
    if (_reply == nullptr)
        return;

    if (_reply->error() != QNetworkReply::NoError)
        return;

    setMapImageData(_reply->readAll());
    int const mapId = tileSpec().mapId();

    if (mapId == 0 || mapId == 1)
        setMapImageFormat("png");
    else
        setMapImageFormat("jpeg");

    setFinished(true);

    _reply->deleteLater();
    _reply = nullptr;
}

void QGeoTiledMapReplyTieton::onNetworkError (QNetworkReply::NetworkError error)
{
    if (_reply == nullptr)
        return;

    if (error != QNetworkReply::OperationCanceledError)
        setError(QGeoTiledMapReply::CommunicationError, _reply->errorString());

    setFinished(true);
    _reply->deleteLater();
    _reply = nullptr;
}

void QGeoTiledMapReplyTieton::onReplyDestroyed ()
{
    _reply = nullptr;
}
