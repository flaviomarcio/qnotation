QTREFORCE_QANNOTATION=true
DEFINES+=QTREFORCE_QANNOTATION

INCLUDEPATH += $$PWD/includes

HEADERS += \
    $$PWD/includes/QAnnotation

include($$PWD/src/qannotation.pri)
