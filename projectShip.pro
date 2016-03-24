#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T18:03:16
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectShip
TEMPLATE = app


SOURCES += \
    item.cpp \
    main.cpp \
    room.cpp \
    ship.cpp \
    map.cpp \
    player.cpp \
    startmenu.cpp \
    gamecomplete.cpp

HEADERS  += \
    item.h \
    room.h \
    ship.h \
    map.h \
    player.h \
    startmenu.h \
    gamecomplete.h

FORMS += \
    ship.ui \
    map.ui \
    startmenu.ui \
    gamecomplete.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
