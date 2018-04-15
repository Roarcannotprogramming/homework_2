#-------------------------------------------------
#
# Project created by QtCreator 2018-04-06T10:59:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql
#LIBS += -L./ -lCOREdll
#LIBS += -L./ -lCore15

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arithmetic_generation_tool_ui
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
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp

HEADERS += \
        mainwindow.h \
    dialog1.h \
    dialog2.h \
    dialog3.h \
    core.h \
    core.h \
    core.h \
    core.h \
    Core15.h

FORMS += \
        mainwindow.ui \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui

DISTFILES += \
    other/main.ico \
    other/main.ico \
    other/main.rc

RESOURCES += \
    other/main.qrc \
    other/qss.qrc \
    png/png.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lCore15
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lCore15d
else:unix: LIBS += -L$$PWD/./ -lCore15

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lCOREdll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lCOREdlld
else:unix: LIBS += -L$$PWD/./ -lCOREdll

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
