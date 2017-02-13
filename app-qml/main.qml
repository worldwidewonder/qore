/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
//import Qt.labs.controls.material 1.0
//import Qt.labs.controls.universal 1.0
import Qt.labs.settings 1.0

ApplicationWindow
{
  id: window
  visible: true
  minimumWidth: 500
  minimumHeight: 700
  title: "Qore"

  Settings
  {
    id: settings
    property string style: "Universal"
  }

  header: ToolBar
  {
    RowLayout
    {
      spacing: 20
      anchors.fill: parent
      implicitHeight: height

      ToolButton
      {
        contentItem: Image
        {
          anchors.centerIn: parent
          source: "icons/navicon.svg"
          sourceSize.width: 32
        }
        onClicked: drawer.open()
      }

      Label
      {
        id: titleLabel
        text: "Qore"
        font.pointSize: 32
        elide: Label.ElideRight
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        Layout.fillWidth: true
      }

      ToolButton
      {
        contentItem: Image
        {
          anchors.centerIn: parent
          source: "icons/remote.svg"
          sourceSize.width: 32
        }
        onClicked:
        {
          listView.currentIndex = 2
          stackView.replace("remote.qml.svg")
        }
      }

      ToolButton
      {
        contentItem: Image
        {
          anchors.centerIn: parent
          source: "icons/ellipsis-v.svg"
          sourceSize.width: 32
        }
        onClicked: optionsMenu.open()

        Menu
        {
          id: optionsMenu
          x: parent.width - width
          transformOrigin: Menu.TopRight

          MenuItem
          {
            text: "Settings"
            onTriggered: settingsPopup.open()
          }
          MenuItem
          {
            text: "About"
            onTriggered: aboutDialog.open()
          }
        }
      }
    }
  }

  Drawer
  {
    id: drawer

    Pane
    {
      padding: 5
      width: Math.min(window.width, window.height) / 3 * 2
      height: window.height

      ListView {
        id: listView

        currentIndex: -1
        anchors.fill: parent

        highlightFollowsCurrentItem: true
        boundsBehavior: Flickable.StopAtBounds
        clip: true

        function navigateToPage(index, model)
        {
          if (listView.currentIndex != index && index > 0)
          {
            listView.currentIndex = index
            titleLabel.text = model.name
            stackView.replace(model.source)
          }
          drawer.close()
        }

        delegate: ItemDelegate
        {
          width: parent.width
          contentItem: GridLayout
          {
            implicitHeight: 48
            Image
            {
              Layout.column: 0
              source: model.icon
              sourceSize.height: 48
            }
            Text
            {
              Layout.column: 2
              text: model.name
              font.pointSize: 32
            }
          }

          highlighted: ListView.isCurrentItem
          onClicked: listView.navigateToPage(index, model)
        }

        model: ListModel
        {
          ListElement { name: "Qore";       icon: "icons/navicon.svg" }
          ListElement { name: "Connection"; icon: "icons/chain";  source: "qrc:/connection.qml.svg" }
          ListElement { name: "Remote";     icon: "icons/remote"; source: "qrc:/remote.qml.svg" }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
      }
    }
  }

  StackView
      {
    id: stackView
    anchors.fill: parent

    initialItem: "connection.qml.svg"
  }

  Connections
  {
    target: client
    //onConnected: console.log("Connected from QML!")
  }
}
