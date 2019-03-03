GRAPHLAYOUT_LIBRARY_TYPE = staticlib

include($$PWD/../graphlayout.pri)

TEMPLATE = lib

RootDir=$$PWD/..

linux:CONFIG -= qtquickcompiler

CONFIG += $${GRAPHLAYOUT_LIBRARY_TYPE}

TARGET = $$GRAPHLAYOUT_NAME
LIBS -= -l$$GRAPHLAYOUT_NAME

# next lines should only be un-commented if antlr-grammars are changed
# variable ANTLR_HOME has to be set!

#win*{
#  ANTLR_JAR = C:\Users\s_phs.DESKTOP-9GA53KK\Documents\mobata\3rd\antlr4-cpp\bin\antlr-4.7-complete.jar
#}else{
#  ANTLR_JAR = $$ANTLR_HOME/bin/antlr-4.7-complete.jar
#}
#ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/graphvizparser/grammars/DOT.g4 -o $$PWD/graphvizparser)

HEADERS += \
    comcreategraphvizfile.hpp \
    comcreatelayout.hpp \
    layoutedge.hpp \
    layoutgraph.hpp \
    layoutnode.hpp \
    types.hpp \
    graphvizparser/comcreategraphvizgraph.hpp \
    graphvizparser/graphvizgraph.hpp \
    graphvizparser/DOTLexer.h \
    graphvizparser/DOTListener.h \
    graphvizparser/DOTParser.h \
    graphvizparser/DOTBaseListener.h \
    graphlayout_global.hpp \
    layoutnodeport.hpp \
    layoutglobal.hpp \
    comcreatelayoutedgesonly.hpp \
    comgraphts.hpp \
    comcreatesutgraph.hpp \
    comcreatestatemachinegraph.hpp \
    comcreatespenatgraph.hpp \
    comcreatedeclgraph.hpp \
    graphquickwidget.hpp \
    mscquickwidget.hpp \
    qmlgraphview.hpp \
    io/comloadjsonlayout.hpp \
    io/readlayout.hpp \
    io/writelayout.hpp \
    io/comsavejsonlayout.hpp \
    layoututils.hpp \
    qmledge.hpp \
    qmlnode.hpp \
    comexportmscgraph.hpp \
    comexportgraph.hpp \
    layoutroles.hpp \
    graphvizparser/dotmodellistener.hpp

SOURCES += \
    comcreategraphvizfile.cpp \
    comcreatelayout.cpp \
    layoutedge.cpp \
    layoutgraph.cpp \
    layoutnode.cpp \
    graphvizparser/comcreategraphvizgraph.cpp \
    graphvizparser/graphvizgraph.cpp \
    graphvizparser/DOTLexer.cpp \
    graphvizparser/DOTParser.cpp \
    graphvizparser/dotmodellistener.cpp \
    layoutnodeport.cpp \
    comcreatelayoutedgesonly.cpp \
    comgraphts.cpp \
    comcreatesutgraph.cpp \
    comcreatestatemachinegraph.cpp \
    comcreatespenatgraph.cpp \
    comcreatedeclgraph.cpp \
    graphquickwidget.cpp \
    mscquickwidget.cpp \
    qmlgraphview.cpp \
    io/comloadjsonlayout.cpp \
    io/comsavejsonlayout.cpp \
    io/readlayout.cpp \
    io/writelayout.cpp \
    layoututils.cpp \
    qmledge.cpp \
    qmlnode.cpp \
    comexportmscgraph.cpp \
    comexportgraph.cpp
	
DISTFILES += \
    graphvizparser/grammars/DOT.g4 \
    graphvizparser/DOT.tokens \
    graphvizparser/DOTLexer.tokens \
    qml/qtquickcontrols2.conf \
#graphview files
    qml/graph_main.qml \
    qml/GraphText.qml \
#mscview files
    qml/msc_main.qml \
    qml/msc_component.qml \
    qml/msc_compspacer.qml \
    qml/msc_fragment.qml \
    qml/msc_fragment_end.qml \
    qml/msc_fragment_start.qml \
    qml/msc_lifeline.qml \
    qml/msc_message.qml \
    qml/msc_message_arrow.qml \
    qml/msc_message_end.qml \
    qml/msc_message_start.qml \
    qml/msc_region.qml \
    qml/msc_region_end.qml \
    qml/msc_region_start.qml \
    qml/msc_regionline.qml \
    qml/msc_spacer.qml \
    qml/msc_statement.qml \
    qml/msc_timer.qml \
    qml/GraphEdge_old.qml \
    qml/GraphEdge.qml \
    qml/GraphNode_old.qml \
    qml/GraphNode.qml

RESOURCES += \
    graphlayout.qrc
