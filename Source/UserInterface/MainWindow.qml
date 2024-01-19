// Copyright Notices: [...]

import QtQuick

Window {
    id: main_window
    width: 640
    height: 480
    visible: true
    title: qsTr("Data Manager")

    Rectangle {
        id: rect
        width: main_window.width
        height: main_window.height
        color: "black"

        Text {
            id: text
            text: qsTr("Hello World")
            anchors.centerIn: parent
            font.pixelSize: 24
            color: "white"
        }
    }
}
