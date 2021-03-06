QT -= gui

CONFIG += c++17
CONFIG += console
CONFIG += silent
CONFIG -= debug_and_release
CONFIG -= app_bundle

TEMPLATE = app
TARGET = demo

include($$PWD/../qnotation.pri)


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    example_controller.h \
    example_defines.h \
    example_invoker.h \
    example_object.h
