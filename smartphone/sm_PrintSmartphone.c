#include "smartphone.h"

void sm_PrintSmartphone(struct smartphone sm) {
    printf("\n");
    printf("Model: %s\n", sm.Model);
    printf("Color: %s\n", sm.Color);
    printf("CPU: %s\n", sm.CPU);
    printf("MEMCount: %iGB\n", sm.MEMCount);
    printf("PZUCount: %iGB\n", sm.PZUCount);
    printf("Cost: %iRUR\n", sm.Cost);
    printf("ScreenSize: %fInch\n", sm.ScreenSize);
    printf("BATCapacity: %imAh\n", sm.BATCapacity);
    printf("\n");
}