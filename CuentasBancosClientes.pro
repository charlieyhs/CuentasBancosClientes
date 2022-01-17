QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    altaclienteform.cpp \
    altacuentaform.cpp \
    ducliente.cpp \
    ducuenta.cpp \
    dulineedit.cpp \
    main.cpp \
    mainwindow.cpp \
    verclientesform.cpp \
    vercuentasform.cpp

HEADERS += \
    DuDefines.h \
    altaclienteform.h \
    altacuentaform.h \
    ducliente.h \
    ducuenta.h \
    dulineedit.h \
    mainwindow.h \
    verclientesform.h \
    vercuentasform.h

FORMS += \
    altaclienteform.ui \
    altacuentaform.ui \
    mainwindow.ui \
    verclientesform.ui \
    vercuentasform.ui

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
