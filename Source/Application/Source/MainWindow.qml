// Copyright Notices: [...]

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "../../UserInterface/QML/Components" as Components
import "../../UserInterface/QML/Pages" as Pages

ApplicationWindow
{
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: "Main Window"

    StackView
    {
        id: mainStack
        anchors.fill: parent

        initialItem: Pages.LoginPage
        {
            onLoginSuccessful: mainStack.push(compShell)
        }

        Component
        {
            id: compShell

            Components.ApplicationShell
            {
                id: appShell
            }
        }
    }
}