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
#include <QtLocation/QPlaceManagerEngine>
#include <QtLocation/QGeoServiceProvider>

QT_BEGIN_NAMESPACE

class QPlaceManagerEngineTieton : public QPlaceManagerEngine
{
    Q_OBJECT

public:
    QPlaceManagerEngineTieton (QVariantMap const & parameters, QGeoServiceProvider::Error * error
        , QString * errorString, QObject * parent = nullptr);

    ~QPlaceManagerEngineTieton ();
};

QT_END_NAMESPACE
