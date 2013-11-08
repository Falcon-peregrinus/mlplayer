/*
 * libmlpgui.h
 * Copyright 2007-2009 Giacomo Lozito and Tomasz Moń

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; under version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses>.
 *
 * The MLPlayer team does not consider modular code linking to
 * MLPlayer or using our public API to be a derived work.
 */

#ifndef LIBAUDGUI_H
#define LIBAUDGUI_H

#include <libmlpcore/core.h>

/* macro defines for MLPlayer stock icons */
#define AUD_STOCK_PLAYLIST    "mlp-playlist"
#define AUD_STOCK_PLUGIN      "mlp-plugin"
#define AUD_STOCK_QUEUETOGGLE "mlp-queuetoggle"
#define AUD_STOCK_RANDOMIZEPL "mlp-randomizepl"

void mlpgui_register_stock_icons(void);

void mlpgui_show_add_url_window(bool_t open);

void mlpgui_jump_to_track(void);
void mlpgui_jump_to_track_hide(void);

void mlpgui_run_filebrowser(bool_t clear_pl_on_ok);
void mlpgui_hide_filebrowser(void);

/* about.c */
void mlpgui_show_about_window (void);

/* confirm.c */
void mlpgui_confirm_playlist_delete (int playlist);
void mlpgui_show_playlist_rename (int playlist);

/* equalizer.c */
void mlpgui_show_equalizer_window (void);
void mlpgui_hide_equalizer_window (void);

/* infopopup.c */
void mlpgui_infopopup_show (int playlist, int entry);
void mlpgui_infopopup_show_current (void);
void mlpgui_infopopup_hide (void);

/* infowin.c */
void mlpgui_infowin_show (int playlist, int entry);
void mlpgui_infowin_show_current (void);

/* jump-to-time.c */
void mlpgui_jump_to_time (void);

/* playlists.c */
void mlpgui_import_playlist (void);
void mlpgui_export_playlist (void);

/* queue-manager.c */
void mlpgui_queue_manager_show (void);

/* ui_playlist_manager.c */
void mlpgui_playlist_manager (void);

/* urilist.c */
void mlpgui_urilist_open (const char * list);
void mlpgui_urilist_insert (int playlist, int position, const char * list);
char * mlpgui_urilist_create_from_selected (int playlist);

/* util.c */
void mlpgui_set_default_icon (void);

#endif /* LIBAUDGUI_H */
