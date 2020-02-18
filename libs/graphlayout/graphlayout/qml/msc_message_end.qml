import QtQuick 2.12
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
