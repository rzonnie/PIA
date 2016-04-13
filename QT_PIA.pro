#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T09:29:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_PIA
TEMPLATE = app

LIBS += \
    -lboost_program_options\
    -lboost_serialization

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/Announcement.cpp \
    src/DynamicQueue.cpp \
    src/PIA.cpp \
    src/PIAEngine.cpp \
    src/ReceivingSocket.cpp \
    src/RoutingTable.cpp \
    src/SendSocket.cpp \
    src/Settings.cpp \
    src/Socket.cpp \
    src/TerminalGUI.cpp \
    src/ThreadRunner.cpp \
    src/guicontroller.cpp \
    src/ChatHistory.cpp \
    src/QueueController.cpp \
    src/functions.cpp

HEADERS  += include/mainwindow.h \
    include/Announcement.h \
    include/BlockingQueue.h \
    include/DynamicQueue.h \
    include/functions.h \
    include/main.h \
    include/PIA.h \
    include/PIAEngine.h \
    include/ReceivingSocket.h \
    include/RoutingTable.h \
    include/RoutingTableStruct.h \
    include/SendSocket.h \
    include/Settings.h \
    include/Socket.h \
    include/TerminalGUI.h \
    include/ThreadRunner.h \
    include/guicontroller.h \
    include/chatmessage.h \
    include/ChatHistory.h \
    include/QueueController.h

FORMS    += \
    mainwindow.ui

