#include "FileIO.h"
#include <gtk/gtk.h>

#define UI "gnu_ui/pract.ui"

extern GtkBuilder *builder;
extern GError *gtkErr;
extern GObject *window;

void gtk_Open(int argc, char *argv[]);
void gtk_Activate(GtkApplication *app, gpointer user_data);

// events
void gtk_event_draw_smartphone_clicked(GtkWidget *widget, gpointer userdata);