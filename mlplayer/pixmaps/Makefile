include ../buildsys.mk

# These override variables in buildsys.mk and so must come after it.
PACKAGE = pixmaps
DATA = mlplayer.png \
       mlplayer.svg

install-extra:
	${MKDIR_P} ${DESTDIR}${datadir}/icons/hicolor/48x48/apps
	${MKDIR_P} ${DESTDIR}${datadir}/icons/hicolor/scalable/apps
	${INSTALL} -m 644 mlplayer.png "${DESTDIR}${datadir}/icons/hicolor/48x48/apps/mlplayer.png"
	${INSTALL} -m 644 mlplayer.svg "${DESTDIR}${datadir}/icons/hicolor/scalable/apps/mlplayer.svg"

uninstall-extra:
	if test -f "${DESTDIR}${datadir}/icons/hicolor/48x48/apps/mlplayer.png" ; then ${RM} "${DESTDIR}${datadir}/icons/hicolor/48x48/apps/mlplayer.png" ; fi
	if test -f "${DESTDIR}${datadir}/icons/hicolor/scalable/apps/mlplayer.svg" ; then ${RM} "${DESTDIR}${datadir}/icons/hicolor/scalable/apps/mlplayer.svg" ; fi
