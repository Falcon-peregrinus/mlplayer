/*
* Status Icon Plugin for MLPlayer
*
* Copyright 2005-2007 Giacomo Lozito <james@develia.org>
* Copyright 2010 Michał Lipski <tallica@o2.pl>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*
*/

#include <mlplayer/misc.h>

#include "statusicon.h"

static const gchar * const si_defaults[] = {
 "rclick_menu", "0", /* SI_CFG_RCLICK_MENU_SMALL1 */
 "scroll_action", "0", /* SI_CFG_SCROLL_ACTION_VOLUME */
 "volume_delta", "5",
 "disable_popup", "FALSE",
 "close_to_tray", "FALSE",
 "reverse_scroll", "FALSE",
 NULL};

si_cfg_t si_cfg;

void si_cfg_load (void)
{
    mlp_config_set_defaults ("statusicon", si_defaults);

    si_cfg.rclick_menu = mlp_get_int ("statusicon", "rclick_menu");
    si_cfg.scroll_action = mlp_get_int ("statusicon", "scroll_action");
    si_cfg.volume_delta = mlp_get_int ("statusicon", "volume_delta");
    si_cfg.disable_popup = mlp_get_bool ("statusicon", "disable_popup");
    si_cfg.close_to_tray = mlp_get_bool ("statusicon", "close_to_tray");
}


void si_cfg_save (void)
{
    mlp_set_int ("statusicon", "rclick_menu", si_cfg.rclick_menu);
    mlp_set_int ("statusicon", "scroll_action", si_cfg.scroll_action);
    mlp_set_int ("statusicon", "volume_delta", si_cfg.volume_delta);
    mlp_set_bool ("statusicon", "disable_popup", si_cfg.disable_popup);
    mlp_set_bool ("statusicon", "close_to_tray", si_cfg.close_to_tray);
}
