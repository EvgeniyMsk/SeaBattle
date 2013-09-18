#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T21:31:46
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

DEFINES += QT5

TARGET = SeaBattle
TEMPLATE = app



SOURCES += client/src/main.cpp\
    client/src/gameLogics/enemyCell.cpp \
    client/src/gameLogics/playerCell.cpp \
    client/src/gameLogics/playerField.cpp \
    client/src/gameLogics/humanPlayer.cpp \
    client/src/gameLogics/aiPlayer.cpp \
    client/src/gameLogics/gameMaster.cpp \
    client/src/view/field.cpp \
    client/src/view/cell.cpp \
    client/src/gameLogics/fleetInstaller.cpp \
    client/src/view/tabOfInformation.cpp \
    client/src/view/view.cpp \
    client/src/gameLogics/gameCell.cpp \
    client/src/gameLogics/gameField.cpp \
    client/src/view/fieldView.cpp \
    client/src/view/infoTabView.cpp \
    client/src/gameLogics/ship.cpp \
    client/src/gameLogics/aiPlayerSimple.cpp \
    client/src/gameLogics/textureAnalyzer.cpp \
    client/src/gameLogics/player.cpp \
    client/src/view/BattleWidget.cpp

HEADERS  += \
    client/src/gameLogics/enemyCell.h \
    client/src/gameLogics/types.h \
    client/src/gameLogics/playerCell.h \
    client/src/gameLogics/ship.h \
    client/src/gameLogics/playerField.h \
    client/src/gameLogics/player.h \
    client/src/gameLogics/humanPlayer.h \
    client/src/gameLogics/aiPlayer.h \
    client/src/gameLogics/gameMaster.h \
    client/src/gameLogics/fleetFactory.h \
    client/src/gameLogics/cellShip.h \
    client/src/view/field.h \
    client/src/view/cell.h \
    client/src/gameLogics/fleetInstaller.h \
    client/src/view/tabOfInformation.h \
    client/src/view/view.h \
    client/src/gameLogics/gameCell.h \
    client/src/gameLogics/gameField.h \
    client/src/view/fieldView.h \
    client/src/view/infoTabView.h \
    client/src/gameLogics/aiPlayerSimple.h \
    client/src/gameLogics/textureAnalyzer.h \
    client/src/view/BattleWidget.h

FORMS    += client/gui/tabOfInformation.ui \
    client/gui/field.ui \
    client/src/view/BattleWidget.ui

RESOURCES += client/gui/pictures/pictures.qrc

INCLUDEPATH += client/src/view client/src/gameLogics client/src
