/*
 * Audtool2
 * Copyright (c) 2007 MLPlayer development team
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <locale.h>
#include "libmlpclient/mlpctrl.h"
#include "mlptool.h"

void playback_play(gint argc, gchar **argv)
{
	mlplayer_remote_play(dbus_proxy);
}

void playback_pause(gint argc, gchar **argv)
{
	mlplayer_remote_pause(dbus_proxy);
}

void playback_playpause(gint argc, gchar **argv)
{
	if (mlplayer_remote_is_playing(dbus_proxy))
	{
		mlplayer_remote_pause(dbus_proxy);
	}
	else
	{
		mlplayer_remote_play(dbus_proxy);
	}
}

void playback_stop(gint argc, gchar **argv)
{
	mlplayer_remote_stop(dbus_proxy);
}

void playback_playing(gint argc, gchar **argv)
{
	if (!mlplayer_remote_is_paused(dbus_proxy))
	{
		exit(!mlplayer_remote_is_playing(dbus_proxy));
	}
	else
	{
		exit(1);
	}
}

void playback_paused(gint argc, gchar **argv)
{
	exit(!mlplayer_remote_is_paused(dbus_proxy));
}

void playback_stopped(gint argc, gchar **argv)
{
	if (!mlplayer_remote_is_playing(dbus_proxy) && !mlplayer_remote_is_paused(dbus_proxy))
	{
		exit(0);
	}
	else
	{
		exit(1);
	}
}

void playback_status(gint argc, gchar **argv)
{
	if (mlplayer_remote_is_paused(dbus_proxy))
	{
		mlptool_report("paused");
		return;
	}
	else if (mlplayer_remote_is_playing(dbus_proxy))
	{
		mlptool_report("playing");
		return;
	}
	else
	{
		mlptool_report("stopped");
		return;
	}
}

void playback_seek(gint argc, gchar **argv)
{
	if (argc < 2)
	{
		mlptool_whine_args(argv[0], "<position>");
		exit(1);
	}

	mlplayer_remote_jump_to_time(dbus_proxy, atoi(argv[1]) * 1000);
}

void playback_seek_relative(gint argc, gchar **argv)
{
	gint oldtime, newtime, diff;

	if (argc < 2)
	{
		mlptool_whine_args(argv[0], "<position>");
		exit(1);
	}

	oldtime = mlplayer_remote_get_output_time(dbus_proxy);
	diff = atoi(argv[1]) * 1000;
	newtime = oldtime + diff;

	mlplayer_remote_jump_to_time(dbus_proxy, newtime);
}
