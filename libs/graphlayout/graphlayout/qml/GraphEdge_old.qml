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

import QtQuick 2.0
Canvas{
    objectName: "edge"
    signal showInfoBox(string uuid)
    property bool infoBox: false

    property var points
    property string label
    property real labelPosX
    property real labelPosY

    property string uuid
    property int type:1
    property int splines:0

    property real lineWidth:3
    property color lineColor: "black"
    property real arrowSize:15
    property real textSize: 0
    property color textColor
    property string textFamily: "serif"

    antialiasing: false
    id:line
    clip: true
    width: 2000
    height: 2000

    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth=lineWidth
        ctx.fillStyle = lineColor
        ctx.strokeStyle=lineColor
        ctx.clearRect(0,0,width, height)
        //start drawing when points are availble-------------------------------------------------------------------
        if(points.length>=2){
            ctx.lineJoin="round"
            ctx.lineCap = "round"
            var headlen = arrowSize
            //init path variable-----------------------------------------------------------------------------
            var pathString = 'import QtQuick 2.0; Path{startX:'+(points[0].x-x)+'; startY:'+(points[0].y-y)+';'
            //curve--------------------------------------------------------------------------------------
            if(splines == 5){
                for(var i = 1; i<points.length;i++){
                    pathString += 'PathCurve{x:'+(points[i].x-x)+'; y:'+(points[i].y-y)+'}'
                }
                //spline--------------------------------------------------------------------------------------
            }else if(splines == 2){
                for(var i = 1; i<points.length;i++){
                    pathString += 'PathCurve{x:'+(points[i].x-x)+'; y:'+(points[i].y-y)+'}'
                }
                //line------------------------------------------------------------------------------------------
            }else if(splines == 1 || splines == 3 || splines == 4){
                for(var i = 1; i<points.length;i++){
                    pathString += 'PathLine{x:'+(points[i].x-x)+'; y:'+(points[i].y-y)+'}'
                }
            }else if(splines == 6){
                pathString += 'PathLine{x:'+(points[0].x-x)+'; y:'+(points[0].y-y)+'}'
                pathString += 'PathLine{x:'+(points[points.length-1].x-x)+'; y:'+(points[points.length-1].y-y)+'}'
            }
            //create PathObject--------------------------------------------------------------------------------------
            pathString += "}"
            var object = Qt.createQmlObject(pathString,line,"dynamicPath")
            //draw Path
            ctx.moveTo(points[0].x-x,points[0].y-y)
            ctx.beginPath()
            ctx.path = object
            ctx.moveTo(points[0].x-x,points[0].y-y)
            ctx.closePath();
            ctx.stroke();
            //draw ControllPoints--------------------------------------------------------------------------
            //for(var i = 0; i<points.length;i++){
                //                ctx.moveTo(points[i].x-x-5,points[i].y-y)
                //                ctx.lineTo(points[i].x-x+5,points[i].y-y)
                //                ctx.moveTo(points[i].x-x,points[i].y-y+5)
                //                ctx.lineTo(points[i].x-x,points[i].y-y-5)
                //ctx.fillText(i,points[i].x-x,points[i].y-y+10)
            //}
            //calculate angle for the edge head------------------------------------------------------------
            var angle2 = Math.atan2(points[points.length-1].y-points[points.length-2].y, points[points.length-1].x-points[points.length-2].x);
            //calculate angle for the edge tail------------------------------------------------------------
            var angle1 = Math.atan2(points[1].y-points[0].y,points[1].x-points[0].x);
            //draw arrow head---------------------------------------------------------------------------------------
            if(type == 0 | type == 2){
                ctx.moveTo(points[points.length-1].x-x, points[points.length-1].y-y)
                ctx.lineTo(points[points.length-1].x-x-headlen*Math.cos(angle2-Math.PI/6),points[points.length-1].y-y-headlen*Math.sin(angle2-Math.PI/6));
                ctx.moveTo(points[points.length-1].x-x, points[points.length-1].y-y)
                ctx.lineTo(points[points.length-1].x-x-headlen*Math.cos(angle2+Math.PI/6),points[points.length-1].y-y-headlen*Math.sin(angle2+Math.PI/6));
                ctx.closePath();
                ctx.stroke();
            }
            if(type == 4){
                var boxsize = headlen/2
                ctx.moveTo(points[points.length-1].x+boxsize-x, points[points.length-1].y+boxsize-y)
                ctx.beginPath()
                ctx.lineTo(points[points.length-1].x+boxsize-x, points[points.length-1].y-boxsize-y)
                ctx.lineTo(points[points.length-1].x-boxsize-x, points[points.length-1].y-boxsize-y)
                ctx.lineTo(points[points.length-1].x-boxsize-x, points[points.length-1].y+boxsize-y)
                ctx.lineTo(points[points.length-1].x+boxsize-x, points[points.length-1].y+boxsize-y)
                ctx.fill();
                ctx.closePath();

            }
            //draw arrow tail-----------------------------------------------------------------------------------------
            if(type == 3 | type == 2){
                ctx.moveTo(points[0].x-x, points[0].y-y)
                ctx.lineTo(points[0].x-x+headlen*Math.cos(angle1-Math.PI/6),points[0].y-y+headlen*Math.sin(angle1-Math.PI/6));
                ctx.moveTo(points[0].x-x, points[0].y-y)
                ctx.lineTo(points[0].x-x+headlen*Math.cos(angle1+Math.PI/6),points[0].y-y+headlen*Math.sin(angle1+Math.PI/6));
                ctx.closePath();
                ctx.stroke();
            }
            //close and draw Path-----------------------------------------------------------------------------------------
            object.destroy();
        }
    }
    Text{
        text: label
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
        font.pixelSize: textSize
        font.family: textFamily
        color: textColor
        clip: true
        x:labelPosX
        y:labelPosY
        MouseArea{
            anchors.fill: parent
            drag.target: parent
        }
    }
    MouseArea{
        x:0
        y:0
        width: 10
        height: 10
        objectName: "thisMouseArea"
        id: mousearea
        onClicked:{
            if(parent.infoBox==true){
                showInfoBox(parent.uuid)
            }
        }
    }
    onLineColorChanged: requestPaint()
    onLineWidthChanged: requestPaint()
    onArrowSizeChanged: requestPaint()
    onPointsChanged:    requestPaint()
    onWidthChanged:     requestPaint()
    onHeightChanged:    requestPaint()
    onXChanged:         requestPaint()
    onYChanged:         requestPaint()
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: parent.requestPaint()
    }
}
