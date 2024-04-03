#include "FileIO.h"

FILE *FileIO_Read() {
    FILE *file = NULL;
    file = fopen(FILEPATH, "rb");

    if (file == NULL)
    {
        perror( "File could not be opened" );
        abort();
    }

    printf("Loading data..\n");

    return file;
}