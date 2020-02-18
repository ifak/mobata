import QtQuick 2.12
Rectangle{
    objectName: "msc_messageloop"
    property color linecolor: "black"
    color:"transparent"
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
            ctx.moveTo(width/2, 1)
            ctx.lineTo(width, 1)
            ctx.lineTo(width, height - 5)
            ctx.lineTo(width/2, height - 5)

            ctx.moveTo(width/2, height - 5)
            ctx.lineTo(width/2 + 5, height)

            ctx.moveTo(width/2, height - 5)
            ctx.lineTo(width/2 + 5, height - 10)

            ctx.moveTo(width/2, 1)
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
