#!/bin/sh
SONGTITLE=$(mlptool current-song)
SONGELAPSED=$(mlptool current-song-output-length)
SONGLEN=$(mlptool current-song-length)
MIME=$(file -ib "`mlptool current-song-filename`")

echo "np: $SONGTITLE [$MIME] ($SONGELAPSED/$SONGLEN)"
