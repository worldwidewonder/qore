## Copyright (c) 2016 Ruben Van Boxem
#
# This code is dual licensed under the MIT and LGPLv3 licenses.
# The full license texts can be found in MIT.txt and LGPLv3.txt.
#
# This file is part of Qore.
#
## Qore's Kodi JSON API wrapper

TARGET = qoreAPI
TEMPLATE = lib
QT += core gui websockets
CONFIG += staticlib

include(../qore.pri)

!staticlib:DEFINES += QORE_API_EXPORT QORE_API_DLL

HEADERS += \
    client.h++ \
    audio/song.h++ \
    audio/artist.h++ \
    audio/album.h++ \
    export.h++

SOURCES += \
    client.c++
