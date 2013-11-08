/*
 * libmlpgui-gtk.h
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

#ifndef LIBAUDGUI_GTK_H
#define LIBAUDGUI_GTK_H

#include <stdint.h>
#include <gtk/gtk.h>
#include <libmlpcore/core.h>

/* effects-menu.c */
GtkWidget * mlpgui_create_effects_menu (void);
GtkWidget * mlpgui_create_vis_menu (void);

/* iface-menu.c */
GtkWidget * mlpgui_create_iface_menu (void);

/* util.c */
void mlpgui_hide_on_delete (GtkWidget * widget);
void mlpgui_hide_on_escape (GtkWidget * widget);
void mlpgui_destroy_on_escape (GtkWidget * widget);
void mlpgui_simple_message (GtkWidget * * widget, GtkMessageType type,
 const char * title, const char * text);
void mlpgui_connect_check_box (GtkWidget * box, bool_t * setting);

GdkPixbuf * mlpgui_pixbuf_from_data (const void * data, int64_t size);
GdkPixbuf * mlpgui_pixbuf_for_entry (int playlist, int entry);
GdkPixbuf * mlpgui_pixbuf_for_current (void);
void mlpgui_pixbuf_scale_within (GdkPixbuf * * pixbuf, int size);

#endif
