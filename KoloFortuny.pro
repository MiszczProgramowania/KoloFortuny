#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T08:54:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KoloFortuny
TEMPLATE = app


SOURCES += main.cpp\
        oknoglowne.cpp \
    plik.cpp \
    bazahasel.cpp \
    konfiguracja.cpp \
    formularzhasel.cpp \
    gracz.cpp \
    kololosu.cpp

HEADERS  += oknoglowne.h \
    plik.h \
    bazahasel.h \
    konfiguracja.h \
    formularzhasel.h \
    gracz.h \
    kololosu.h

FORMS    += oknoglowne.ui \
    formularzhasel.ui

DISTFILES += \
    readme.txt \
    konfiguracja.dat \
    img/kolo.png

RESOURCES += \
    grafika.qrc
