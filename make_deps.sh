#!/bin/bash
cd ..
git clone --depth=1 https://github.com/sammycage/lunasvg.git
cd lunasvg
#git pull --no-rebase
git checkout 7f82e941270aad040922798c210ce0e2c1eb58aa
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
