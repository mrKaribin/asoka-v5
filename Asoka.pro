#-------------------------------------------------
#
# Project created by QtCreator 2023-07-20T13:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asoka
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Asoka.cpp \
    Core/Core.cpp \
    Core/Identifier.cpp \
    Core/Object.cpp \
    GUI/Application.cpp \
    GUI/AsokaConsole.cpp \
    Debug/ClassTest.cpp \
    Debug/Logs.cpp \
    Debug/Tester.cpp \
    Core/Thread.cpp

HEADERS  += mainwindow.h \
    Asoka/Types/string.h \
    Asoka.h \
    Core/Core.h \
    Core/Identifier.h \
    Core/Object.h \
    Core/Property.h \
    Core/Tests/PropertyTest.h \
    GUI/Application.h \
    GUI/AsokaConsole.h \
    Debug/ClassTest.h \
    Debug/Logs.h \
    Debug/Tester.h \
    Debug/Logs/FileLog.h \
    Debug/Logs/Log.h \
    Core/Thread.h \
    Core/Action.h \
    Core/EObject.h \
    Asoka/Types/json.h \
    Logic/LShape.h \
    Logic/LAction.h
