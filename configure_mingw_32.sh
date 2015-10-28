CC=i686-w64-mingw32-gcc
CXX=i686-w64-mingw32-g++
RANLIB=i686-w64-mingw32-ranlib
DLLTOOL=i686-w64-mingw32-dlltool
LD=i686-w64-mingw32-ld
NM=i686-w64-mingw32-nm
CFLAGS= -D_WIN_
./configure --host=i686-w64-mingw32 --with-mingw --with-wx-config=i686-w64-mingw32-msw-unicode-3.0  --prefix=/usr/i686-w64-mingw32/
cp lib/Makefile.cross_32 lib/Makefile
