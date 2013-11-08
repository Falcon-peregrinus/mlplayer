#ifndef __VORBIS_H__
#define __VORBIS_H__

#include <vorbis/vorbisfile.h>

#include <mlplayer/plugin.h>

extern ov_callbacks vorbis_callbacks;

gboolean vorbis_update_song_tuple (const Tuple * tuple, VFSFile * fd);

#endif                          /* __VORBIS_H__ */
