SUBDIRS = libmlpcore libmlpgui libmlptag mlplayer

include ../extra.mk

ifeq ($(USE_EGGSM),yes)
SUBDIRS := libeggsmclient ${SUBDIRS}
endif

ifeq ($(USE_DBUS),yes)
SUBDIRS := libmlpclient mlptool ${SUBDIRS}
endif

include ../buildsys.mk
