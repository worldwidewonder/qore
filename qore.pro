## Copyright (c) 2016 Ruben Van Boxem
#
#  This code is dual licensed under the MIT and LGPLv3 licenses.
#  The full license texts can be found in MIT.txt and LGPLv3.txt.
#
#  This file is part of Qore.
#
## Qore main project file

TEMPLATE = subdirs

SUBDIRS += \
    api \
    app

app.depends = api

OTHER_FILES += \
    MIT.license.txt \
    GPLv3.license.txt \
    README.md
