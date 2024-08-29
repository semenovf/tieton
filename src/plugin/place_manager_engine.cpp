////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "place_manager_engine.hpp"

QPlaceManagerEngineTieton::QPlaceManagerEngineTieton (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error , QString * errorString, QObject * parent)
    : QPlaceManagerEngine(parameters, parent)
{}

QPlaceManagerEngineTieton::~QPlaceManagerEngineTieton () = default;

