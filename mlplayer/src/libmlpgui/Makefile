LIB = ${LIB_PREFIX}mlpgui${LIB_SUFFIX}
LIB_MAJOR = 1
LIB_MINOR = 0

SRCS = about.c \
       confirm.c \
       effects-menu.c \
       equalizer.c \
       iface-menu.c \
       infopopup.c \
       infowin.c \
       init.c \
       jump-to-time.c \
       list.c \
       playlists.c \
       queue-manager.c \
       ui_fileopener.c \
       ui_urlopener.c \
       ui_jumptotrack.c \
       ui_jumptotrack_cache.c \
       icons-stock.c \
       ui_playlist_manager.c \
       urilist.c \
       util.c

INCLUDES = libmlpgui.h \
           libmlpgui-gtk.h \
           list.h

include ../../buildsys.mk
include ../../extra.mk

includesubdir = libmlpgui

CPPFLAGS := -I.. -I../.. \
            ${CPPFLAGS} \
            ${GLIB_CFLASG} \
            ${GTK_CFLAGS} \
            ${REGEX_CFLAGS}

CFLAGS += ${LIB_CFLAGS}

LIBS := -L../libmlpcore -lmlpcore \
        ${LIBS} -lm \
        ${GLIB_LIBS} \
        ${GTK_LIBS} \
        ${REGEX_LIBS}
