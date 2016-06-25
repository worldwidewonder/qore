## Copyright (c) 2016 Ruben Van Boxem
#
# This code is dual licensed under the MIT and LGPLv3 licenses.
# The full license texts can be found in MIT.txt and LGPLv3.txt.
#
# This file is part of Qore.
#
## Qore common project settings

# Compiler flags
MY_CXXFLAGS = -std=c++14 -pedantic -Wextra \
              -Winit-self -Wmissing-include-dirs \
              -Wstrict-aliasing
*g++*:QMAKE_CXXFLAGS += $${MY_CXXFLAGS}
*clang*:QMAKE_CXXFLAGS += $${MY_CXXFLAGS} -stdlib=libc++
*clang*:QMAKE_LFLAGS += -stdlib=libc++
*clang*:LIBS += -lc++abi
*icc*:QMAKE_CXXFLAGS += $${MY_CXXFLAGS}

# Enable c++/h++ extensions
QMAKE_EXT_CPP += .c++
QMAKE_EXT_H += .h++

INCLUDEPATH += .
