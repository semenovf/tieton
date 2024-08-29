////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "mapping_manager_engine.hpp"
#include "tile_fetcher.hpp"
#include "tiled_map.hpp"
#include <pfs/tieton/tag.hpp>
#include <pfs/log.hpp>

QGeoTiledMappingManagerEngineTieton::QGeoTiledMappingManagerEngineTieton (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString, QObject * parent)
    : QGeoTiledMappingManagerEngine(parent)
{
    int width = 256;
    int height = 256;
    double minZoomLevel = 0;
    double maxZoomLevel = 22.0;

    auto pos = parameters.find("tieton.tile.size.width");

    if (pos != parameters.end())
        width = pos.value().toInt();

    pos = parameters.find("tieton.tile.size.height");

    if (pos != parameters.end())
        height = pos.value().toInt();

    pos = parameters.find("tieton.map.zoom.min");

    if (pos != parameters.end())
        minZoomLevel = pos.value().toDouble();

    pos = parameters.find("tieton.map.zoom.max");

    if (pos != parameters.end())
        maxZoomLevel = pos.value().toDouble();

    if (minZoomLevel < 0.0) {
        LOGE(tieton::TAG, "Bad minimum zoom level, set to 0");
        minZoomLevel = 0.0;
    }

    if (maxZoomLevel < 0.0) {
        LOGE(tieton::TAG, "Bad maximum zoom level, set to 22");
        maxZoomLevel = 22.0;
    }

    if (minZoomLevel > maxZoomLevel) {
        LOGE(tieton::TAG, "Bad minimum zoom level, set to 0");
        minZoomLevel = 0.0;
    }

    LOGD(tieton::TAG, "Zoom level range: {:.1}-{}", minZoomLevel, maxZoomLevel);

    QGeoCameraCapabilities cameraCaps;
    cameraCaps.setMinimumZoomLevel(minZoomLevel);
    cameraCaps.setMaximumZoomLevel(maxZoomLevel);
    setCameraCapabilities(cameraCaps);

    LOGD(tieton::TAG, "Tile size: {}x{}", width, height);
    setTileSize(QSize(width, height));

    QList<QGeoMapType> mapTypes;

    int streetMapId = static_cast<int>(QGeoMapType::StreetMap);

    pos = parameters.find("tieton.map.id.street_map");

    if (pos != parameters.end())
        streetMapId = pos.value().toInt();

    mapTypes << QGeoMapType(QGeoMapType::StreetMap
        , tr("Street Map")
        , tr("Normal map view in daylight mode")
        , false
        , false
        , streetMapId
        , "tieton"
        , cameraCaps
        , parameters);

    // types << QGeoMapType(QGeoMapType::SatelliteMapDay, tr("Satellite"), tr("Satellite map view in daylight mode"), false, false, 2, "tieton", cameraCaps, parameters);
    // types << QGeoMapType(QGeoMapType::TerrainMap, tr("Terrain"), tr("Terrain map view in daylight mode"), false, false, 3, "tieton", cameraCaps, parameters);
    // types << QGeoMapType(QGeoMapType::HybridMap, tr("Hybrid"), tr("Satellite map view with streets in daylight mode"), false, false, 4, "tieton", cameraCaps, parameters);

    setSupportedMapTypes(mapTypes);

    auto tileFetcher = new QGeoTileFetcherTieton(parameters, this);
    setTileFetcher(tileFetcher);

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

QGeoTiledMappingManagerEngineTieton::~QGeoTiledMappingManagerEngineTieton () = default;

QGeoMap * QGeoTiledMappingManagerEngineTieton::createMap ()
{
    return new QGeoTiledMapTieton(this);
}
