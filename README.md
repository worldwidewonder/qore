# Qore

Qt Kodi remote.

# Building from source

## Desktop

Although Qore is developed to be run on portable devices, it can just as well function as a desktop application.
I do strongly suggest just using the Kodi main interface instead in this case.

The build steps are like those of any Qt application:

    qmake
    make

or nmake, gmake or whatever flavour of make your platform desires. Note that Qt's jom will choke on the generated makefiles.

## Mobile

### Windows Phone

You will need Qt 5 for Windows RT and Visual Studio 2015.
Use qmake to generate the project files:

    qmake -tp vc -r path/to/core

then open the generated "qore.sln" in VS2015.
Because the qmake generator for Visual Studio project files
