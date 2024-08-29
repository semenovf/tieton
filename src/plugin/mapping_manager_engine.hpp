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
#include "QtLocation/private/qgeotiledmappingmanagerengine_p.h"
#include "QtLocation/private/qgeomaptype_p.h"

QT_BEGIN_NAMESPACE

class QGeoTiledMappingManagerEngineTieton : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT

public:
    QGeoTiledMappingManagerEngineTieton (QVariantMap const & parameters
        , QGeoServiceProvider::Error * error, QString * errorString, QObject * parent = nullptr);

    ~QGeoTiledMappingManagerEngineTieton ();

    QGeoMap * createMap () override;
};

QT_END_NAMESPACE
