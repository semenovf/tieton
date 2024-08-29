////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include "coding_manager_engine.hpp"

QGeoCodingManagerEngineTieton::QGeoCodingManagerEngineTieton (QVariantMap const & parameters
    , QGeoServiceProvider::Error * error, QString * errorString, QObject *parent)
    : QGeoCodingManagerEngine(parameters, parent)
{

}

QGeoCodingManagerEngineTieton::~QGeoCodingManagerEngineTieton () = default;
