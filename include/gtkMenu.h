#include "FileIO.h"
#include <gtk/gtk.h>

#define UI "gtkMenu/pract.ui"

extern GtkBuilder *builder;
extern GError *gtkErr;

void gtk_Open(int argc, char *argv[]);
void gtk_Activate(GtkApplication *app, gpointer user_data);

// events
void _event_ABDev_clicked(GObject *object, gpointer userdata);
