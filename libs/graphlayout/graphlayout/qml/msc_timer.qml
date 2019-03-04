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
    id: timer
    objectName: "msc__timer"
    width: 1
    height: 1
    radius: 20
    property color textcolor: "black"
    property string uuid: ""
    property string label: ""
    property color borderColor: "transparent"

    border.color: timer.borderColor
    border.width: 2

    color: "lightgreen"
    Text{
        id:text
        color: timer.textcolor
        text: timer.label;
        width: timer.width
        height: timer.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    property int prefWidth: text.contentWidth * 1.7
    property int prefHeight: text.contentHeight * 1.7
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
