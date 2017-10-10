TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
SOURCES += \
    piece.cpp \
    echiquier.cpp \
    main.cpp \
    joueur.cpp \
    joueurBlanc.cpp \
    joueurNoir.cpp \
    roi.cpp \
    reine.cpp \
    tour.cpp \
    fou.cpp \
    pion.cpp \
    cavalier.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    piece.h \
    echiquier.h \
    joueur.h \
    joueurBlanc.h \
    joueurNoir.h \
    roi.h \
    reine.h \
    tour.h \
    fou.h \
    pion.h \
    cavalier.h

