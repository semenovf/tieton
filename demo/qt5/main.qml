////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
import QtQuick 2.8
import QtQuick.Controls 2.8
import QtQuick.Window 2.2
import "Map"

Window {
    x: 100
    y: 100
    width: 640
    height: 480
    visible: true

    MapUI {
        anchors.fill: parent
    }
}
