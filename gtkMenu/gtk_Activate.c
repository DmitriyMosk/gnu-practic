#include "gtkMenu.h"

void gtk_Activate(GtkApplication *app, gpointer userdata) {
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, UI, NULL);

    // setup frame
    GObject *window = gtk_builder_get_object(builder, "main");
    gtk_window_set_application(GTK_WINDOW(window), app);
}