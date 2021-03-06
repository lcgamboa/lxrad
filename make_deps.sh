#!/bin/bash
cd ..
git clone https://github.com/sammycage/lunasvg.git
cd lunasvg
git pull
export CXXFLAGS=-fPIC
export CFLAGS=-fPIC
rm -rf build
mkdir build
cd build
cmake ..
make -j4
