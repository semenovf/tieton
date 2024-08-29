////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
import QtQuick 2.8
import QtLocation 5.8
import QtPositioning 5.8

Item {
    id: mapPage

    // Ubuntu 22.04 / Qt 5.15.3 - Freeze (see https://bugreports.qt.io/browse/QTBUG-95638 and related bugs)
    //
    // Plugin {
    //     id: mapPlugin
    //     name: "osm"
    //
    //     PluginParameter {
    //         name: "osm.mapping.providersrepository.disabled"
    //         value: "true"
    //     }
    //
    //     PluginParameter {
    //         name: "osm.mapping.providersrepository.address"
    //         value: "http://maps-redirect.qt.io/osm/5.8/"
    //     }
    // }

    // Ubuntu 22.04 / Qt 5.15.3 - Segmentation fault (core dumped)
    // Plugin {
    //     id: mapPlugin
    //     name: "mapboxgl"
    // }

    // Plugin {
    //     id: mapPlugin
    //     name: "mapbox"
    // }

    // Commercial license
    // Plugin {
    //     id: mapPlugin
    //     name: "nokia"
    // }

    // Plugin {
    //     id: mapPlugin
    //     name: "esri"
    // }

    Plugin {
        id: mapPlugin
        name: "tieton"

        PluginParameter {
            name: "tile-map-server.spec"
            value: "http://192.168.0.5:8181/tms.xml"
        }

        PluginParameter {
            name: "tieton.tile.address.pattern"
            value: "http://192.168.0.5:8181/World.OSM.GMT.z6.v2103/{z}/{x}/{y}.png"
            //value: "http://192.168.0.5:8181/World.HGT.EPSG3857/{z}/{x}/{y}.png"
        }

        PluginParameter {
            name: "tieton.map.id.street_map"
            value: 1
        }

        PluginParameter {
            name: "tieton.tile.size.width"
            value: 256
        }

        PluginParameter {
            name: "tieton.tile.size.height"
            value: 256
        }

        PluginParameter {
            name: "tieton.map.zoom.min"
            value: 1
        }

        PluginParameter {
            name: "tieton.map.zoom.max"
            value: 10
        }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(56.8431, 60.6454) // Yekaterinburg
        zoomLevel: 3
        copyrightsVisible: false
    }
}
