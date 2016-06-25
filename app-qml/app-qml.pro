TEMPLATE = app

QT += qml quick websockets

include(../qore.pri)

SOURCES += main.c++

*win*:CONFIG += windeployqt

RESOURCES += qml.qrc

OTHER_FILES += \
    main.qml \
    connection.qml \
    remote.qml

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../api/release/ -lqoreAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../api/debug/ -lqoreAPI
else:unix: LIBS += -L$$OUT_PWD/../api/ -lqoreAPI

INCLUDEPATH += $$PWD/../api
DEPENDPATH += $$PWD/../api

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
