#!/bin/bash
cd ..
git clone --depth=1 https://github.com/sammycage/lunasvg.git
cd lunasvg
#git pull --no-rebase
export CXXFLAGS="-fPIC"
export CFLAGS="-fPIC"
rm -rf build
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON ..
make -j4
cd ..
cd ..
cd lxrad
ln -s ../lunasvg/ lunasvg
