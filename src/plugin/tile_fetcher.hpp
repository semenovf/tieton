////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QNetworkAccessManager>
#include <QVariantMap>
#include <QtLocation/private/qgeotilefetcher_p.h>
#include <string>

QT_BEGIN_NAMESPACE

class QGeoTileFetcherTieton : public QGeoTileFetcher
{
    Q_OBJECT

private:
    std::string _tileAddressPattern;

    QVariantMap _params;
    QNetworkAccessManager * _networkManager {nullptr};

public:
    QGeoTileFetcherTieton (QVariantMap const & parameters, QGeoTiledMappingManagerEngine * parent);
    ~QGeoTileFetcherTieton ();

private:
    QGeoTiledMapReply * getTileImage (QGeoTileSpec const & spec) override;
};

QT_END_NAMESPACE
