QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
CONFIG -=debug_and_release

CONFIG(release,debug|release)   { TARGET = Library_Collector }
CONFIG(debug,debug|release)     { TARGET = Library_Collector_D }

LIBRARIES_PATH = D:/Coding/Libs/Libraries_V4_2
LIBRARIES_INCLUDE = $${LIBRARIES_PATH}/includes

win32-g++ {
    32Bit {
        LIBRARIES_PATH = $${LIBRARIES_PATH}/MinGW_32_bit
    }else {
        LIBRARIES_PATH = $${LIBRARIES_PATH}/MinGW_64_bit
    }
}
else:win32:!win32-g++: {
    !contains(QMAKE_TARGET.arch,x86_64) {
        LIBRARIES_PATH = $${LIBRARIES_PATH}/MSVC2017_32_bit
    }else {
        LIBRARIES_PATH = $${LIBRARIES_PATH}/MSVC2017_64_bit
    }
}

INCLUDEPATH += $${LIBRARIES_INCLUDE}/Base
DEPENDPATH += $${LIBRARIES_INCLUDE}/Base

win32:CONFIG(release, debug|release): LIBS += -L$${LIBRARIES_PATH} -lBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$${LIBRARIES_PATH} -lBase_D

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $${LIBRARIES_PATH}/libBase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $${LIBRARIES_PATH}/libBase_D.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $${LIBRARIES_PATH}/Base.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $${LIBRARIES_PATH}/Base_D.lib

INCLUDEPATH += $${LIBRARIES_INCLUDE}/Message
DEPENDPATH += $${LIBRARIES_INCLUDE}/Message

win32:CONFIG(release, debug|release): LIBS += -L$${LIBRARIES_PATH} -lMessage
else:win32:CONFIG(debug, debug|release): LIBS += -L$${LIBRARIES_PATH} -lMessage_D

SOURCES += main.cpp \
    Adapter/NoticeAdapter.cpp \
    Data/BuildData.cpp \
    Data/Collector.cpp \
    MessageHandler.cpp \
    WindowMain.cpp \
    WindowMainWidgets/BuildDataWidget.cpp \
    WindowMainWidgets/MainInfoWidget.cpp

HEADERS += \
    Adapter/NoticeAdapter.h \
    Data/BuildData.h \
    Data/Collector.h \
    MessageHandler.h \
    WindowMain.h \
    WindowMainWidgets/BuildDataWidget.h \
    WindowMainWidgets/MainInfoWidget.h

FORMS += \
    WindowMain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
