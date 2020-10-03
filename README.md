# qt_lgpl
This repository contains headers and DLLs compiled from unmodified QT source, only for Framework libraries available under the LGPL v3 license

See [QT Features](https://www.qt.io/product/features#js-6-3) for the official list of QT modules and tools available under the LGPL license

# Local Build Initial Setup

## Retrieve Source

As per the [QT Open Source](https://www.qt.io/download-open-source) document, [This page](https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code) contains the instructions for retrieving the QT source. [This Page](https://wiki.qt.io/Get_the_Source) contains supplementary instructions. Reproduced in part below:

```
$ git clone https://code.qt.io/qt/qt5.git
```

## Setup submodules

qtwebengine is excluded by default because it's large, takes a long time to compile, and often fails to build.

```
$ cd qt5
$ git checkout 5.15.1
$ perl init-repository --module-subset=default,-qtwebengine
```

## Build DLLs

### Environment Setup
* make sure no qmake-specific environment varaibles (like `QMAKEPATH` or `QMAKEFEATURES`) are set.
* `$HOME/.config/Qt/Qmake.conf` should be empty.
* On windows, make sure `sh.exe` is not in your path

Set your LLVM_INSTALL_DIR to the location where you have llvm installed
```
$ export LLVM_INSTALL_DIR=/usr/llvm
```

###  Create your build output directory

```
$ mkdir qt5-build
$ cd qt5-build
$ ../qt5/configure -developer-build -opensource -nomake examples -nomake tests -confirm-license
```

`-opensource` is required to ensure conformance to the LGPL license.
`-developer-build` exports more symbols, to expose more classes/functions to testing.

### Build

#### Linux

`make -j$(nproc)` to make everything
or build a specific module, eg. `make module-qtdeclarative`

#### Windows
`nmake` or `jom` or `mingw32-make`
Building webkit on windows requires [more steps](http://trac.webkit.org/wiki/BuildingQtOnWindows)

### Install

Note: Installation is only needed if you haven't used the configure options -developer-build or -prefix "%PWD%/qtbase". Otherwise, you can just use Qt from the build directory.

```
$ make install
```

### Clean

```
$ git submodule foreach --recursive "git clean -dfx" && git clean -dfx
```

### Getting Updates

```
$ git pull
$ perl init-repository -f --module-subset=default,-qtwebengine
```

don't forget to remake your build directories, or at least run `$ config.status -recheck-all` in them
