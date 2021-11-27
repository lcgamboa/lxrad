#!/bin/bash
cd ..
git clone --depth=1 https://github.com/sammycage/lunasvg.git
cd lunasvg
git pull --no-rebase
export CXXFLAGS="-fPIC -flto"
export CFLAGS="-fPIC -flto"
rm -rf build
mkdir build
cd build
cmake ..
make -j4
cd ..
cd ..
cd lxrad
ln -s ../lunasvg/ lunasvg
