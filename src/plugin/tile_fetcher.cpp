////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "tile_fetcher.hpp"
#include "tiled_map_reply.hpp"
#include <pfs/fmt.hpp>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include <pfs/tieton/tag.hpp>
#include <pfs/log.hpp>

inline bool replace (std::string & str, std::string const & from, std::string const & to)
{
    size_t pos = str.find(from);

    if (pos == std::string::npos)
        return false;

    str.replace(pos, from.length(), to);
    return true;
}

QGeoTileFetcherTieton::QGeoTileFetcherTieton (QVariantMap const & parameters
    , QGeoTiledMappingManagerEngine * parent)
    : QGeoTileFetcher(parent)
    , _params(parameters)
    , _networkManager(new QNetworkAccessManager(this))
{
    auto pos = parameters.find("tieton.tile.address.pattern");

    if (pos != parameters.end()) {
        _tileAddressPattern = pos.value().toString().toStdString();
        replace(_tileAddressPattern, "{z}", "{0}");
        replace(_tileAddressPattern, "{x}", "{1}");
        replace(_tileAddressPattern, "{y}", "{2}");
    }
}

QGeoTileFetcherTieton::~QGeoTileFetcherTieton () = default;

QGeoTiledMapReply *
QGeoTileFetcherTieton::getTileImage (QGeoTileSpec const & spec)
{
    // QUrl url(QStringLiteral("http://localhost:8080/%1/%2/%3.mvt")
    QUrl url {QString::fromStdString(fmt::format(_tileAddressPattern, spec.zoom(), spec.x(), spec.y()))};

    LOGD(tieton::TAG, "Request: {}", url.toString().toStdString());

    QNetworkRequest remoteRequest(url);
    QNetworkReply * tileReply = _networkManager->get(remoteRequest);
    return new QGeoTiledMapReplyTieton(tileReply, spec);
}
