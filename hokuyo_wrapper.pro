#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T16:17:23
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
   hokuyo_wrapper.cpp \
   directiongenerator.cpp \
   localgridgenerator.cpp

INCLUDEPATH += /home/highlight/Programs/HokuyoDriver/include/urg_cpp

LIBS += /home/highlight/Programs/HokuyoDriver/lib/liburg_cpp.a

# This problem causes me too much confusion
LIBS += -lrt

HEADERS += \
   Connection_information.h \
   hokuyo_wrapper.h \
   directiongenerator.h \
   localgridgenerator.h \
   structures.h

DISTFILES +=

INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_highgui.so \
       /usr/local/lib/libopencv_core.so    \
       /usr/local/lib/libopencv_imgproc.so
