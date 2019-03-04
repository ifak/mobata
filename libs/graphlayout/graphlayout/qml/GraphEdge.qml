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
import QEdge 1.0

QmlEdge{
    id:edge
    objectName: "edge"
    width:2000
    height:2000
    z:4000
    skale: {if(parent){parent.skale}else{1}}
    Text{
        text: label
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
        font.pixelSize: textSize*edge.skale
        font.family: textFamily
        color: textColor
        clip: true
        x:labelPos.x
        y:labelPos.y
        MouseArea{
            anchors.fill: parent
            drag.target: parent
        }
    }
    MouseArea{
        x:0
        y:0
//        width: 10
//        height: 10
        anchors.fill: parent
        objectName: "thisMouseArea"
        id: mousearea
        propagateComposedEvents: true
        onClicked:{
            if(edge.containsPos(mouseX, mouseY) == true){
                edgeClicked(edge.uuid)
                mouse.accepted = true
            }else{
                mouse.accepted = false
            }
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: edge.update()
    }
}
