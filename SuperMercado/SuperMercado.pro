#-------------------------------------------------
#
# Project created by QtCreator 2012-04-15T09:34:36
#
#-------------------------------------------------

QT       += core gui sql

TARGET = SuperMercado
TEMPLATE = app


SOURCES += main.cpp\
        supermercado.cpp \
    banco.cpp \
    cad_produto.cpp \
    produto.cpp

HEADERS  += supermercado.h \
    banco.h \
    cad_produto.h \
    produto.h

FORMS    += supermercado.ui \
    banco.ui \
    cad_produto.ui \
    produto.ui
