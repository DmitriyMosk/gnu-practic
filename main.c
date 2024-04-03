#include "FileIO.h"
#include "gtkMenu.h"
#include "smartphone.h"

void BuildTestFile() {
    FILE *file = FileIO_Write();

    sm_InitSmartphones();

    for(int i = 0; i < SM_COUNT_ITEMS; ++i) {
        struct smartphone CurSM;

        printf("Insert smartphone model(Model): "); fgets(CurSM.Model, 32, stdin); CurSM.Model[strcspn(CurSM.Model, "\n")] = '\0';
        printf("Insert smartphone color(Color): "); fgets(CurSM.Color, 32, stdin); CurSM.Color[strcspn(CurSM.Color, "\n")] = '\0';
        printf("Insert CPU(Model): "); fgets(CurSM.CPU, 32, stdin); CurSM.CPU[strcspn(CurSM.CPU, "\n")] = '\0';
        printf("Insert MEMCount(GB): "); scanf("%i", &CurSM.MEMCount);
        printf("Insert PZUCount(GB): "); scanf("%i", &CurSM.PZUCount);
        printf("Insert Cost(RUR): "); scanf("%i", &CurSM.Cost);
        printf("Insert ScreenSize(inches): "); scanf("%f", &CurSM.ScreenSize);
        printf("Insert BATCapacity(mAh): "); scanf("%i", &CurSM.BATCapacity);

        sm_PrintSmartphone(CurSM);

        char acceptPoint;

        printf("Insert this smartphone on table number %d? [Y/N]: ", i);

        do {
            acceptPoint = (char)getchar();
        }while(acceptPoint != 'Y' && acceptPoint != 'N');

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (acceptPoint == 'Y')
            sm_StoreSmartphone(CurSM);
        else
            i--;
    }

    sm_PrintSmartphones();

    if (sm_SaveSmartphoneList(file) != SM_SUCCESS) {
        perror("Error writing files: save fault");
        abort();
    }

    FileIO_End(file);
}

int main(int argc, char *argv[]) {
    if (FileIO_FileExists() != FILE_EXISTS) {
        BuildTestFile();
        printf("Please reopen this app.\nPress any key to exit.");

        while (getchar() != '\n')
            printf("Exit.\n");
    } else {
        FILE *file = FileIO_Read();

        int status_ok = 0;

        status_ok += sm_InitSmartphones();
        status_ok += sm_OpenSmartphoneList(file);

        if (status_ok != SM_SUCCESS) {
            perror("Error initializing memory or open list");
            abort();
        }

        sm_PrintSmartphones();

        FileIO_End(file);
        gtk_Open(argc, argv);
    }

    return 0;
}
