// Copyright Notices: [...]

import QtQuick
import QtQuick.Controls

import UserInterface

Item
{
    Rectangle
    {
        anchors.centerIn: parent

        width: 200
        height: 200
        color: "blue"

        TemplateObject
        {
            id: templateObject
        }

        Label
        {
            anchors.centerIn: parent
            text: templateObject.Name
        }
    }
}