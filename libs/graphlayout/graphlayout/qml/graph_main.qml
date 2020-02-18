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

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Rectangle{
    objectName: "root"
    id: root
    visible: true
    color: "white"
    Rectangle {
        x:0
        y:0
        width: parent.width - x
        height:parent.height - y
        objectName: "zoomObject"
        signal unhighlight()
        id: graphArea
        property real skale: 1.0
        scale: 1.0
        transformOrigin: Item.TopLeft
        color: parent.color
        MouseArea{
            anchors.fill:parent
            objectName: "rootMouseArea"
            onScaleChanged: {
                anchors.fill=root
            }
            onWheel: {
                if(Qt.ControlModifier & wheel.modifiers){
                    if(graphArea.skale + wheel.angleDelta.y / 4000 > 0.01 & graphArea.skale + wheel.angleDelta.y / 4000 < 10){
                        graphArea.skale += wheel.angleDelta.y / 4000
                    }
                }else{
                    if(graphArea.y + wheel.angleDelta.y/12 < 0){
                        graphArea.y += wheel.angleDelta.y/12
                    }
                    if(graphArea.x + wheel.angleDelta.x/12 < 0){
                        graphArea.y += wheel.angleDelta.x/12
                    }
                }
            }
            drag.target: graphArea
            drag.maximumX: 0
            drag.maximumY: 0
            onClicked: {
                graphArea.unhighlight();
            }
        }
        Rectangle{
            property real skale: parent.skale
            clip:true
            objectName: "drawArea"
            id: nodeArea
            anchors.fill: parent
            color: "transparent"

        }
    }
    Text{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        text: "Zoom:" + Math.round(graphArea.skale*100)/100
    }
}
