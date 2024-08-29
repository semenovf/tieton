////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "routing_manager_engine.hpp"

QGeoRoutingManagerEngineTieton::QGeoRoutingManagerEngineTieton (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error , QString * errorString, QObject * parent)
    : QGeoRoutingManagerEngine(parameters, parent)
{}

QGeoRoutingManagerEngineTieton::~QGeoRoutingManagerEngineTieton () = default;

QGeoRouteReply *
QGeoRoutingManagerEngineTieton::calculateRoute (QGeoRouteRequest const & request)
{
    // FIXME
    return new QGeoRouteReply(QGeoRouteReply::NoError, QString{}, this);
}
