dnl ***
dnl *** Process this file with autoconf to produce a configure script.
dnl ***

dnl Initialize
dnl ==========
AC_PREREQ([2.59])
AC_INIT([mlplayer], [3.2.4])
AC_COPYRIGHT([(C) 2013 MLPlayer Team])

AC_SUBST([PACKAGE], [AC_PACKAGE_TARNAME])
AC_SUBST([VERSION], [AC_PACKAGE_VERSION])
AC_DEFINE_UNQUOTED([PACKAGE], "$PACKAGE", [Name of package])
AC_DEFINE_UNQUOTED([VERSION], "$VERSION", [Version number of package])

AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AC_CONFIG_HEADERS([config.h])

AUD_COMMON_PROGS

BUILDSYS_INIT
BUILDSYS_SHARED_LIB

dnl This is legacy branch; disable deprecation warnings
dnl ===================================================
CFLAGS="$CFLAGS -Wno-deprecated-declarations"

dnl Byte order
dnl ==========
AC_C_BIGENDIAN([BIGENDIAN=1], [BIGENDIAN=0],
 [AC_MSG_ERROR([Unknown machine byte order])],
 [AC_MSG_ERROR([Universal builds are not supported, sorry])])
AC_SUBST([BIGENDIAN])

dnl Platform
dnl ========
AC_MSG_CHECKING([for Microsoft Windows])
case "$target" in
    *mingw*)
        AC_MSG_RESULT([yes])
        HAVE_MSWINDOWS="yes"
        ;;
    *)
        AC_MSG_RESULT([no])
        HAVE_MSWINDOWS="no"
        ;;
esac
AC_SUBST([HAVE_MSWINDOWS])

dnl Prevent symbol collisions
dnl =========================
if test "x$HAVE_MSWINDOWS" = "xyes" ; then
    EXPORT="__declspec(dllexport)"
elif test "x$GCC" = "xyes" ; then
    CFLAGS="$CFLAGS -fvisibility=hidden"
    CXXFLAGS="$CXXFLAGS -fvisibility=hidden"
    EXPORT="__attribute__((visibility(\"default\")))"
else
    AC_MSG_ERROR([Unknown syntax for EXPORT keyword])
fi
AC_DEFINE_UNQUOTED([EXPORT], [$EXPORT], [Define to compiler syntax for public symbols])

dnl Headers and functions
dnl ===============================
AC_CHECK_HEADERS([execinfo.h regex.h rxposix.h rx/rxposix.h])
AC_CHECK_FUNCS([sigwait backtrace])

AC_MSG_CHECKING([for cexpf])
OLD_LIBS="$LIBS"
LIBS="$LIBS -lm"
AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <complex.h>
                                 #include <stdio.h>],
                                [printf ("%f", crealf (cexpf (1)))])],
               [AC_MSG_RESULT(yes)
                AC_DEFINE([HAVE_CEXPF], [1], [Define if cexpf is present])],
               [AC_MSG_RESULT(no)])
LIBS="$OLD_LIBS"

AC_MSG_CHECKING([for /proc/self/exe])
if test -e "/proc/self/exe" ; then
    AC_MSG_RESULT(yes)
    AC_DEFINE([HAVE_PROC_SELF_EXE], [1], [Define if the /proc/self/exe symlink is supported])
else
    AC_MSG_RESULT(no)
fi

dnl gettext
dnl =======
AM_GNU_GETTEXT([external])
if test "$MSGFMT" = ":" ; then
    AC_MSG_ERROR([msgfmt was not found; have you installed gettext?])
fi

dnl Build stamp
dnl ===========
AC_ARG_WITH([buildstamp],
 AS_HELP_STRING([--with-buildstamp=XXX], [Set build stamp to XXX]),
 AC_DEFINE_UNQUOTED([BUILDSTAMP], "$withval", [Build stamp]),
 AC_DEFINE_UNQUOTED([BUILDSTAMP], "unknown build", [Build stamp]))

dnl Activation of text console (MS-Windows ONLY)
dnl ============================================
AC_ARG_ENABLE([text-console],
[AS_HELP_STRING([--enable-text-console],[Enable text console for MS-Windows hosts])],
[use_text_console=$withval],
[use_text_console=no]
)

if test "x$HAVE_MSWINDOWS" = "xyes" && test "x$use_text_console" = "xno" ; then
	LDFLAGS="$LDFLAGS -Wl,-subsystem,windows"
fi

dnl Check for GTK+
dnl ==============

AC_ARG_ENABLE([gtk3],
 [AS_HELP_STRING([--disable-gtk3], [Use GTK2 even if GTK3 is present])],
 [use_gtk3=$enableval], [use_gtk3=yes])

if test $use_gtk3 = yes ; then
    PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.0.0], [use_gtk3=yes], [use_gtk3=no])
fi

if test $use_gtk3 = no ; then
    PKG_CHECK_MODULES([GTK], [gtk+-2.0 >= 2.12.0], [use_gtk3=no],
     AC_MSG_ERROR([Cannot find GTK headers.  Aborting ...]))
fi

AC_SUBST([GTK_LIBS])
AC_SUBST([GTK_CFLAGS])

### ---------------------------------------------------------------------------
dnl Path settings
dnl =============
AC_PATH_PROG([AUDACIOUS_PATH], [mlplayer], [no])

AUD_ARG_ENABLE([user-plugin-dir], [yes],
[per-user plugin dir])

if test "x$enable_user_plugin_dir" = "xno"; then
    AC_DEFINE([DISABLE_USER_PLUGIN_DIR], 1, [Define to disable per user plugin directory])
fi

AUD_ARG_ENABLE([rpath], [yes], [disable rpath])

if test "x$enable_rpath" = "xyes"; then
    LDFLAGS="$LDFLAGS -Wl,-rpath,${libdir}"
fi

### ---------------------------------------------------------------------------
dnl Chardet support
dnl ===============
AUD_ARG_ENABLE([chardet], [yes],
[charset detection support],
[
    PKG_CHECK_MODULES([LIBGUESS], [libguess >= 1.1], [enable_chardet=yes], [enable_chardet=no])

    if test "x$enable_chardet" = "xyes"; then
        AC_DEFINE([USE_CHARDET], 1, [Define if character set detection enabled])
    fi
])
AUD_CONDITIONAL([USE_CHARDET], [enable_chardet])


### ---------------------------------------------------------------------------
dnl D-Bus support
dnl =============
AUD_ARG_ENABLE([dbus], [yes],
[D-Bus support],
[
    PKG_CHECK_MODULES([DBUS], [dbus-1 >= 0.60 dbus-glib-1 >= 0.60 gthread-2.0],
        [enable_dbus=yes],
        [enable_dbus=no])

    AC_PATH_PROG([DBUS_BINDING_TOOL], [dbus-binding-tool], [no])
    AC_PATH_PROG([GLIB_GENMARSHAL], [glib-genmarshal], [no])
    if test "x$DBUS_BINDING_TOOL" = "xno" || test "x$GLIB_GENMARSHAL" = "xno" || test "x$enable_dbus" = "xno" ; then
        enable_dbus="no"
    else
        AC_DEFINE([USE_DBUS], 1, [Define if D-Bus support enabled])
        LIBAUDCLIENT_LDFLAGS="-lmlpclient"
        AC_SUBST([DBUS_CFLAGS])
        AC_SUBST([DBUS_LIBS])
        AC_SUBST([DBUS_BINDING_TOOL])
        AC_SUBST([LIBAUDCLIENT_LDFLAGS])
    fi
])
AUD_CONDITIONAL([USE_DBUS], [enable_dbus])


### ---------------------------------------------------------------------------
dnl regex support (gnu/oniguruma/pcre)
dnl ==================================
REGEX_LIBS=
REGEX_CFLAGS=

regex_selected=

AC_ARG_WITH([regexlib],
[AS_HELP_STRING([--with-regexlib[=gnu/oniguruma/pcre]],[Use the chosen regex library (def: gnu)])],
[regex_selected=$withval],
[regex_selected=gnu]
)

case $regex_selected in
  pcre)
    AUD_CHECK_MODULE([LIBPCRE], [libpcre], [>= 6.7], [PCRE])
    AC_DEFINE([USE_REGEX_PCRE], 1, [If this macro is defined, use PCRE regex library.])
    REGEX_LIBS="-lpcreposix $LIBPCRE_LIBS"
    REGEX_CFLAGS="$LIBPCRE_CFLAGS"
    ;;
  oniguruma)
    AC_CHECK_LIB([onig], [onig_new],
    [
        AC_DEFINE([USE_REGEX_ONIGURUMA], 1, [If this macro is defined, use Oniguruma regex library.])
        REGEX_LIBS="-lonig"
    ],[
        AC_MSG_ERROR([Cannot find Oniguruma regex library.])
    ])
    ;;
  *)
    AC_DEFINE([USE_REGEX_GNU], 1, [If this macro is defined, use GNU regex library.])

    AC_CHECK_LIB(c, regcomp, REGEX_LIBS="-lc",
      [AC_CHECK_LIB(regex, regcomp, REGEX_LIBS="-lregex",
        [AC_CHECK_LIB(rx, regcomp, REGEX_LIBS="-lrx",
          AC_MSG_ERROR([Cannot find GNU regex library.])
        )]
      )]
    )
    ;;
esac

AC_MSG_CHECKING([regex library type])
AC_MSG_RESULT($regex_selected)

AC_SUBST([REGEX_LIBS])
AC_SUBST([REGEX_CFLAGS])


### ---------------------------------------------------------------------------
dnl Pthread support
dnl ===============
PTHREAD_LIBS=
PTHREAD_CFLAGS=

AC_CHECK_LIB(pthread, pthread_create, PTHREAD_LIBS="-lpthread",
  [AC_CHECK_LIB(pthreads, pthread_create, PTHREAD_LIBS="-lpthreads",
    [AC_CHECK_LIB(pthreadGC2, pthread_create, PTHREAD_LIBS="-lpthreadGC2")]
  )]
)

AC_SUBST([PTHREAD_LIBS])
AC_SUBST([PTHREAD_CFLAGS])

### ---------------------------------------------------------------------------
dnl Session management support
dnl ==========================

AUD_ARG_ENABLE([sm], [yes],
[session management],
[
    PKG_CHECK_MODULES([SM], [sm >= 1.0], [
        enable_sm="yes"
    ],[
        enable_sm="no"
    ])

    AC_SUBST([SM_CFLAGS])
    AC_SUBST([SM_LIBS])

    PKG_CHECK_MODULES([ICE], [ice >= 1.0],
     [enable_sm="${enable_sm}"],
     [enable_sm="no"])

    AC_SUBST([ICE_CFLAGS])
    AC_SUBST([ICE_LIBS])

    PKG_CHECK_MODULES(GLIB214, glib-2.0 >= 2.14, enable_sm=$enable_sm,
     enable_sm=no)

    if test $enable_sm = yes ; then
        AC_DEFINE(USE_EGGSM, 1, Define if session management should be used)
    fi
])

AUD_CONDITIONAL([USE_EGGSM], [enable_sm])

### ---------------------------------------------------------------------------
dnl Define plugin directories
dnl =========================
plugindir="$libdir/mlplayer"
AC_SUBST([plugindir])
AC_SUBST([pluginsubs])

AUD_DEFINE_PLUGIN_DIR([Transport])
AUD_DEFINE_PLUGIN_DIR([Input])
AUD_DEFINE_PLUGIN_DIR([Output])
AUD_DEFINE_PLUGIN_DIR([Effect])
AUD_DEFINE_PLUGIN_DIR([General])
AUD_DEFINE_PLUGIN_DIR([Visualization])
AUD_DEFINE_PLUGIN_DIR([Container])
AUD_DEFINE_PLUGIN_DIR([Discovery])


### ---------------------------------------------------------------------------
dnl XXX Work around some autoconf bugs.
if test "x$prefix" = "xNONE"; then
        prefix="${ac_default_prefix}"
fi

if test -z "$datadir"; then
    datadir="${prefix}/share"
fi

localedir="$datadir/locale"
AC_SUBST([localedir])

AUDACIOUS_DEFINES="-DPLUGINSUBS=$pluginsubs"
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_BINDIR=\\\"$bindir\\\""
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_DATADIR=\\\"$datadir/mlplayer\\\""
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_PLUGINDIR=\\\"$plugindir\\\""
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_LOCALEDIR=\\\"$localedir\\\""
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_DESKTOPFILE=\\\"${datadir}/applications/mlplayer.desktop\\\""
AUDACIOUS_DEFINES="$AUDACIOUS_DEFINES -DHARDCODE_ICONFILE=\\\"${datadir}/pixmaps/mlplayer.png\\\""
AC_SUBST([AUDACIOUS_DEFINES])


### ---------------------------------------------------------------------------
dnl Output configuration files
dnl ==========================
AC_CONFIG_FILES([
    mlplayer.pc
    mlpclient.pc
    buildsys.mk
    extra.mk
    man/mlptool.1
    man/mlplayer.1
    src/libmlpcore/audio.h
])

BUILDSYS_TOUCH_DEPS
AC_OUTPUT

### ---------------------------------------------------------------------------
dnl Print out the results
dnl =====================
echo ""
echo "Configuration:"
echo ""
echo "  Install path:                           $prefix"

if test "x$AUDACIOUS_PATH" != "xno"; then
echo "  Current MLPlayer executable:           $AUDACIOUS_PATH"
fi

echo "  Allow user plugin dir:                  $enable_user_plugin_dir"
echo ""
echo "  Automatic character code detection:     $enable_chardet"
echo "  D-Bus support:                          $enable_dbus"
echo "  Session management (eggsm)              $enable_sm"
echo ""

if test "x$AUDACIOUS_PATH" != "xno" && test "x$prefix/bin/mlplayer" != "x$AUDACIOUS_PATH"; then
    mlplocation=`dirname $AUDACIOUS_PATH`
    echo "**"
    echo "** NOTICE! Configure has discovered that you already have MLPlayer installed"
    echo "** and it does not match with the given --prefix. You have MLPlayer installed"
    echo "** in ${mlplocation} and you chose ${prefix}/bin."
    echo "**"
    echo "** If you don't want two copies of MLPlayer installed, rerun configure with"
    echo "** the --prefix option set to the location of the old MLPlayer, or uninstall"
    echo "** the old MLPlayer."
    echo "**"
fi

if test "x$enable_dbus" != "xyes"; then
    echo "**"
    echo "** WARNING! DBUS support is disabled. This means that various features"
    echo "** the user might expect (such as remotely adding files to session via"
    echo "** commandline) will not work!"
    echo "**"
fi
