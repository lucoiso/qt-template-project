// Copyright Notices: [...]

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/UserInterface/Resources/QML/Pages" as Pages

Item
{
    TabBar
    {
        id: shellBar

        z: 999
        width: parent.width

        TabButton
        {
            text: "Home"
        }

        TabButton
        {
            text: "Placeholder"
        }
    }

    StackLayout
    {
        anchors.left: parent.left
        anchors.top: shellBar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        currentIndex: shellBar.currentIndex

        Pages.HomePage
        {
            id: homePage
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Pages.PlaceholderPage
        {
            id: placeholderPage
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}