## Copyright (c) 2016 Ruben Van Boxem
#
# This code is dual licensed under the MIT and LGPLv3 licenses.
# The full license texts can be found in MIT.txt and LGPLv3.txt.
#
# This file is part of Qore.
#
## Qore remote application

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qore
TEMPLATE = app

include(../qore.pri)

INCLUDEPATH += \
    . \
    ..

LIBS += \
    -L../api -lqoreAPI

SOURCES += \
    main.c++ \
    library_view.c++ \
    remote_control.c++ \
    qore_widget.c++ \
    connection.c++

HEADERS  += \
    library_view.h++ \
    remote_control.h++ \
    qore_widget.h++ \
    connection.h++
