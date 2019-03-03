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
    objectName: "msc_messageend"
    color:"transparent"
    property int dir: 1
    property color linecolor: "black"
    Canvas {
        height:parent.height
        width: parent.width
        onPaint: {
            var ctx = getContext("2d")
            ctx.lineWidth=2
            ctx.fillStyle = linecolor
            ctx.strokeStyle=linecolor
            ctx.clearRect(0,0,width, height)
            ctx.beginPath()
            if(parent.dir == 1){
                ctx.moveTo(0, height-5)
                ctx.lineTo(width/2, height-5)

                ctx.moveTo(width/2, height-5)
                ctx.lineTo(width/2-5,height)

                ctx.moveTo(width/2, height-5)
                ctx.lineTo(width/2-5,height-10)

                ctx.moveTo(width/2, height-5)
            }else{
                ctx.moveTo(width, height-5)
                ctx.lineTo(width/2, height-5)

                ctx.moveTo(width/2, height-5)
                ctx.lineTo(width/2+5,height)

                ctx.moveTo(width/2, height-5)
                ctx.lineTo(width/2+5,height-10)

                ctx.moveTo(width/2, height-5)
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
}
