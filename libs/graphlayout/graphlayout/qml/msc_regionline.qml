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
Canvas {
    anchors.fill:{
        if(parent){
            anchors.fill = parent
        }
    }

    id: regionline
    objectName: "msc_regionline"
    property string label
    property string uuid
    property var startPos
    property var endPos
    property int intend: 0
    property int type: 0
    property color linecolor: "black"
    property color textcolor: "black"
    x:0
    y:0
    z: -100+intend
    onPaint: {
        if(startPos && endPos && intend){
            var ctx = getContext("2d")
            ctx.lineWidth=2
            ctx.fillStyle = linecolor
            ctx.strokeStyle=linecolor
            ctx.clearRect(0,0,width, height)
            ctx.beginPath()
            if(type == 0){
                ctx.moveTo(startPos.x-2-intend,startPos.y-2)
                ctx.lineTo(endPos.x+2+intend, startPos.y-2)
                ctx.lineTo(endPos.x+2+intend, endPos.y-2)
                ctx.lineTo(startPos.x-2-intend, endPos.y-2)
                ctx.lineTo(startPos.x-2-intend, startPos.y-2)
                ctx.moveTo(startPos.x-2-intend,startPos.y-2)
            }else if(type == 1){
                ctx.moveTo(startPos.x-2-intend,startPos.y-2)
                for(var i = 0; i <= ( (endPos.x+2+intend) - (startPos.x-2-intend) ) / 10; i++){
                    ctx.moveTo(startPos.x-2-intend+(i*10),startPos.y-2)
                    ctx.lineTo(startPos.x-2-intend+(i*10)+5,startPos.y-2)
                }
                ctx.moveTo(startPos.x-2-intend,startPos.y-2)
            }

            ctx.closePath()
            ctx.stroke()
        }
    }
    Rectangle{
        id: labelbox
        x:-100
        y:-100
        height: 18
        width: 35
        border.color: regionline.linecolor
        border.width: 2
        Text{
            anchors.fill: parent
            text: "  " + regionline.label
            horizontalAlignment: Text.AlignLeft
            verticalAlignment:  Text.AlignVCenter
            color: regionline.textcolor
        }
    }

    onStartPosChanged:{
        requestPaint()
        if(type==0){
            labelbox.x = startPos.x - 2 - intend
            labelbox.y = startPos.y - 2
        }
    }
    onEndPosChanged:{
        requestPaint();
        if(type==0){
            labelbox.x = startPos.x - 2 - intend
            labelbox.y = startPos.y - 2
        }
    }
    onLinecolorChanged: requestPaint();
    onTypeChanged: {
        if(type != 0){
            labelbox.destroy()
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: parent.requestPaint()
    }
}
