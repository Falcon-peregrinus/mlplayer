/*
 * plugins.h
 * Copyright 2010 John Lindgren
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

#ifndef AUDACIOUS_PLUGINS_H
#define AUDACIOUS_PLUGINS_H

#include <mlplayer/api.h>
#include <mlplayer/types.h>
#include <libmlpcore/core.h>

typedef bool_t (* PluginForEachFunc) (PluginHandle * plugin, void * data);

#define AUD_API_NAME PluginsAPI
#define AUD_API_SYMBOL plugins_api

#ifdef _AUDACIOUS_CORE

#include "api-local-begin.h"
#include "plugins-api.h"
#include "api-local-end.h"

enum {
 INPUT_KEY_SCHEME,
 INPUT_KEY_EXTENSION,
 INPUT_KEY_MIME,
 INPUT_KEYS};

/* plugin-init.c */
void start_plugins_one (void);
void start_plugins_two (void);
void stop_plugins_two (void);
void stop_plugins_one (void);

/* plugin-registry.c */
void plugin_registry_load (void);
void plugin_registry_prune (void);
void plugin_registry_save (void);

void plugin_register (const char * path);
void plugin_register_loaded (const char * path, Plugin * header);

void plugin_set_enabled (PluginHandle * plugin, bool_t enabled);

PluginHandle * transport_plugin_for_scheme (const char * scheme);
PluginHandle * playlist_plugin_for_extension (const char * extension);
void input_plugin_for_key (int key, const char * value, PluginForEachFunc
 func, void * data);
bool_t input_plugin_has_images (PluginHandle * plugin);
bool_t input_plugin_has_subtunes (PluginHandle * plugin);
bool_t input_plugin_can_write_tuple (PluginHandle * plugin);
bool_t input_plugin_has_infowin (PluginHandle * plugin);

/* pluginenum.c */
void plugin_system_init (void);
void plugin_system_cleanup (void);
void plugin_load (const char * path);

#else

#include <mlplayer/api-define-begin.h>
#include <mlplayer/plugins-api.h>
#include <mlplayer/api-define-end.h>

#include <mlplayer/api-alias-begin.h>
#include <mlplayer/plugins-api.h>
#include <mlplayer/api-alias-end.h>

#endif

#undef AUD_API_NAME
#undef AUD_API_SYMBOL

#endif

#ifdef AUD_API_DECLARE

#define AUD_API_NAME PluginsAPI
#define AUD_API_SYMBOL plugins_api

#include "api-define-begin.h"
#include "plugins-api.h"
#include "api-define-end.h"

#include "api-declare-begin.h"
#include "plugins-api.h"
#include "api-declare-end.h"

#undef AUD_API_NAME
#undef AUD_API_SYMBOL

#endif
