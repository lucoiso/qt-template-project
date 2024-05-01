// Copyright Notices: [...]

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../Pages" as Pages

Item {
    TabBar {
        id: shellBar

        z: 999
        width: parent.width

        TabButton {
            text: qsTr("Home")
        }

        TabButton {
            text: qsTr("Placeholder")
        }
    }

    StackLayout {
        anchors.left: parent.left
        anchors.top: shellBar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        currentIndex: shellBar.currentIndex

        Pages.HomePage {
            id: homePage
        }

        Pages.PlaceholderPage {
            id: placeholderPage
        }
    }
}