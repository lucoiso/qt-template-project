// Copyright Notices: [...]

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UserInterface

Item
{
    readonly property int fieldWidth: 200
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
            fillMode: Image.PreserveAspectFit
            source: "qrc:/UserInterface/Resources/Images/Placeholder.png"
        }

        TextField
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            id: usernameInput
            placeholderText: "Username"
            width: fieldWidth
        }

        Button
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: "Login"
            width: fieldWidth
            enabled: usernameInput.text.trim() !== ""

            onClicked:
            {
                loginSuccessful();
            }
        }
    }
}