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
    player.cpp \
    startmenu.cpp \
    gamecomplete.cpp \
    playerinventory.cpp

HEADERS  += \
    item.h \
    room.h \
    ship.h \
    player.h \
    startmenu.h \
    gamecomplete.h \
    playerinventory.h

FORMS += \
    ship.ui \
    startmenu.ui \
    gamecomplete.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
