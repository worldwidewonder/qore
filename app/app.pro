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

!*win*:LIBS += -L../api -lqoreAPI
*win*:LIBS += -L../api/debug -lqoreAPI

SOURCES += \
    connection.c++ \
    library_view.c++ \
    main.c++ \
    qore_widget.c++ \
    remote_control.c++

HEADERS  += \
    connection.h++ \
    library_view.h++ \
    qore_widget.h++ \
    remote_control.h++
