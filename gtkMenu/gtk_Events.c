#include "gtkMenu.h"
#include "smartphone.h"

void gtk_event_draw_smartphone_clicked(GtkWidget *widget, gpointer userdata) {
    char info[256];

    GtkLabel *label_info = GTK_LABEL(gtk_builder_get_object(builder, "smartphone_info"));

    struct smartphone element;
    int max_price = 0;

    for(int i = 0; i < SM_COUNT_ITEMS; i++) {
        if (SMARTPHONES[i].Cost > max_price && SMARTPHONES[i].MEMCount < 6) {
            max_price = SMARTPHONES[i].Cost;
            element = SMARTPHONES[i];
        }
    }

    char *markup;

    if (max_price == 0) {
        markup = g_markup_printf_escaped ("Ничего не найдено");
    } else {
        markup = g_markup_printf_escaped ("Модель: %s\nЦвет: %s\nCPU: %s\nОперативная память:%i GB\nПостоянная память: %i GB\nЦена: %i Руб.\nРазмер экрана: %.2f Дюйм\nЁмкость батареи: %i",
                                          element.Model,
                                          element.Color,
                                          element.CPU,
                                          element.MEMCount,
                                          element.PZUCount,
                                          element.Cost,
                                          element.ScreenSize,
                                          element.BATCapacity);
    }

    gtk_label_set_markup (label_info, markup);
    g_free (markup);

    g_print("%s.%s.%s.%d.%d", element.Model, element.Color, element.CPU, element.MEMCount, element.Cost);
}