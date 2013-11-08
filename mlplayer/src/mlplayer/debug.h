/*
 * debug.h
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

#ifndef AUDACIOUS_DEBUG_H
#define AUDACIOUS_DEBUG_H

#include <stdio.h>

#include <mlplayer/api.h>

#ifdef _AUDACIOUS_CORE
#define AUDDBG(...) do {if (verbose) {printf ("%s:%d [%s]: ", __FILE__, __LINE__, __FUNCTION__); printf (__VA_ARGS__);}} while (0)
#else
#define AUDDBG(...) do {if (* _mlp_api_table->verbose) {printf ("%s:%d [%s]: ", __FILE__, __LINE__, __FUNCTION__); printf (__VA_ARGS__);}} while (0)
#endif

#endif
