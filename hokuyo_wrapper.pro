#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T16:17:23
# This wrapper is actully cross-platform, as a convenient demo, 
# Qt is chosen to show how this wrapper is used.
# Note: urg_lib is needed as a fundamental driver for urg device.
# The link is:
# http://sourceforge.net/projects/urgnetwork/files/urg_library/
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = laserOA
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Connection_information.cpp \
    hokuyo_wrapper.cpp

INCLUDEPATH += /home/highlight/Programs/HokuyoDriver/include/urg_cpp
LIBS += /home/highlight/Programs/HokuyoDriver/lib/liburg_cpp.a

LIBS += -lrt

HEADERS += \
    Connection_information.h \
    hokuyo_wrapper.h

DISTFILES += \
    README.txt

# OpenCV Library
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
