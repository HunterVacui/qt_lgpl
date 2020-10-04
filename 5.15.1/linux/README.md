Compiled with:

```
mkdir -p ~/hvsrc/qt_lgpl/build
cd ~/hvsrc/qt_lgpl/build
~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform linux-g++ -prefix /5.15.1/linux
make -j$(nproc)
make install
```
