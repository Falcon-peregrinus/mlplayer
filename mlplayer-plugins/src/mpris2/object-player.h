/*
 * Generated by gdbus-codegen 2.30.2. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __OBJECT_PLAYER_H__
#define __OBJECT_PLAYER_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.mpris.MediaPlayer2.Player */

#define MPRIS_TYPE_MEDIA_PLAYER2_PLAYER (mpris_media_player2_player_get_type ())
#define MPRIS_MEDIA_PLAYER2_PLAYER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER, MprisMediaPlayer2Player))
#define MPRIS_IS_MEDIA_PLAYER2_PLAYER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER))
#define MPRIS_MEDIA_PLAYER2_PLAYER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER, MprisMediaPlayer2PlayerIface))

struct _MprisMediaPlayer2Player;
typedef struct _MprisMediaPlayer2Player MprisMediaPlayer2Player;
typedef struct _MprisMediaPlayer2PlayerIface MprisMediaPlayer2PlayerIface;

struct _MprisMediaPlayer2PlayerIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_next) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_pause) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_play) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_play_pause) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_previous) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_stop) (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

  gboolean  (*get_can_control) (MprisMediaPlayer2Player *object);

  gboolean  (*get_can_go_next) (MprisMediaPlayer2Player *object);

  gboolean  (*get_can_go_previous) (MprisMediaPlayer2Player *object);

  gboolean  (*get_can_pause) (MprisMediaPlayer2Player *object);

  gboolean  (*get_can_play) (MprisMediaPlayer2Player *object);

  gboolean  (*get_can_seek) (MprisMediaPlayer2Player *object);

  GVariant * (*get_metadata) (MprisMediaPlayer2Player *object);

  const gchar * (*get_playback_status) (MprisMediaPlayer2Player *object);

};

GType mpris_media_player2_player_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *mpris_media_player2_player_interface_info (void);
guint mpris_media_player2_player_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void mpris_media_player2_player_complete_next (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

void mpris_media_player2_player_complete_pause (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

void mpris_media_player2_player_complete_play (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

void mpris_media_player2_player_complete_play_pause (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

void mpris_media_player2_player_complete_previous (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);

void mpris_media_player2_player_complete_stop (
    MprisMediaPlayer2Player *object,
    GDBusMethodInvocation *invocation);



/* D-Bus method calls: */
void mpris_media_player2_player_call_next (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_next_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_next_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);

void mpris_media_player2_player_call_pause (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_pause_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_pause_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);

void mpris_media_player2_player_call_play (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_play_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_play_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);

void mpris_media_player2_player_call_play_pause (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_play_pause_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_play_pause_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);

void mpris_media_player2_player_call_previous (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_previous_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_previous_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);

void mpris_media_player2_player_call_stop (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mpris_media_player2_player_call_stop_finish (
    MprisMediaPlayer2Player *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mpris_media_player2_player_call_stop_sync (
    MprisMediaPlayer2Player *proxy,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
gboolean mpris_media_player2_player_get_can_control (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_control (MprisMediaPlayer2Player *object, gboolean value);

gboolean mpris_media_player2_player_get_can_go_next (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_go_next (MprisMediaPlayer2Player *object, gboolean value);

gboolean mpris_media_player2_player_get_can_go_previous (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_go_previous (MprisMediaPlayer2Player *object, gboolean value);

gboolean mpris_media_player2_player_get_can_pause (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_pause (MprisMediaPlayer2Player *object, gboolean value);

gboolean mpris_media_player2_player_get_can_play (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_play (MprisMediaPlayer2Player *object, gboolean value);

gboolean mpris_media_player2_player_get_can_seek (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_can_seek (MprisMediaPlayer2Player *object, gboolean value);

GVariant *mpris_media_player2_player_get_metadata (MprisMediaPlayer2Player *object);
GVariant *mpris_media_player2_player_dup_metadata (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_metadata (MprisMediaPlayer2Player *object, GVariant *value);

const gchar *mpris_media_player2_player_get_playback_status (MprisMediaPlayer2Player *object);
gchar *mpris_media_player2_player_dup_playback_status (MprisMediaPlayer2Player *object);
void mpris_media_player2_player_set_playback_status (MprisMediaPlayer2Player *object, const gchar *value);


/* ---- */

#define MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY (mpris_media_player2_player_proxy_get_type ())
#define MPRIS_MEDIA_PLAYER2_PLAYER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY, MprisMediaPlayer2PlayerProxy))
#define MPRIS_MEDIA_PLAYER2_PLAYER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY, MprisMediaPlayer2PlayerProxyClass))
#define MPRIS_MEDIA_PLAYER2_PLAYER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY, MprisMediaPlayer2PlayerProxyClass))
#define MPRIS_IS_MEDIA_PLAYER2_PLAYER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY))
#define MPRIS_IS_MEDIA_PLAYER2_PLAYER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_PROXY))

typedef struct _MprisMediaPlayer2PlayerProxy MprisMediaPlayer2PlayerProxy;
typedef struct _MprisMediaPlayer2PlayerProxyClass MprisMediaPlayer2PlayerProxyClass;
typedef struct _MprisMediaPlayer2PlayerProxyPrivate MprisMediaPlayer2PlayerProxyPrivate;

struct _MprisMediaPlayer2PlayerProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  MprisMediaPlayer2PlayerProxyPrivate *priv;
};

struct _MprisMediaPlayer2PlayerProxyClass
{
  GDBusProxyClass parent_class;
};

GType mpris_media_player2_player_proxy_get_type (void) G_GNUC_CONST;

void mpris_media_player2_player_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MprisMediaPlayer2Player *mpris_media_player2_player_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
MprisMediaPlayer2Player *mpris_media_player2_player_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void mpris_media_player2_player_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MprisMediaPlayer2Player *mpris_media_player2_player_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
MprisMediaPlayer2Player *mpris_media_player2_player_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON (mpris_media_player2_player_skeleton_get_type ())
#define MPRIS_MEDIA_PLAYER2_PLAYER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON, MprisMediaPlayer2PlayerSkeleton))
#define MPRIS_MEDIA_PLAYER2_PLAYER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON, MprisMediaPlayer2PlayerSkeletonClass))
#define MPRIS_MEDIA_PLAYER2_PLAYER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON, MprisMediaPlayer2PlayerSkeletonClass))
#define MPRIS_IS_MEDIA_PLAYER2_PLAYER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON))
#define MPRIS_IS_MEDIA_PLAYER2_PLAYER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MPRIS_TYPE_MEDIA_PLAYER2_PLAYER_SKELETON))

typedef struct _MprisMediaPlayer2PlayerSkeleton MprisMediaPlayer2PlayerSkeleton;
typedef struct _MprisMediaPlayer2PlayerSkeletonClass MprisMediaPlayer2PlayerSkeletonClass;
typedef struct _MprisMediaPlayer2PlayerSkeletonPrivate MprisMediaPlayer2PlayerSkeletonPrivate;

struct _MprisMediaPlayer2PlayerSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  MprisMediaPlayer2PlayerSkeletonPrivate *priv;
};

struct _MprisMediaPlayer2PlayerSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType mpris_media_player2_player_skeleton_get_type (void) G_GNUC_CONST;

MprisMediaPlayer2Player *mpris_media_player2_player_skeleton_new (void);


G_END_DECLS

#endif /* __OBJECT_PLAYER_H__ */
