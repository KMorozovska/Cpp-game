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
    gamewindow.cpp \
    questionanswer.cpp \
    importdata.cpp \
    importprogess.cpp \
    startwindow.cpp

HEADERS += \
    gamewindow.h \
    questionanswer.h \
    importdata.h \
    importprogess.h \
    startwindow.h \
    qstringserializer.h

RESOURCES += \
    data.qrc

INCLUDEPATH += /usr/include/boost

LIBS += -L/usr/include/boost -lboost_serialization
