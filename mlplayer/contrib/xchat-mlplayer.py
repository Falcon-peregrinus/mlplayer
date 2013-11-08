#
# X-Chat MLPlayer for MLPlayer 1.4 and later
# This uses the native MLPlayer D-Bus interface.
#
# To consider later:
#   - support org.freedesktop.MediaPlayer (MPRIS)?
#
# This script is in the public domain.
#   $Id: xchat-mlplayer.py 4574 2007-05-16 07:46:17Z deitarion $
#

__module_name__ = "xchat-mlplayer"
__module_version__ = "1.0.1"
__module_description__ = "Get NP information from MLPlayer"

from dbus import Bus, DBusException
import xchat

# connect to DBus
bus = Bus(Bus.TYPE_SESSION)

def get_mlp():
	try:
		return bus.get_object('org.atheme.mlplayer', '/org/atheme/mlplayer')
	except DBusException:
		print "\x02Either MLPlayer is not running or you have something wrong with your D-Bus setup."
		return None

def command_np(word, word_eol, userdata):
	mlp = get_mlp()
	if mlp:
		pos = mlp.Position()

		length = mlp.SongLength(pos)
		length = (length > 0) and ("%d:%02d" % (length / 60, length % 60)) or "stream"

		playSecs = mlp.Time() / 1000
		xchat.command("SAY [%s | %d:%02d/%s]" % (
			mlp.SongTitle(pos).encode("utf8"),
			playSecs / 60, playSecs % 60, length))
	return xchat.EAT_ALL

def makeVoidCommand(cmd):
	def callback(word, word_eol, userdata):
		getattr(get_mlp(), cmd, lambda: None)()
		return xchat.EAT_ALL
	return callback

def command_send(word, word_eol, userdata):
	if len(word) < 2:
		print "You must provide a user to send the track to."
		return xchat.EAT_ALL

	mlp = get_mlp()
	if mlp:
		xchat.command('DCC SEND %s "%s"' % (word[1], mlp.SongFilename(mlp.Position()).encode("utf8")))
	return xchat.EAT_ALL

xchat.hook_command("NP",    command_np,                 help="Displays current playing song.")
xchat.hook_command("NEXT",  makeVoidCommand('Advance'), help="Advances in MLPlayer' playlist.")
xchat.hook_command("PREV",  makeVoidCommand('Reverse'), help="Goes backwards in MLPlayer' playlist.")
xchat.hook_command("PAUSE", makeVoidCommand('Pause'),   help="Toggles paused status.")
xchat.hook_command("STOP",  makeVoidCommand('Stop'),    help="Stops playback.")
xchat.hook_command("PLAY",  makeVoidCommand('Play'),    help="Begins playback.")
xchat.hook_command("SENDTRACK", command_send, help="Syntax: /SENDTRACK <nick>\nSends the currently playing track to a user.")

# IRC+PP support section

# XChat is lame and does not give us a server list.
def get_servers():
	chanlist = xchat.get_list("channels")
	servlist = []

	for i in chanlist:
		if i.server not in servlist:
			servlist.append(i.server)

	return servlist

ignore_services = 0;
def ignore_service_errors_cb(word, word_eol, userdata):
	global ignore_services

	if ignore_services == 1:
		return xchat.EAT_ALL

	return xchat.EAT_NONE

#xchat.hook_print("Notice", ignore_service_errors_cb)

def unset_ignore_services(userdata=None):
	global ignore_services

	ignore_services = 0
	return 1

last_title = None

def presence_notification_dispatch(userdata=None):
	global ignore_services, last_title

	mlp = get_mlp()

	ignore_services = 1
	if mlp:
		pos = mlp.Position()

		title = mlp.SongTitle(pos).encode("utf8")

		if title != last_title:
			slist = get_servers()
			for i in slist:
				ctx = xchat.find_context(i)

				ctx.command("nickserv set qproperty np %s" % (title))

			last_title = title

	return 1

#presence_notification_dispatch()
#xchat.hook_timer(3000, presence_notification_dispatch)
#xchat.hook_timer(500, unset_ignore_services)

print "xchat-mlplayer $Id: xchat-mlplayer.py 4574 2007-05-16 07:46:17Z deitarion $ loaded"
