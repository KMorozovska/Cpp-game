#QT += core
#QT -= gui

CONFIG += c++11

TARGET = ZPR_projekt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    window.cpp \
    gamewindow.cpp \
    questionanswer.cpp \
    importdata.cpp

HEADERS += \
    window.h \
    gamewindow.h \
    questionanswer.h \
    importdata.h

RESOURCES += \
    data.qrc
