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
    objectName: "msc__component"
    id: rect
    property int curve: 10
    property int span: 1
    property int column:-1
    property string label: ""
    property string uuid: ""
    property color textcolor: "black"
    property color compcolor: "yellow"
    property color borderColor: "transparent"
    width: 10
    height: 10
    radius:rect.curve
    color: rect.compcolor
    border.color: rect.borderColor
    border.width: 2
    Text{
        id:text
        color: rect.textcolor
        width: rect.width
        height: rect.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: rect.label;
    }
    property int prefWidth: text.contentWidth*1.7
    property int prefHeight: {
        if(text.contentHeight > 6){
            return text.contentHeight * 1.7
        }else{
            return 20
        }
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
