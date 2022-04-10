# Process this file with autoconf to produce a configure script.
AC_INIT([lxrad],[0.5],[lcgamboa@yahoo.com])
AC_PREREQ([2.71])
AC_CONFIG_SRCDIR([lib/capplication.cc])
AC_CONFIG_HEADERS([config.h])


EXTERNAL_CFLAGS="$CFLAGS"

# Checks for programs.
AC_PROG_CPP
AC_PROG_CC
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11


# Checks for libraries.
AC_CHECK_LIB([openal], [alGenSources],
cat >>confdefs.h <<_ACEOF
#define HAVE_OPENAL 1
_ACEOF
LIBS="-lopenal $LIBS",
AC_MSG_WARN([libopenal Not Found!]))

#check for wxwidget
WXCONFIG=wx-config
AC_ARG_WITH(wx-config,
[[  --with-wx-config=FILE     Use the given path to wx-config when determining
                            wxWidgets configuration; defaults to "wx-config"]],
[
    if test "$withval" != "yes" -a "$withval" != ""; then
        WXCONFIG=$withval
    fi
])
AC_MSG_CHECKING([wxWidgets version])
if wxversion=`$WXCONFIG --version`; then
    AC_MSG_RESULT([$wxversion])
else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([wxWidgets is required. Try --with-wx-config.])
fi

WX_CXXFLAGS="`$WXCONFIG --cxxflags`"
WX_LIBS="`$WXCONFIG --libs std`"
WX_LIBS_ADV="`$WXCONFIG --libs stc`"


AC_SUBST(WX_LIBS)
AC_SUBST(WX_LIBS_ADV)
 

CFLAGS="$WX_CXXFLAGS $EXTERNAL_CFLAGS -D_LX_WX"
LIBS="$LIBS $WX_LIBS"
LIBSADV="$WX_LIBS_ADV"


# Checks for header files.

AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STAT
AC_CHECK_FUNCS([getcwd mkdir strerror strrchr strstr strtol])

AC_SUBST(PACKAGE,`sed -ne 's/PACKAGE=//p' VERSION`)
AC_SUBST(VERSION,`sed -ne 's/VERSION=//p' VERSION`)
AC_SUBST(MAINVER,`sed -ne 's/MAINVER=//p' VERSION`)
AC_SUBST(MINORVER,`sed -ne 's/MINORVER=//p' VERSION`)
AC_SUBST(HOSTOS,`uname -sr || echo unknown`)
AC_SUBST(HOSTCPU,`uname -m || echo unknown`)

AC_SUBST(LIBS)
AC_SUBST(LIBSADV)

AC_SUBST(PREFIX)
AC_SUBST(BINDIR)
AC_SUBST(LIBDIR)


AC_CONFIG_FILES([Makefile
           Makefile.Conf
	   docs/Makefile
           include/Makefile
           layout/Makefile
           lib/Makefile
           share/Makefile
           utils/Makefile
	   utils/lxrad-config])
AC_OUTPUT

