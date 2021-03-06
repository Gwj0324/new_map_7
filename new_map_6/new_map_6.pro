#-------------------------------------------------
#
# Project created by QtCreator 2020-03-01T09:45:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new_map_6
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
win32{

    CONFIG(debug, debug|release) {

    INCLUDEPATH += C:/qtvld/include

    DEPENDPATH += C:/qtvld/include

    LIBS += -LC:/qtvld/lib/Win32 -lvld

}

}

SOURCES += \
    astar.cpp \
        main.cpp \
    point.cpp \
        widget.cpp \
    m_road.cpp \
    advertisement.cpp \
    set.cpp

HEADERS += \
    astar.h \
    point.h \
        widget.h \
    m_road.h \
    advertisement.h \
    set.h

FORMS += \
        widget.ui \
    advertisement.ui \
    set.ui

RESOURCES += \
    resource.qrc
RC_ICONS = panda.ico
CONFIG += resources_big
