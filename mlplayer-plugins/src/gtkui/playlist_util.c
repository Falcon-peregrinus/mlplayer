/*  MLPlayer - Cross-platform multimedia player
 *  Copyright (C) 2005-2011  MLPlayer development team
 *  Copyright (C) 2010 Michał Lipski <tallica@o2.pl>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; under version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses>.
 *
 *  The MLPlayer team does not consider modular code linking to
 *  MLPlayer or using our public API to be a derived work.
 */

#include <gtk/gtk.h>

#include <mlplayer/drct.h>
#include <mlplayer/playlist.h>
#include <libmlpgui/libmlpgui.h>
#include <libmlpgui/list.h>

#include "playlist_util.h"
#include "ui_playlist_notebook.h"

GtkWidget * playlist_get_treeview (gint playlist)
{
    GtkWidget *page = gtk_notebook_get_nth_page(UI_PLAYLIST_NOTEBOOK, playlist);

    if (!page)
        return NULL;

    return g_object_get_data ((GObject *) page, "treeview");
}

gint playlist_count_selected_in_range (gint list, gint top, gint length)
{
    gint selected = 0;
    gint count;

    for (count = 0; count < length; count ++)
    {
        if (mlp_playlist_entry_get_selected (list, top + count))
            selected ++;
    }

    return selected;
}

gint playlist_get_focus (gint list)
{
    GtkWidget * tree = playlist_get_treeview (list);
    g_return_val_if_fail (tree, -1);

    return mlpgui_list_get_focus (tree);
}

void playlist_song_info (void)
{
    gint list = mlp_playlist_get_active ();
    gint focus = playlist_get_focus (list);

    if (focus < 0)
        return;

    mlpgui_infowin_show (list, focus);
}

void playlist_queue_toggle (void)
{
    gint list = mlp_playlist_get_active ();
    gint focus = playlist_get_focus (list);

    if (focus < 0)
        return;

    gint at = mlp_playlist_queue_find_entry (list, focus);

    if (at < 0)
        mlp_playlist_queue_insert (list, -1, focus);
    else
        mlp_playlist_queue_delete (list, at, 1);
}

void playlist_delete_selected (void)
{
    gint list = mlp_playlist_get_active ();
    gint focus = playlist_get_focus (list);
    focus -= playlist_count_selected_in_range (list, 0, focus);

    mlp_drct_pl_delete_selected (list);

    if (mlp_playlist_selected_count (list)) /* song changed? */
        return;

    if (focus == mlp_playlist_entry_count (list))
        focus --;
    if (focus >= 0)
    {
        mlp_playlist_entry_set_selected (list, focus, TRUE);
        playlist_set_focus (list, focus);
    }
}

void playlist_copy (void)
{
    gchar * text = mlpgui_urilist_create_from_selected (mlp_playlist_get_active ());
    if (! text)
        return;

    gtk_clipboard_set_text (gtk_clipboard_get (GDK_SELECTION_CLIPBOARD), text, -1);
    g_free (text);
}

void playlist_cut (void)
{
    playlist_copy ();
    playlist_delete_selected ();
}

void playlist_paste (void)
{
    gchar * text = gtk_clipboard_wait_for_text (gtk_clipboard_get
     (GDK_SELECTION_CLIPBOARD));
    if (! text)
        return;

    gint list = mlp_playlist_get_active ();
    mlpgui_urilist_insert (list, playlist_get_focus (list), text);
    g_free (text);
}

void playlist_shift (gint offset)
{
    gint list = mlp_playlist_get_active ();
    gint focus = playlist_get_focus (list);

    if (focus < 0 || ! mlp_playlist_entry_get_selected (list, focus))
        return;

    focus += mlp_playlist_shift (list, focus, offset);
    playlist_set_focus (list, focus);
}
