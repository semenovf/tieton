////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/QGeoCodingManagerEngine>
#include <QtLocation/QGeoCodeReply>

QT_BEGIN_NAMESPACE

class QGeoCodingManagerEngineTieton : public QGeoCodingManagerEngine
{
    Q_OBJECT

public:
    QGeoCodingManagerEngineTieton (QVariantMap const & parameters, QGeoServiceProvider::Error * error
        , QString * errorString, QObject *parent = nullptr);

    ~QGeoCodingManagerEngineTieton ();
};

QT_END_NAMESPACE
