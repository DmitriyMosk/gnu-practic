#include "smartphone.h"

struct smartphone *SMARTPHONES = NULL;

int sm_InitSmartphones() {
    SMARTPHONES = (struct smartphone *)malloc(SM_COUNT_ITEMS * sizeof(struct smartphone));

    if (SMARTPHONES == NULL) {
        perror( "Memory allocation error: not enough memory");
        abort();
    }

    return SM_SUCCESS;
}