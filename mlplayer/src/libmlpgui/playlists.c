/*
 * playlists.c
 * Copyright 2011 John Lindgren
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

#include <gtk/gtk.h>

#include <mlplayer/i18n.h>
#include <mlplayer/misc.h>
#include <mlplayer/playlist.h>
#include <libmlpcore/vfs.h>

#include "config.h"
#include "libmlpgui.h"

static char * select_file (bool_t save, const char * default_filename)
{
    GtkWidget * dialog = gtk_file_chooser_dialog_new (save ?
     _("Export Playlist") : _("Import Playlist"), NULL, save ?
     GTK_FILE_CHOOSER_ACTION_SAVE : GTK_FILE_CHOOSER_ACTION_OPEN, NULL, NULL);

    if (default_filename)
        gtk_file_chooser_set_uri ((GtkFileChooser *) dialog, default_filename);

    gtk_dialog_add_button ((GtkDialog *) dialog, GTK_STOCK_CANCEL,
     GTK_RESPONSE_REJECT);
    gtk_dialog_add_button ((GtkDialog *) dialog, save ? GTK_STOCK_SAVE :
     GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT);

    gtk_dialog_set_default_response ((GtkDialog *) dialog, GTK_RESPONSE_ACCEPT);

    char * path = mlp_get_string ("mlpgui", "playlist_path");
    if (path[0])
        gtk_file_chooser_set_current_folder_uri ((GtkFileChooser *) dialog, path);
    g_free (path);

    char * filename = NULL;
    if (gtk_dialog_run ((GtkDialog *) dialog) == GTK_RESPONSE_ACCEPT)
        filename = gtk_file_chooser_get_uri ((GtkFileChooser *) dialog);

    path = gtk_file_chooser_get_current_folder_uri ((GtkFileChooser *) dialog);
    mlp_set_string ("mlpgui", "playlist_path", path);
    g_free (path);

    gtk_widget_destroy (dialog);
    return filename;
}

static bool_t confirm_overwrite (const char * filename)
{
    GtkWidget * dialog = gtk_message_dialog_new (NULL, 0, GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_YES_NO, _("Overwrite %s?"), filename);

    int result = gtk_dialog_run ((GtkDialog *) dialog);
    gtk_widget_destroy (dialog);
    return (result == GTK_RESPONSE_YES);
}

EXPORT void mlpgui_import_playlist (void)
{
    int list = mlp_playlist_get_active ();
    int id = mlp_playlist_get_unique_id (list);

    char * filename = select_file (FALSE, NULL);
    if (! filename)
        return;

    if ((list = mlp_playlist_by_unique_id (id)) < 0)
        return;

    mlp_playlist_entry_delete (list, 0, mlp_playlist_entry_count (list));
    mlp_playlist_entry_insert (list, 0, filename, NULL, FALSE);
    mlp_playlist_set_filename (list, filename);
    g_free (filename);
}

EXPORT void mlpgui_export_playlist (void)
{
    int list = mlp_playlist_get_active ();
    int id = mlp_playlist_get_unique_id (list);

    char * def = mlp_playlist_get_filename (list);
    char * filename = select_file (TRUE, def);
    str_unref (def);

    if (! filename || (vfs_file_test (filename, G_FILE_TEST_EXISTS) &&
     ! confirm_overwrite (filename)))
        return;

    if ((list = mlp_playlist_by_unique_id (id)) < 0)
        return;

    mlp_playlist_save (list, filename);
    g_free (filename);
}
