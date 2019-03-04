/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.2

Rectangle {
    objectName: "msc__statement"
    width: 1
    height: 1
    radius: 20
    property color textcolor: "black"
    property string uuid: ""
    property string label: ""
    property int prefWidth: text.contentWidth*1.7
    property int prefHeight: text.contentHeight*1.7
    property color borderColor: "transparent"

    border.color: borderColor
    border.width: 2

    color: "lightblue"
    Text{
        id:text
        color: parent.textcolor
        text: label;
        width: parent.width
        height: parent.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    signal clickedObject(string quuid)
    MouseArea{
        id: mouse
        z:100
        anchors.fill: parent
        objectName: "thisMouseArea"
        onClicked: {
            clickedObject(parent.uuid)
        }
    }
}
