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
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
//import Qt.labs.controls.material 1.0
//import Qt.labs.controls.universal 1.0

Pane
{
  id: pane

  anchors.fill: parent

  Column
  {
    anchors.fill: parent

    spacing: 20
    //flow: Grid.TopToBottom
    //horizontalItemAlignment: Grid.AlignRight

    GridLayout
    {
      //anchors.horizontalCenter: parent.horizontalCenter
      width: Math.min(pane.width, pane.height*3/4)
      height: width

      Button
      {
        id: noidea

        Layout.row: 0
        Layout.column: 0
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/commenting-o.svg"
          anchors.fill: parent
        }
      }
      Button
      {
        id: up

        Layout.row: 0
        Layout.column: 1
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/chevron-up.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_Up)
      }
      Button
      {
        id: goleft

        Layout.row: 1
        Layout.column: 0
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/chevron-left.svg"
          anchors.fill: parent
        }

      onClicked: client.keypress(Qt.Key_Left)
      }
      Button
      {
        id: ok

        Layout.row: 1
        Layout.column: 1
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/check.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_Enter)
      }
      Button
      {
        id: goright

        Layout.row: 1
        Layout.column: 2
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/chevron-right.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_Right)
      }
      Button
      {
        id: back

        Layout.row: 2
        Layout.column: 0
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/arrow-left.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_Back)
      }
      Button
      {
        id: down

        Layout.row: 2
        Layout.column: 1
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/chevron-down.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_Down)
      }
    }
    GridLayout
    {
      width: Math.min(pane.width, pane.height*3/4)
      height: width/5

      Button
      {
        id: rewind

        Layout.row: 0;
        Layout.column: 0
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/backward.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_AudioRewind)
      }
      Button
      {
        id: pause

        Layout.row: 0
        Layout.column: 1
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "qrc:/icons/pause"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_MediaPause)
      }
      Button {
        id: play

        Layout.row: 0
        Layout.column: 2
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/play.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_MediaPlay)
      }
      Button
      {
        id: fast_forward

        Layout.row: 0
        Layout.column: 3
        Layout.fillWidth: true
        Layout.fillHeight: true

        contentItem: Image
        {
          source: "icons/forward.svg"
          anchors.fill: parent
        }

        onClicked: client.keypress(Qt.Key_AudioForward)
      }
    }
  }
}
