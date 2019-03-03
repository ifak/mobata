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
Rectangle{
    objectName: "msc__arrow"
    color:"transparent"
    property int dir: 1
    property string label: ""
    property string uuid: ""
    property int prefWidth: text.contentWidth*1.7
    property int prefHeight: text.contentHeight * 1.7
    property color linecolor: "black"
    property color textcolor: "black"
    property int colStartWidth
    property int colEndWidth
    Canvas {
        height:parent.height
        width: parent.width
        onPaint: {
            var ctx = getContext("2d")
            ctx.lineWidth=2
            ctx.fillStyle = parent.linecolor
            ctx.strokeStyle = parent.linecolor
            ctx.clearRect(0,0,width, height)
            ctx.beginPath()
            if(parent.dir == 1){
                ctx.moveTo(0, height-5)
                ctx.lineTo(width, height-5)
            }else{
                ctx.moveTo(width, height-5)
                ctx.lineTo(0, height-5)
            }
            ctx.closePath()
            ctx.stroke()
        }
        onWidthChanged: requestPaint()
        onHeightChanged: requestPaint()
        Timer {
            interval: 1000
            running: true
            repeat: true
            onTriggered: parent.requestPaint()
        }
    }
    Text{
        id:text
        text: label
        color: parent.textcolor
        width: parent.width
        height: parent.height-10
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
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
