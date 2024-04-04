#include "gtkMenu.h"

GObject *window = NULL;

void gtk_Activate(GtkApplication *app, gpointer userdata) {
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, UI, NULL);

    // setup frame
    window = gtk_builder_get_object(builder, "main");
    gtk_window_set_application(GTK_WINDOW(window), app);

    // setup switcher
    GtkStackSwitcher *stack_switcher = NULL;
    GtkStack *stack = NULL;

    stack_switcher = GTK_STACK_SWITCHER(gtk_builder_get_object(builder, "switch"));
    stack          = GTK_STACK(gtk_builder_get_object(builder, "stack"));

    gtk_stack_switcher_set_stack(stack_switcher, stack);
    // setup switcher

    // draw smartphone btn
    GObject *draw_smartphone = gtk_builder_get_object (builder, "draw_smartphone");
    g_signal_connect (draw_smartphone, "clicked", G_CALLBACK (gtk_event_draw_smartphone_clicked), NULL);

    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    g_object_unref(builder);
}