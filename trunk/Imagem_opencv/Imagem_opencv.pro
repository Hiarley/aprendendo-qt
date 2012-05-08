#-------------------------------------------------
#
# Project created by QtCreator 2012-04-27T14:44:53
#
#-------------------------------------------------

QT       += core gui

TARGET = Imagem_opencv
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    informacao.cpp \
    pixels.cpp \
    texto.cpp

HEADERS  += principal.h \
    informacao.h \
    pixels.h \
    texto.h

FORMS    += principal.ui \
    informacao.ui \
    pixels.ui \
    texto.ui

INCLUDEPATH += C:\OpenCV2.2\include\
INCLUDEPATH += C:\OpenCV2.2\include\opencv2\
INCLUDEPATH += C:\OpenCV2.2\include\opencv\

LIBS += -LC:\OpenCV2.2\lib \
    -lopencv_core220 \
    -lopencv_highgui220 \
    -lopencv_imgproc220 \
    -lopencv_features2d220 \
    -lopencv_calib3d220
