/*
 * general.h
 * Copyright 2011 John Lindgren
 *
 * This file is part of MLPlayer.
 *
 * MLPlayer is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 2 or version 3 of the License.
 *
 * MLPlayer is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * MLPlayer. If not, see <http://www.gnu.org/licenses/>.
 *
 * The MLPlayer team does not consider modular code linking to MLPlayer or
 * using our public API to be a derived work.
 */

#ifndef AUDACIOUS_GENERAL_H
#define AUDACIOUS_GENERAL_H

#include "plugins.h"

void general_init (void);
void general_cleanup (void);

bool_t general_plugin_start (PluginHandle * plugin);
void general_plugin_stop (PluginHandle * plugin);

PluginHandle * general_plugin_by_widget (/* GtkWidget * */ void * widget);

#endif
