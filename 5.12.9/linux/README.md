built with:

```
cd ~/hvsrc/qt5
git checkout 5.12.9
perl init-repository --module-subset=default,-qtwebengine -f
rm -rf ~/hvsrc/qt_lgpl/build
mkdir ~/hvsrc/qt_lgpl/build
cd ~/hvsrc/qt_lgpl/build
~/hvsrc/qt5/configure -opensource -nomake examples -nomake tests -confirm-license -xplatform linux-g++ -prefix ~/hvsrc/qt_lgpl/5.12.9/linux
make -j$(nproc)
make install
```
