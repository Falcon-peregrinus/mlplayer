#include <mlplayer/i18n.h>
#include <libmlpgui/libmlpgui.h>
#include <libmlpgui/libmlpgui-gtk.h>

#include <gtk/gtk.h>

#include "vtx.h"
#include "ayemu.h"

void vtx_about (void)
{
    static GtkWidget * box = NULL;

    mlpgui_simple_message (& box, GTK_MESSAGE_INFO, _("About Vortex Player"),
     _("Vortex file format player by Sashnov Alexander <sashnov@ngs.ru>\n"
     "Founded on original source in_vtx.dll by Roman Sherbakov <v_soft@microfor.ru>\n"
     "\n"
     "Music in vtx format can be found at http://vtx.microfor.ru/music.htm\n"
     "and other AY/YM music sites.\n"
     "\n"
     "MLPlayer implementation by Pavel Vymetalek <pvymetalek@seznam.cz>"));
}
