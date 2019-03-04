DSLPARSER_LIBRARY_TYPE = staticlib

include(dslparser.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${DSLPARSER_LIBRARY_TYPE}

TARGET = $$DSLPARSER_NAME
LIBS -= -l$$DSLPARSER_NAME

#DEFINES+=QT_NO_DEBUG_OUTPUT

#QMAKE_CXXFLAGS_WARN_ON = -Wall -Wextra -Wno-attributes
#QMAKE_CXXFLAGS_WARN_OFF = -Wattributes
win32-msvc*:QMAKE_CXXFLAGS += -wd4267
win64-msvc*:QMAKE_CXXFLAGS += -wd4267

# next lines should only be un-commented if antlr-grammars are changed
# variable ANTLR_HOME has to be set!

win*{
  ANTLR_JAR = $$ANTLR_HOME\bin\antlr-4.7.2-complete.jar
}else{
  ANTLR_JAR = $$ANTLR_HOME/bin/antlr-4.7.2-complete.jar
}

ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/CommonLexer.g4 -o $$PWD/common)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/CommonDecl.g4 -o $$PWD/common)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/Spenat.g4 -o $$PWD/spenat)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/SutDecl.g4 -o $$PWD/sut)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/TestSystemDecl.g4 -o $$PWD/testsystem)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/TestCaseDecl.g4 -o $$PWD/testcase)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/ImportReader.g4 -o $$PWD/importreader)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/StateMachine.g4 -o $$PWD/statemachine)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/Irdl.g4 -o $$PWD/irdl)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/IrdlCommonDecl.g4 -o $$PWD/irdldecl)
ParserError = $$system(java -jar $$ANTLR_JAR -Dlanguage=Cpp $$PWD/grammars/SimSystemDecl.g4 -o $$PWD/simsystem)

DISTFILES += \
    grammars/CommonLexer.g4 \
    grammars/Spenat.g4 \
    dslparser.pri \
    spenat/Spenat.tokens \
    spenat/SpenatLexer.tokens \
    common/CommonLexer.tokens \
    grammars/CommonDecl.g4 \
    common/CommonDecl.tokens \
    common/CommonDeclLexer.tokens \
    grammars/SutDecl.g4 \
    sut/SutDecl.tokens \
    sut/SutDeclLexer.tokens \
    testcase/TestCaseDeclLexer.tokens \
    testcase/TestCaseDecl.tokens \
    grammars/TestSystemDecl.g4 \
    grammars/TestCaseDecl.g4 \
    grammars/ImportReader.g4 \
    grammars/StateMachine.g4 \
    grammars/Irdl.g4 \
    statemachine/StateMachine.tokens \
    statemachine/StateMachineLexer.tokens \
    grammars/Irdl.g4 \
    irdl/Irdl.tokens \
    irdl/IrdlLexer.tokens \
    grammars/IrdlCommonDecl.g4 \
    irdldecl/IrdlCommonDecl.tokens \
    irdldecl/IrdlCommonDeclLexer.tokens \
    grammars/SimSystemDecl.g4 \
    simsystem/SimSystemDecl.tokens \
    simsystem/SimSystemDeclLexer.tokens

HEADERS += \
    spenat/SpenatBaseListener.h \
    spenat/SpenatLexer.h \
    spenat/SpenatListener.h \
    spenat/SpenatParser.h \
    dslparser_global.hpp \
    dslerror.hpp \
    spenat/combuildspenatmodel.hpp \
    spenat/comcreatespenatproposals.hpp \
    dslparser_types.hpp \
    spenat/spenatmodellistener.hpp \
    common/CommonLexer.h \
    common/comcreatecommontokens.hpp \
    common/commonmodellistener.hpp \
    common/commonfunctors.hpp \
    common/combuildbasemodel.hpp \
    common/CommonDeclBaseListener.h \
    common/CommonDeclLexer.h \
    common/CommonDeclListener.h \
    common/CommonDeclParser.h \
    sut/SutDeclBaseListener.h \
    sut/SutDeclLexer.h \
    sut/SutDeclListener.h \
    sut/SutDeclParser.h \
    sut/combuildsutmodel.hpp \
    sut/sutmodellistener.hpp \
    sut/comcreatesutproposals.hpp \
#    trafficsim/TrafficSimDeclBaseListener.h \
#    trafficsim/TrafficSimDeclLexer.h \
#    trafficsim/TrafficSimDeclListener.h \
#    trafficsim/TrafficSimDeclParser.h \
    testsystem/combuildtestsystemmodel.hpp \
    testsystem/comcreatetestsystemproposals.hpp \
    testsystem/TestSystemDeclBaseListener.h \
    testsystem/TestSystemDeclLexer.h \
    testsystem/TestSystemDeclListener.h \
    testsystem/TestSystemDeclParser.h \
    testsystem/testsystemmodellistener.hpp \
    testcase/TestCaseDeclLexer.h \
    testcase/TestCaseDeclBaseListener.h \
    testcase/TestCaseDeclListener.h \
    testcase/TestCaseDeclParser.h \
    testcase/combuildtestcasemodel.hpp \
    testcase/comcreatetestcaseproposals.hpp \
    testcase/testcasemodellistener.hpp \
    testsystem/testsystemmodellistener.hpp \
    importreader/ImportReaderBaseListener.h \
    importreader/ImportReaderLexer.h \
    importreader/ImportReaderListener.h \
    importreader/ImportReaderParser.h \
    importreader/importreadermodellistener.hpp \
    importreader/combuildimportreadermodel.hpp \
    common/commonmodellistener.ipp \
#    diagnosis/combuilddiagnosismodel.hpp \
#    diagnosis/comcreatediagnosisproposals.hpp \
#    diagnosis/diagnosismodellistener.hpp \
#    diagnosis/DiagnosisDeclBaseListener.h \
#    diagnosis/DiagnosisDeclLexer.h \
#    diagnosis/DiagnosisDeclListener.h \
#    diagnosis/DiagnosisDeclParser.h \
    statemachine/comcreatestatemachineproposals.hpp \
    statemachine/StateMachineBaseListener.h \
    statemachine/StateMachineLexer.h \
    statemachine/StateMachineListener.h \
    statemachine/statemachinemodellistener.hpp \
    statemachine/StateMachineParser.h \
    statemachine/combuildstatemachinemodel.hpp \
    dslproposal.hpp \
    irdl/combuildirdlmodel.hpp \
    irdl/comcreateirdlproposals.hpp \
    irdl/IrdlBaseListener.h \
    irdl/IrdlLexer.h \
    irdl/IrdlListener.h \
    irdl/IrdlParser.h \
    irdl/irdlmodellistener.hpp \
    statemachine/combuildstatemachinefile.hpp \ #\
    irdldecl/combuildirdldeclmodel.hpp \
    irdldecl/comcreateirdldeclproposals.hpp \
    irdldecl/IrdlCommonDeclBaseListener.h \
    irdldecl/IrdlCommonDeclLexer.h \
    irdldecl/IrdlCommonDeclListener.h \
    irdldecl/IrdlCommonDeclParser.h \
    irdldecl/irdldeclmodellistener.hpp \
    common/buildbasemodelfile.hpp \
    spenat/combuildspenatfile.hpp \
    statement/combuildstatementmodel.hpp \
    statement/statementmodellistener.hpp \
    simsystem/SimSystemDeclBaseListener.h \
    simsystem/SimSystemDeclListener.h \
    simsystem/SimSystemDeclParser.h \
    simsystem/SimSystemDeclLexer.h \
#    testcase/combuildtestcasefile.hpp

SOURCES += \
    spenat/SpenatLexer.cpp \
    spenat/SpenatParser.cpp \
    spenat/combuildspenatmodel.cpp \
    spenat/comcreatespenatproposals.cpp \
    spenat/spenatmodellistener.cpp \
    common/CommonLexer.cpp \
    common/comcreatecommontokens.cpp \
    dslparser_types.cpp \
    common/combuildbasemodel.cpp \
    common/CommonDeclLexer.cpp \
    common/CommonDeclParser.cpp \
    sut/SutDeclLexer.cpp \
    sut/SutDeclParser.cpp \
    sut/combuildsutmodel.cpp \
    sut/sutmodellistener.cpp \
    sut/comcreatesutproposals.cpp \
#    trafficsim/TrafficSimDeclBaseListener.cpp \
#    trafficsim/TrafficSimDeclLexer.cpp \
#    trafficsim/TrafficSimDeclListener.cpp \
#    trafficsim/TrafficSimDeclParser.cpp \
    testsystem/combuildtestsystemmodel.cpp \
    testsystem/comcreatetestsystemproposals.cpp \
    testsystem/TestSystemDeclLexer.cpp \
    testsystem/TestSystemDeclParser.cpp \
    testsystem/testsystemmodellistener.cpp \
    testcase/TestCaseDeclLexer.cpp \
    testcase/TestCaseDeclParser.cpp \
    testcase/combuildtestcasemodel.cpp \
    testcase/comcreatetestcaseproposals.cpp \
    testcase/testcasemodellistener.cpp \
    importreader/ImportReaderLexer.cpp \
    importreader/ImportReaderParser.cpp \
    importreader/combuildimportreadermodel.cpp \
    importreader/importreadermodellistener.cpp \
#    diagnosis/combuilddiagnosismodel.cpp \
#    diagnosis/comcreatediagnosisproposals.cpp \
#    diagnosis/diagnosismodellistener.cpp \
#    diagnosis/DiagnosisDeclBaseListener.cpp \
#    diagnosis/DiagnosisDeclLexer.cpp \
#    diagnosis/DiagnosisDeclListener.cpp \
#    diagnosis/DiagnosisDeclParser.cpp \
    statemachine/combuildstatemachinemodel.cpp \
    statemachine/comcreatestatemachineproposals.cpp \
    statemachine/StateMachineLexer.cpp \
    statemachine/statemachinemodellistener.cpp \
    statemachine/StateMachineParser.cpp \
    irdl/combuildirdlmodel.cpp \
    irdl/comcreateirdlproposals.cpp \
    irdl/IrdlLexer.cpp \
    irdl/IrdlParser.cpp \
    irdl/irdlmodellistener.cpp \
    statemachine/combuildstatemachinefile.cpp \ #\
    irdldecl/combuildirdldeclmodel.cpp \
    irdldecl/comcreateirdldeclproposals.cpp \
    irdldecl/IrdlCommonDeclLexer.cpp \
    irdldecl/IrdlCommonDeclParser.cpp \
    irdldecl/irdldeclmodellistener.cpp \
    common/buildbasemodelfile.cpp \
    spenat/combuildspenatfile.cpp \
    statement/combuildstatementmodel.cpp \
    statement/statementmodellistener.cpp \
    simsystem/SimSystemDeclParser.cpp \
    simsystem/SimSystemDeclLexer.cpp
#    testcase/combuildtestcasefile.cpp
