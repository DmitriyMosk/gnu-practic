#include "smartphone.h"

int sm_OpenSmartphoneList(FILE *I_FILE) {

    unsigned long rCount = 0;
    rCount = fread(SMARTPHONES, sizeof(struct smartphone), SM_COUNT_ITEMS, I_FILE);

    if (rCount != SM_COUNT_ITEMS) {
        return SM_FAULT;
    }

    return SM_SUCCESS;
}