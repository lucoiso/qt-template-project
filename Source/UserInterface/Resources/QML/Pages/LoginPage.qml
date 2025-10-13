// Copyright Notices: [...]

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UserInterface

Item
{
    readonly property int field_width: 200
    signal loginSuccessful()

    ColumnLayout
    {
        anchors.centerIn: parent
        spacing: 8

        Image
        {
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.margins: 16

            asynchronous: false
            width: 100
            height: 100
            sourceSize.width: width
            sourceSize.height: height
            fillMode: Image.PreserveAspectFit
            source: "qrc:/UserInterface/Resources/Images/Placeholder.png"
        }

        TextField
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            id: usernameInput
            placeholderText: "Username"
            width: field_width
        }

        Button
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: "Login"
            width: field_width

            onClicked:
            {
                loginSuccessful();
            }
        }
    }
}