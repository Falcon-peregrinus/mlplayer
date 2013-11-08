LIB = ${LIB_PREFIX}mlpcore${LIB_SUFFIX}
LIB_MAJOR = 1
LIB_MINOR = 0

SRCS = audio.c \
       mlpstrings.c \
       eventqueue.c \
       hook.c \
       index.c \
       strpool.c \
       tuple.c \
       tuple_compiler.c \
       tuple_formatter.c \
       vfs.c \
       vfs_async.c \
       vfs_common.c

INCLUDES = audio.h \
           mlpstrings.h \
           core.h \
           hook.h \
           index.h \
           tuple.h \
           vfs.h \
           vfs_async.h

include ../../buildsys.mk
include ../../extra.mk

includesubdir = libmlpcore

CPPFLAGS := -I.. -I../.. \
            ${CPPFLAGS} \
            ${GLIB_CFLAGS} \
            ${PTHREAD_CFLAGS}

CFLAGS += ${LIB_CFLAGS}

LIBS += ${PTHREAD_LIBS} ${GLIB_LIBS} -lm
