/* GDK - The GIMP Drawing Kit
 * Copyright (C) 2002 Hans Breuer
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include "gdk.h"
#include "gdkprivate-win32.h"
#include "gdkwin32screen.h"
#include "gdkdisplayprivate.h"
#include "gdkdisplay-win32.h"
#include "gdkmonitor-win32.h"

#include <dwmapi.h>

struct _GdkWin32Screen
{
  GObject parent_instance;

  int width, height;
};

struct _GdkWin32ScreenClass
{
  GObjectClass parent_class;
};

G_DEFINE_TYPE (GdkWin32Screen, gdk_win32_screen, G_TYPE_OBJECT)

void
_gdk_win32_screen_init_root_window_size (GdkWin32Screen *screen,
                                         GListModel     *monitors)
{
  GdkRectangle result = { 0, };
  int i;
  GdkMonitor *monitor;

  for (i = 1; i < g_list_model_get_n_items (monitors); i++)
  {
    GdkRectangle rect;

    monitor = g_list_model_get_item (monitors, i);
    gdk_monitor_get_geometry (monitor, &rect);
    gdk_rectangle_union (&result, &rect, &result);
    g_object_unref (monitor);
  }

  screen->width = result.width;
  screen->height = result.height;
}

static void
gdk_win32_screen_init (GdkWin32Screen *win32_screen)
{
}

static void
gdk_win32_screen_finalize (GObject *object)
{
  G_OBJECT_CLASS (gdk_win32_screen_parent_class)->finalize (object);
}

static void
gdk_win32_screen_class_init (GdkWin32ScreenClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = gdk_win32_screen_finalize;
}
