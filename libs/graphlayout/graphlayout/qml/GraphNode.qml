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
import QNode 1.0

QmlNode {
    objectName: "node"
    id: node
    z: 0
    skale: {if(parent){parent.skale}else{1}}
    MouseArea{
        anchors.fill: parent
        objectName: "thisMouseArea"
        id: mousearea
        onClicked:{
            nodeClicked(node.uuid)
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: node.repaint()
    }
}
