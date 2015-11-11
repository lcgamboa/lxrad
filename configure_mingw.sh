CC=x86_64-w64-mingw32-gcc
CXX=x86_64-w64-mingw32-g++
RANLIB=x86_64-w64-mingw32-ranlib
DLLTOOL=x86_64-w64-mingw32-dlltool
LD=x86_64-w64-mingw32-ld
NM=x86_64-w64-mingw32-nm
./configure --host=x86_64-w64-mingw32 --with-mingw --with-wx-config=x86_64-w64-mingw32-msw-unicode-3.0  --prefix=/usr/x86_64-w64-mingw32/
cp lib/Makefile.cross lib/Makefile
