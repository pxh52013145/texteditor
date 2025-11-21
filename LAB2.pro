QT += core gui widgets printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LAB2
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    codeeditor.cpp \
    finddialog.cpp \
    replacedialog.cpp

HEADERS += \
    mainwindow.h \
    codeeditor.h \
    finddialog.h \
    replacedialog.h

FORMS += \
    mainwindow.ui \
    finddialog.ui \
    replacedialog.ui