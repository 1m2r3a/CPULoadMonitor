#-------------------------------------------------
#
# Project created by QtCreator 2018-01-03T23:18:57
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Monitor
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    glwidget.cpp \
    Helper.cpp \
    cpu.cpp \
    thread.cpp

HEADERS += \
        mainwindow.h \
    glwidget.h \
    CounterInfo.h \
    Helper.h \
    Query.h \
    cpu.h \
    thread.h

FORMS += \
        mainwindow.ui
LIBS += -LD:\Qt\5.9.3\mingw53_32\lib\libQt5OpenGL.a -lopengl32 \
          -lPdh -lPsapi
