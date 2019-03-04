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
    property var par
    id: lifeline
    objectName: "msc_lifeline"
    property color color
    property string compUuid
    anchors.top: {if(par){par.top}}
    anchors.bottom: {if(par){par.bottom}}
    width: 10
    clip: true
    z: -20
    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth=2
        ctx.fillStyle = color
        ctx.strokeStyle = color
        ctx.clearRect(0,0,width, height)
        ctx.beginPath()
        ctx.moveTo(width/2, 10)
        ctx.lineTo(width/2, height)
        ctx.closePath()
        ctx.stroke()
    }
    onParentChanged:{
        par = parent;
    }
    onXChanged: requestPaint();
    function updateX(pos){
        lifeline.x = pos-5;
        height = parent.height;
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: parent.requestPaint()
    }
}
