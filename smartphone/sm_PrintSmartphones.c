#include "smartphone.h"

void sm_PrintSmartphones() {
    printf("----- SM_MEMORY_LOG -----\n");
    printf("Count SM_objs: %i\n", SM_COUNT_ITEMS);

    for(int i = 0; i < SM_COUNT_ITEMS; i++) {
        struct smartphone cur = SMARTPHONES[i];

        sm_PrintSmartphone(cur);
    }

    printf("----- SM_MEMORY_END -----\n");
}