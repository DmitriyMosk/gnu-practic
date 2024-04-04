#include "gtkMenu.h"
#include "smartphone.h"

void gtk_event_draw_smartphone_clicked(GtkWidget *widget, gpointer userdata) {
    char info[256];

    GObject *obj_label = gtk_builder_get_object(builder, "smartphone_info");

    struct smartphone element;
    int max_price = 0;

    for(int i = 0; i < SM_COUNT_ITEMS; i++) {
        if (SMARTPHONES[i].Cost > max_price && SMARTPHONES[i].MEMCount < 6) {
            max_price = SMARTPHONES[i].Cost;
            element = SMARTPHONES[i];
        }
    }

    g_print("%s.%s.%s.%d.%d", element.Model, element.Color, element.CPU, element.MEMCount, element.Cost);


}