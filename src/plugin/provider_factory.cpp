////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.09 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "provider_factory.hpp"
#include "coding_manager_engine.hpp"
#include "mapping_manager_engine.hpp"
#include "place_manager_engine.hpp"
#include "routing_manager_engine.hpp"
#include <pfs/log.hpp>
#include <pfs/tieton/tag.hpp>

QGeoCodingManagerEngine *
QGeoServiceProviderFactoryTieton::createGeocodingManagerEngine (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString) const
{
    //return new QGeoCodingManagerEngineTieton(parameters, error, errorString);
    return nullptr; // Unsupported yet
}

QGeoMappingManagerEngine *
QGeoServiceProviderFactoryTieton::createMappingManagerEngine (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString) const
{
    int index = 0;

    for (auto pos = parameters.cbegin(); pos != parameters.cend(); ++pos) {
        LOGD(tieton::TAG, "Parameter {}: {}={}"
            , ++index
            , pos.key().toStdString()
            , pos.value().toString().toStdString());
    }

    return new QGeoTiledMappingManagerEngineTieton(parameters, error, errorString);
}

QGeoRoutingManagerEngine *
QGeoServiceProviderFactoryTieton::createRoutingManagerEngine (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString) const
{
    // return new QGeoRoutingManagerEngineTieton(parameters, error, errorString);
    return nullptr; // Unsupported yet
}

QPlaceManagerEngine *
QGeoServiceProviderFactoryTieton::createPlaceManagerEngine (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString) const
{
    //return new QPlaceManagerEngineTieton(parameters, error, errorString);
    return nullptr; // Unsupported yet
}
