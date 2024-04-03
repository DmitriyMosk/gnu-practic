#include "smartphone.h"

int sm_SaveSmartphoneList(FILE *O_FILE) {
    if (O_FILE == NULL) {
        perror("Error saving: file thread is null");
        abort();
    }

    unsigned long wCount = 0;
    wCount = fwrite(SMARTPHONES, sizeof(struct smartphone), SM_COUNT_ITEMS, O_FILE);

    if (wCount != SM_COUNT_ITEMS) {
        return SM_FAULT;
    }

    return SM_SUCCESS;
}