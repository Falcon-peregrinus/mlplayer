PLUGIN = jackout${PLUGIN_SUFFIX}

SRCS = jack.c		\
       bio2jack.c
#       configure.c	\

include ../../buildsys.mk
include ../../extra.mk

plugindir := ${plugindir}/${OUTPUT_PLUGIN_DIR}

CFLAGS += ${PLUGIN_CFLAGS}
CPPFLAGS += ${PLUGIN_CPPFLAGS} ${GTK_CFLAGS} ${GLIB_CFLAGS} ${PTHREAD_CFLAGS} -I../..
LIBS += ${GTK_LIBS} ${GLIB_LIBS}  ${JACK_LIBS} -lsamplerate ${PTHREAD_LIBS} -lm
