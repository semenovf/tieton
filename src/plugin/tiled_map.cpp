////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "tiled_map.hpp"
#include "mapping_manager_engine.hpp"

QGeoTiledMapTieton::QGeoTiledMapTieton (QGeoTiledMappingManagerEngineTieton * engine, QObject * parent)
    : QGeoTiledMap(engine, parent)
{}

QGeoTiledMapTieton::~QGeoTiledMapTieton () = default;
