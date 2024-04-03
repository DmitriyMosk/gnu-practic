#include "FileIO.h"

struct smartphone {
    char    Model[32];     // Model
    char    Color[32];     // Color
    char    CPU[32];       // CPU Model
    int     MEMCount;      // MB
    int     PZUCount;      // MB
    int     Cost;          // RUR
    float   ScreenSize;    // inches
    int     BATCapacity;   // mAh
};

#define SM_COUNT_ITEMS 20
#define SM_SUCCESS 0
#define SM_FAULT  (-1)

extern struct smartphone *SMARTPHONES;

int sm_InitSmartphones();
int sm_StoreSmartphone(struct smartphone sm);

int sm_SaveSmartphoneList(FILE *O_FILE);
int sm_OpenSmartphoneList(FILE *I_FILE);

void sm_PrintSmartphones();
void sm_PrintSmartphone(struct smartphone sm);
