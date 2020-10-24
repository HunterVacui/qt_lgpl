# qt_lgpl
This repository contains headers and DLLs compiled from [unmodified QT source](https://github.com/qt), only for Framework libraries available under the LGPL v3 license

See [QT Features](https://www.qt.io/product/features#js-6-3) for the official list of QT modules and tools available under the LGPL license

These files are also available from [QT directly](https://download.qt.io/archive/qt/). **WARNING:** Even though the files available on the linked website are titled "open source" If you use these installers provided by QT, you run the risk of including additional modules that are not available under the LGPL license. If you install from that source, make sure to unselect any framework binaries not included in the [list of LGPL features](https://www.qt.io/product/features#js-6-3)

(Note: The QT Design tools are listed as GPL, not LGPL. However "The Qt Company GPL Exception 1.0" allows for using the output of these design tools in closed source programs, provided that said program is not itself a QT GUI Design application -- in any form)

# Local Build Initial Setup

Pick a target platform and release version before starting.

For this example we'll use:
* Release **5.15.1**. (See [releases](https://github.com/qt/qt5/releases))
* Platform **linux-g++** (See [mkspecs](https://github.com/qt/qtbase/tree/dev/mkspecs))

## Retrieve Source

As per the [QT Open Source](https://www.qt.io/download-open-source) document, [This page](https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code) contains the instructions for retrieving the QT source. [This Page](https://wiki.qt.io/Get_the_Source) contains supplementary instructions. Reproduced in part below:

```
$ cd ~/hvsrc
$ git clone https://code.qt.io/qt/qt5.git
```

## Setup submodules

qtwebengine is excluded by default because it's large, takes a long time to compile, and often fails to build.

```
$ cd ~/hvsrc/qt5
$ git checkout 5.15.1
$ perl init-repository --module-subset=default,-qtwebengine
```

## Environment Setup

* make sure no qmake-specific environment varaibles (like `QMAKEPATH` or `QMAKEFEATURES`) are set.
* `$HOME/.config/Qt/Qmake.conf` should be empty.
* On windows, make sure `sh.exe` is not in your path

Follow the build-environment-specific setup instructions [specified here](https://wiki.qt.io/Get_the_Source#Building_Qt)


# Build DLLs

## Linux

```
mkdir -p ~/hvsrc/qt_lgpl/build && cd ~/hvsrc/qt_lgpl/build
~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform linux-g++ -prefix ~/hvsrc/qt_lgpl/5.15.1/linux
make -j$(nproc) && make install
```

## Windows

(note: these commands are not vetted yet. may require more local build setup. See https://askubuntu.com/questions/656219/building-a-windows-executable-in-qt-on-a-linux-system)
```
mkdir -p ~/hvsrc/qt_lgpl/build && cd ~/hvsrc/qt_lgpl/build
~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform win32-g++ -prefix ~/hvsrc/qt_lgpl/5.15.1/win32
make -j$(nproc) && make install
```

## Android

[Android](https://doc.qt.io/qt-5/android-building.html) ([wiki](https://wiki.qt.io/Android) & [getting started](https://doc.qt.io/qt-5/android-getting-started.html)):
```
$ apt install build-essential default-jre openjdk-8-jdk-headless android-sdk android-sdk-platform-23 libc6-i386
$ ~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform android-clang --disable-rpath -android-ndk <path/to/sdk>/ndk-bundle/ -android-sdk <path/to/sdk> -no-warnings-are-errors -prefix /5.15.1/android/sdk_23
```

## Raspberry Pi

[doc](https://wiki.qt.io/RaspberryPi)

# Build QT local Dev Build

##  Create your build output directory

```
$ mkdir -p ~/hvsrc/qt_lgpl/5.15.1/linux-g++
$ cd ~/hvsrc/qt_lgpl/5.15.1/linux-g++
$ ~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform linux-g++
```

`-opensource` is required to ensure conformance to the LGPL license.
`-developer-build` exports more symbols, to expose more classes/functions to testing.
See more configure options [here](https://doc.qt.io/qt-5/configure-options.html)

## Build

### Linux

`make -j$(nproc)` to make everything (nproc outputs the number of processing units available on the machine)
or build a specific module, eg. `make module-qtdeclarative`

### Windows
`nmake` or `jom` or `mingw32-make`
Building webkit on windows requires [more steps](http://trac.webkit.org/wiki/BuildingQtOnWindows)

## Install

Note: Installation is only needed if you haven't used the configure options -developer-build or -prefix "%PWD%/qtbase". Otherwise, you can just use Qt from the build directory.

```
$ make install
```

## Clean

```
$ git submodule foreach --recursive "git clean -dfx" && git clean -dfx
```

## Getting Updates

```
$ git pull
$ perl init-repository -f --module-subset=default,-qtwebengine
```

don't forget to remake your build directories, or at least run `$ config.status -recheck-all` in them
