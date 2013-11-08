#!/bin/sh
UNUSED=0
while [  $UNUSED -lt 1 ]; do
	PLAYTIME=$(mlptool current-song-output-length)
	SONGTITLE=$(mlptool current-song)
	SONGLEN=$(mlptool current-song-length)
	echo -n "[>] $PLAYTIME $SONGTITLE ($SONGLEN)                     "
	sleep 1
	printf "\r"
done
