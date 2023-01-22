CC=i686-w64-mingw32-gcc
CXX=i686-w64-mingw32-g++
RANLIB=i686-w64-mingw32-ranlib
DLLTOOL=i686-w64-mingw32-dlltool
LD=i686-w64-mingw32-ld
NM=i686-w64-mingw32-nm
./configure --host=i686-w64-mingw32 --with-mingw --with-wx-config=i686-w64-mingw32-msw-unicode-3.1  --prefix=/usr/i686-w64-mingw32/ CFLAGS="-std=c++14 -D_USE_MATH_DEFINES"
cp lib/Makefile.cross_32 lib/Makefile
