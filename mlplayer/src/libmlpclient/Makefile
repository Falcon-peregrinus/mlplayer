LIB = ${LIB_PREFIX}mlpclient${LIB_SUFFIX}
LIB_MAJOR = 2
LIB_MINOR = 0

SRCS = mlpctrl.c

INCLUDES = mlpctrl.h

include ../../buildsys.mk
include ../../extra.mk

pre-depend:
	cd ../mlplayer; ${MAKE} ${MFLAGS} dbus-client-bindings.h

CPPFLAGS := -I.. -I../.. \
            ${CPPFLAGS} \
            ${DBUS_CFLAGS} \
            ${GLIB_CFLAGS}

CFLAGS += ${LIB_CFLAGS}

LIBS += ${GLIB_LIBS}	\
	${DBUS_LIBS}
