#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T11:26:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DSP_openCV_Demo1
TEMPLATE = app

#linux openCV package
#QT_CONFIG -= no-pkg-config
#CONFIG += link_pkgconfig
#PKGCONFIG += opencv


SOURCES += main.cpp\
        mainwindow.cpp \
    MatToQImage.cpp

HEADERS  += mainwindow.h \
    MatToQImage.h

FORMS    += mainwindow.ui

#WIN32 opencv link
# OpenCv Configuration opencv-2.4.6
#INCLUDEPATH += "C:\opencv-2.4.6\install\install\include"
#INCLUDEPATH += "C:\opencv-2.4.6\install\install\include\opencv"

#LIBS += -LC:\opencv-2.4.6\install\install\bin\
#-lopencv_core246 \
#-lopencv_highgui246 \
#-lopencv_imgproc246 \
#-lopencv_features2d246 \
#-lopencv_calib3d246

#Linux opencv link
# OpenCv Configuration opencv-3.3.0
#INCLUDEPATH += "~/opencv-3.3.0/opencv/include"
#INCLUDEPATH += "~/opencv-3.3.0/opencv/include/opencv"

#LIBS += -L~/opencv-3.3.0/build/bin \
#-lopencv_core \
#-lopencv_highgui \
#-lopencv_imgproc \
#-lopencv_features2d \
#-lopencv_calib3d \
#-lopencv_videoio

# OpenCv Configuration ROS opencv-3.2.0
INCLUDEPATH += "/opt/ros/kinetic/include/opencv-3.2.0-dev"
INCLUDEPATH += "/opt/ros/kinetic/include/opencv-3.2.0-dev"

LIBS += -L~/opt/ros/kinetic/lib \
-lopencv_core \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_videoio
