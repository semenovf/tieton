////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "QtLocation/private/qgeotiledmap_p.h"

QT_BEGIN_NAMESPACE

class QGeoTiledMappingManagerEngineTieton;

class QGeoTiledMapTieton: public QGeoTiledMap
{
    Q_OBJECT

public:
    QGeoTiledMapTieton (QGeoTiledMappingManagerEngineTieton * engine, QObject * parent = nullptr);
    ~QGeoTiledMapTieton ();
};

QT_END_NAMESPACE
