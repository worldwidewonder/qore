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
import Qt.labs.controls 1.0

Pane
{
  id: pane

  font.pointSize: 20

  GridLayout
  {
    anchors
    {
      top: parent.top
      left: parent.left
      right: parent.right
      bottom: parent.fillHeight ? parent.bottom : undefined
    }

    Label
    {
      Layout.row: 0
      Layout.column: 0

      text: qsTr("Hostname:")
    }
    TextField
    {
      id: host_field

      Layout.row: 0
      Layout.column: 1
      Layout.fillWidth: true

      placeholderText: "localhost"
      focus: true
    }
    Label
    {
      Layout.row: 1
      Layout.column: 0

      text: qsTr("Port:")
    }
    TextField
    {
      id: port_field
      Layout.row: 1
      Layout.column: 1
      Layout.fillWidth: true

      placeholderText: "9090"
      validator: IntValidator {}
    }
    Button
    {
      Layout.row: 2
      Layout.column: 1
      Layout.fillWidth: true

      width: validate_text.implicitWidth

      label: Text
      {
        id: validate_text
        text: qsTr("Validate & connect")
        font.pointSize: 20
        anchors.centerIn: parent
      }
      onClicked: client.connect_socket(host_field.text, port_field.text*1)
    }
  }
}
