////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.09 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QObject>
#include <QtLocation/QGeoServiceProviderFactory>

// References:
// 1. [Qt Location C++ API](https://doc.qt.io/qt-5/qtlocation-cpp.html)
// 2. [Qt Location GeoServices](https://doc.qt.io/qt-5/qtlocation-geoservices.html)

QT_BEGIN_NAMESPACE

class QGeoServiceProviderFactoryTieton: public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0"
        FILE "tieton_plugin.json")

public:
    QGeoCodingManagerEngine * createGeocodingManagerEngine (QVariantMap const & parameters
        , QGeoServiceProvider::Error * error, QString * errorString) const override;

    QGeoMappingManagerEngine * createMappingManagerEngine (QVariantMap const & parameters
        , QGeoServiceProvider::Error * error, QString * errorString) const override;

    QGeoRoutingManagerEngine * createRoutingManagerEngine(QVariantMap const & parameters
        , QGeoServiceProvider::Error * error, QString * errorString) const override;

    QPlaceManagerEngine * createPlaceManagerEngine (QVariantMap const & parameters
        , QGeoServiceProvider::Error * error, QString * errorString) const override;
};

QT_END_NAMESPACE
