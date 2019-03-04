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
Text{
    objectName: "text"
    property string uuid
    property real textSize:12
    property string textFamiliy: "serif"
    property color textColor
    property real parentPosX
    property real parentPosY
    property real labelPosX:0
    property real labelPosY:0

    property real skale: {if(parent){parent.skale}else{1}}

    clip: true
    font.pixelSize: textSize
    font.family: textFamiliy
    color: textColor
    x: (parentPosX - contentWidth/2) * skale
    y: (parentPosY - contentHeight/2) * skale
    z: 2000
    MouseArea{
        objectName: "labelMouseArea"
        anchors.fill: parent
        drag.target: parent
    }
}
