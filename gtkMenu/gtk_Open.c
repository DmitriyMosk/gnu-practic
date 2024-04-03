#include "gtkMenu.h"

GError *gtkErr = NULL;
GtkBuilder *builder = NULL;

void gtk_Open(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("org.gtk.practice", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(gtk_Activate), NULL);

    int status_run = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    printf("status_run: %d", status_run);
}