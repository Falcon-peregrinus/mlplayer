LIB = ${LIB_PREFIX}mlptag${LIB_SUFFIX}
LIB_MAJOR = 1
LIB_MINOR = 0

SRCS = mlptag.c		\
       util.c		\
       tag_module.c	\
       id3/id3-common.c \
       id3/id3v1.c	\
       id3/id3v22.c	\
       id3/id3v24.c	\
       ape/ape.c

INCLUDES = mlptag.h

include ../../buildsys.mk
include ../../extra.mk

CPPFLAGS := -I.. -I../.. \
            ${CPPFLAGS} \
            ${GLIB_CFLAGS}

CFLAGS += ${LIB_CFLAGS}

LIBS := -L../libmlpcore -lmlpcore \
        ${LIBS} \
        ${GLIB_LIBS}
