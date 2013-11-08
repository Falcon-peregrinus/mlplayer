/*
 * init.c
 * Copyright 2010-2011 John Lindgren
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    provided with the distribution.
 *
 * This software is provided "as is" and without any warranty, express or
 * implied. In no event shall the authors be liable for any damages arising from
 * the use of this software.
 */

#include <mlplayer/misc.h>
#include <mlplayer/playlist.h>
#include <libmlpcore/hook.h>

#include "config.h"
#include "init.h"
#include "libmlpgui.h"
#include "libmlpgui-gtk.h"

static const char * const mlpgui_defaults[] = {
 "close_dialog_add", "FALSE",
 "close_dialog_open", "TRUE",
 "close_jtf_dialog", "TRUE",
 "playlist_manager_close_on_activate", "FALSE",
 "remember_jtf_entry", "TRUE",
 NULL};

AudAPITable * _mlp_api_table = NULL;

static void playlist_set_playing_cb (void * unused, void * unused2)
{
    mlpgui_pixbuf_uncache ();
}

static void playlist_position_cb (void * list, void * unused)
{
    if (GPOINTER_TO_INT (list) == mlp_playlist_get_playing ())
        mlpgui_pixbuf_uncache ();
}

EXPORT void mlpgui_init (AudAPITable * table)
{
    _mlp_api_table = table;
    mlp_config_set_defaults ("mlpgui", mlpgui_defaults);

    hook_associate ("playlist set playing", playlist_set_playing_cb, NULL);
    hook_associate ("playlist position", playlist_position_cb, NULL);
}

EXPORT void mlpgui_cleanup (void)
{
    hook_dissociate ("playlist set playing", playlist_set_playing_cb);
    hook_dissociate ("playlist position", playlist_position_cb);

    mlpgui_hide_equalizer_window ();
    mlpgui_jump_to_track_hide ();
    mlpgui_pixbuf_uncache ();
    mlpgui_playlist_manager_cleanup ();
    mlpgui_queue_manager_cleanup ();

    _mlp_api_table = NULL;
}
