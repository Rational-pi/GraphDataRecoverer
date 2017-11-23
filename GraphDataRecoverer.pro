#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T21:38:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphDataRecoverer
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp
HEADERS +=
FORMS +=

include(GDRmainWindow\GDRmainwindow.pri)
include(GDRscenes\GDRscenes.pri)
