#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T18:03:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectShip
TEMPLATE = app


SOURCES += \
    backpack.cpp \
    item.cpp \
    main.cpp \
    room.cpp \
    ship.cpp \
    map.cpp

HEADERS  += \
    backpack.h \
    item.h \
    room.h \
    ship.h \
    map.h

FORMS += \
    backpack.ui \
    ship.ui \
    map.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
