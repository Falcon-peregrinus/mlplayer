/*
 * init.h
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

#include <mlplayer/plugin.h>

/* init.c */
void mlpgui_init (AudAPITable * table);
void mlpgui_cleanup (void);

/* queue-manager.c */
void mlpgui_queue_manager_cleanup (void);

/* ui_playlist_manager.c */
void mlpgui_playlist_manager_cleanup (void);

/* util.c */
void mlpgui_pixbuf_uncache (void);
