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
Canvas {
    objectName: "node"
    signal posChanged(string msg)
    signal showInfoBox(string uuid)
    property string uuid
    property string shape
    property string label
    property point labelPos
    property string xLabel

    property bool token: false
    property color tokencolor: "black"

    property color color: "white"
    property real borderWidth: 2
    property color borderColor: "black"
    property real textSize: 12
    property color textColor: "black"
    property string textFamily: "serif"

    property bool infoBox: false

    antialiasing: true
    clip: true

    onPaint:{
        var ctx = getContext("2d")
        ctx.clearRect(0,0,3000, 3000)
        ctx.lineCap = "round"
        ctx.lineJoin = "round"
        ctx.fillStyle = color
        if(shape == "3"){
            ctx.strokeStyle=color
        }else{
            ctx.strokeStyle=borderColor
        }
        ctx.lineWidth=borderWidth
        ctx.beginPath()

        /*------------------------------------------------------------------------
        rect
------------------------------------------------------------------------*/
        if(shape == "0"){
            ctx.moveTo(3,3)
            ctx.lineTo(3,height-3)
            ctx.lineTo(width-3,height-3)
            ctx.lineTo(width-3,3)
            ctx.lineTo(3,3)
            /*------------------------------------------------------------------------
        roundedRect
------------------------------------------------------------------------*/
        }else if(shape == "1"){
            ctx.roundedRect(3,3,width-6,height-6,height/4,height/4)
            /*------------------------------------------------------------------------
        ellipse
------------------------------------------------------------------------*/
        }else if(shape == "2"){
            ctx.ellipse(2,2,width-4,height-4)
            /*------------------------------------------------------------------------
        point
------------------------------------------------------------------------*/
        }else if(shape == "3"){
            ctx.arc(width/2,height/2,height/2,0,2*Math.PI,true)
            /*------------------------------------------------------------------------
        circle
------------------------------------------------------------------------*/
        }else if(shape == "4"){
            ctx.arc(width/2,height/2,height/2-3,0,2*Math.PI,true)

            /*------------------------------------------------------------------------
        diamond
------------------------------------------------------------------------*/
        }else if(shape == "5"){
            ctx.moveTo(width/2,5)
            ctx.lineTo(5,height/2)
            ctx.lineTo(width/2,height-5)
            ctx.lineTo(width-5,height/2)
            ctx.lineTo(width/2,5)
            /*------------------------------------------------------------------------
        parallelogram
------------------------------------------------------------------------*/
        }else if(shape == "6"){
            ctx.moveTo(width/5,3);
            ctx.lineTo(width-3,3);
            ctx.lineTo(width-width/5,height-3);
            ctx.lineTo(3,height-3);
            ctx.lineTo(width/5,3);
            /*------------------------------------------------------------------------
        triangle
------------------------------------------------------------------------*/
        }else if(shape == "7"){
            ctx.moveTo(3,height-height/4);
            ctx.lineTo(width/2,3);
            ctx.moveTo(width/2,3);
            ctx.lineTo(width-3,height-height/4);
            ctx.moveTo(width-3,height-height/4);
            ctx.lineTo(3,height-height/4);
            /*------------------------------------------------------------------------
        invtriangle
------------------------------------------------------------------------*/
        }else if(shape == "8"){
            ctx.moveTo(3,height/4);
            ctx.lineTo(width/2,height-3);
            ctx.moveTo(width/2,height-3);
            ctx.lineTo(width-3,height/4);
            ctx.moveTo(width-3,height/4);
            ctx.lineTo(3,height/4);
            /*------------------------------------------------------------------------
        trapezium
------------------------------------------------------------------------*/
        }else if(shape == "9"){
            ctx.moveTo(width/5,3);
            ctx.lineTo(width-width/5,3);
            ctx.lineTo(width-3,height-3);
            ctx.lineTo(3,height-3);
            ctx.lineTo(width/5,3);
            /*------------------------------------------------------------------------
        invtrapezium
------------------------------------------------------------------------*/
        }else if(shape == "10"){
            ctx.moveTo(3,3);
            ctx.lineTo(width-3,3);
            ctx.lineTo(width-width/5,height-3);
            ctx.lineTo(width/5,height-3);
            ctx.lineTo(3,3);
            /*------------------------------------------------------------------------
        octagon
------------------------------------------------------------------------*/
        }else if(shape == "11"){
            ctx.moveTo(width/3,3);
            ctx.lineTo(2*width/3,3);
            ctx.lineTo(width-3,height/3);
            ctx.lineTo(width-3,2*height/3);
            ctx.lineTo(2*width/3,height-3);
            ctx.lineTo(width/3,height-3);
            ctx.lineTo(3,2*height/3);
            ctx.lineTo(3,height/3);
            ctx.lineTo(width/3,3);
            /*------------------------------------------------------------------------
        hexagon
------------------------------------------------------------------------*/
        }else if(shape == "12"){
            ctx.moveTo(width/4,3);
            ctx.lineTo(3*width/4,3);
            ctx.lineTo(width-3,height/2);
            ctx.lineTo(3*width/4,height-3);
            ctx.lineTo(width/4,height-3);
            ctx.lineTo(3,height/2);
            ctx.lineTo(width/4,3);
            /*------------------------------------------------------------------------
        square
------------------------------------------------------------------------*/
        }else if(shape == "13"){
            ctx.moveTo(3,3);
            ctx.lineTo(width-3,3);
            ctx.lineTo(width-3,height-3);
            ctx.lineTo(3,height-3);
            ctx.lineTo(3,3);
            /*------------------------------------------------------------------------
    box3d
------------------------------------------------------------------------*/
        }else if(shape == "14"){
            ctx.moveTo(3+width/20,3);
            ctx.lineTo(width-3,3);
            ctx.lineTo(width-3-width/20,3+height/20);
            ctx.lineTo(3,3+height/20);
            ctx.lineTo(3+width/20,3);

            ctx.moveTo(3,3+height/20);
            ctx.lineTo(3,height-3);
            ctx.lineTo(width-3-width/20,height-3);
            ctx.lineTo(width-3-width/20,3+height/20);
            ctx.lineTo(3,3+height/20);

            ctx.moveTo(width-3,3);
            ctx.lineTo(width-3,height-3-height/20);
            ctx.lineTo(width-3-width/20,height-3);
            ctx.lineTo(width-3-width/20,3+height/20);
            ctx.lineTo(width-3,3);
            /*------------------------------------------------------------------------
Plaintext
------------------------------------------------------------------------*/
        }else if(shape == "15"){
        }
        /*------------------------------------------------------------------------
    draw + text
------------------------------------------------------------------------*/
        ctx.fill()
        ctx.closePath()
        ctx.stroke()
        /*------------------------------------------------------------------------
Token
------------------------------------------------------------------------*/
        if(token == true){
            ctx.beginPath()
            ctx.fillStyle = tokencolor
            ctx.strokeStyle = tokencolor
            ctx.moveTo(width/2,10);
            ctx.arc(width/2,10,5,0,2*Math.PI,true)
            ctx.fill()
            ctx.closePath()
            ctx.stroke()
        }
    }
    Text{
        objectName: "XLabel"
        width: parent.width - 10
        height: parent.height - 10
        x: 5
        y: 5
        color: parent.textColor
        font.pixelSize: parent.textSize
        font.family: parent.textFamily
        text: parent.xLabel
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    onColorChanged:         requestPaint()
    onBorderWidthChanged:   requestPaint()
    onBorderColorChanged:   requestPaint()
    onTextSizeChanged:      requestPaint()
    onTextColorChanged:     requestPaint()
    onTextFamilyChanged:    requestPaint()
    onWidthChanged:         requestPaint()
    onHeightChanged:        requestPaint()
    onShapeChanged:         requestPaint()
    onTokenChanged:         requestPaint()
    onTokencolorChanged:    requestPaint()
    MouseArea{
        z: 100
        anchors.fill: parent
        objectName: "thisMouseArea"
        id: mousearea
        onClicked:{
            if(parent.infoBox==true){
                showInfoBox(parent.uuid)
            }
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: parent.requestPaint()
    }
}
