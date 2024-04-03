#include "smartphone.h"

int SMARTPHONES_COUNT = 0;

int sm_StoreSmartphone(struct smartphone sm) {
    SMARTPHONES[SMARTPHONES_COUNT] = sm;

    SMARTPHONES_COUNT++;
    return SM_SUCCESS;
}