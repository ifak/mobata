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

    Flickable {
        clip: true
        x:0
        y:0
        objectName: "zoomObject"
        id: graphArea
        width:  root.width
        height: root.height
        contentWidth: drawArea.width*scaleObj.xScale
        contentHeight: drawArea.height*scaleObj.yScale+20
        boundsBehavior: Flickable.StopAtBounds

        GridLayout{
            clip: true
            id: drawArea
            x:0
            y:0
            objectName: "drawArea"
            rowSpacing: 10
            columns: 3
            transform: Scale {id: scaleObj; objectName: "scale"; xScale: 1; yScale: 1;}

            function createSpacer(){
                var component = Qt.createComponent("msc_spacer.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.minimumHeight=10;
                return object;
            }
            function createComponentSpacer(){
                var component = Qt.createComponent("msc_compspacer.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.minimumHeight=10;

                var object2 = component.createObject(compArea,{});
                object2.Layout.fillWidth=true;
                object2.Layout.fillHeight=true;
                object2.objectName = "msc_compspacer_head";

                return object;

            }
            function createComponent(Label,uuid,span,column,color,radius,textcolor){
                var component = Qt.createComponent("msc_component.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.columnSpan=span;
                object.label=Label;
                object.span=span;
                object.uuid=uuid;
                object.column=column;
                object.compcolor=color;
                object.curve=radius;
                object.textcolor=textcolor;
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.maximumHeight=object.prefHeight*1.2;
                object.Layout.minimumHeight=object.prefHeight;

                var object2 = component.createObject(compArea,{});
                object2.objectName="msc__component_head"
                object2.Layout.fillWidth=true;
                object2.Layout.fillHeight=true;
                object2.Layout.columnSpan=span;
                object2.label=Label;
                object2.span=span;
                object2.uuid=uuid;
                object2.column=column;
                object2.compcolor=color;
                object2.curve=radius;
                object2.textcolor=textcolor;

                return object;
            }
            function createStatement(Label,span,color,radius,textcolor,uuid){
                var component = Qt.createComponent("msc_statement.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.columnSpan=span;
                object.label=Label;
                object.uuid = uuid;
                object.textcolor = textcolor
                object.radius = radius
                object.color = color
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.maximumHeight=object.prefHeight*1.2;
                object.Layout.minimumHeight=object.prefHeight;
                return object;
            }
            function createTimer(Label,span,color,radius,textcolor,uuid){
                var component = Qt.createComponent("msc_timer.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.columnSpan=span;
                object.label=Label;
                object.uuid = uuid;
                object.textcolor = textcolor
                object.radius = radius
                object.color = color
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.maximumHeight=object.prefHeight*1.2;
                object.Layout.minimumHeight=object.prefHeight;
                return object;
            }
            function createMessageStart(dir,color){
                var component = Qt.createComponent("msc_message_start.qml");
                var object = component.createObject(drawArea,{});
                object.linecolor = color;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.dir = dir;
                return object;
            }
            function createMessageEnd(dir,color){
                var component = Qt.createComponent("msc_message_end.qml");
                var object = component.createObject(drawArea,{});
                object.linecolor = color;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.dir = dir;
                return object;
            }
            function createMessageLoop(color){
                var component = Qt.createComponent("msc_message_loop.qml");
                var object = component.createObject(drawArea,{});
                object.linecolor = color;
                object.Layout.minimumHeight=15
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                return object;
            }
            function createMessageText(Label, textcolor, span){
                var component = Qt.createComponent("msc_message.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.columnSpan=span;
                object.label = Label;
                object.textcolor = textcolor;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                return object;
            }
            function createMessageArrow(Label,span,dir,color,textcolor,uuid){
                var component = Qt.createComponent("msc_message_arrow.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.columnSpan=span;
                object.label=Label;
                object.dir = dir;
                object.uuid = uuid;
                object.linecolor=color;
                object.textcolor=textcolor;
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.minimumHeight=object.prefHeight;
                return object;
            }
            function createFragment(Label,span,color){
                var component = Qt.createComponent("msc_fragment.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.label=Label;
                object.textcolor = color;
                object.Layout.columnSpan=span;
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.maximumHeight=object.prefHeight*1.2;
                object.Layout.minimumHeight=object.prefHeight;
                return object;
            }
            function createFragmentStart(uuid,label){
                var component = Qt.createComponent("msc_fragment_start.qml");
                var object = component.createObject(drawArea,{});
                object.uuid = uuid;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.preferredWidth=10;
                object.Layout.preferredHeight=10;
                object.label=label;
                return object;
            }
            function createFragmentEnd(uuid){
                var component = Qt.createComponent("msc_fragment_end.qml");
                var object = component.createObject(drawArea,{});
                object.uuid = uuid;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.preferredWidth=10;
                object.Layout.preferredHeight=10;
                return object;
            }
            function createRegion(Label,span,color){
                var component = Qt.createComponent("msc_region.qml");
                var object = component.createObject(drawArea,{});
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.textcolor = color
                object.label=Label;
                object.Layout.columnSpan=span;
                object.Layout.preferredWidth=object.prefWidth;
                object.Layout.preferredHeight=object.prefHeight;
                object.Layout.maximumHeight=object.prefHeight*1.2;
                object.Layout.minimumHeight=object.prefHeight;
                return object;
            }
            function createRegionStart(uuid){
                var component = Qt.createComponent("msc_region_start.qml");
                var object = component.createObject(drawArea,{});
                object.uuid = uuid;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.preferredWidth=10;
                object.Layout.preferredHeight=10;
                return object;
            }
            function createRegionEnd(uuid){
                var component = Qt.createComponent("msc_region_end.qml");
                var object = component.createObject(drawArea,{});
                object.uuid = uuid;
                object.Layout.fillWidth=true;
                object.Layout.fillHeight=true;
                object.Layout.preferredWidth=10;
                object.Layout.preferredHeight=10;
                return object;
            }
            function setMinimumWidth(width){
                var object = drawArea.children[0]
                object.Layout.minimumWidth=width;
                var object2 = drawArea.children[columns-1]
                object2.Layout.minimumWidth=width;
                return object;
            }
        }

        Rectangle{
            id: compRect
            width: parent.width * skal.xScale
            height:compArea.height * skal.yScale
            x:0
            y: graphArea.contentY

            color: root.color

            GridLayout{
                property int height1
                property int height2
                property int counter
                x:0
                y:0
                clip:false
                objectName: "compArea"
                id: compArea
                columns: drawArea.columns
                rowSpacing: drawArea.rowSpacing
                transform: Scale {id: skal; xScale: scaleObj.xScale; yScale: scaleObj.yScale;}
                function setSize(index,height,width){
                    var object = compArea.children[index]
                    object.Layout.minimumWidth = width;
                    object.Layout.maximumWidth = width;
                    object.Layout.minimumHeight = height;
                    object.Layout.maximumHeight = height;
                }
            }
        }

        onYChanged: {
            compRect.y = -y*(1/scaleObj.yScale)
            if(compRect.y < 0){
                compRect.y = 0
            }
        }

        ScrollBar.vertical: ScrollBar{
            parent: graphArea.parent
            anchors.top: graphArea.top
            anchors.right: graphArea.right
            anchors.bottom: graphArea.bottom
            policy: ScrollBar.AsNeeded
            opacity: 1
            orientation: Qt.Vertical
        }
        ScrollBar.horizontal: ScrollBar{
            parent: graphArea.parent
            anchors.right: graphArea.right
            anchors.left: graphArea.left
            anchors.bottom: graphArea.bottom
            policy: ScrollBar.AsNeeded
            opacity: 1
            orientation: Qt.Horizontal
        }
    }
}
