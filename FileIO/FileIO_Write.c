#include "FileIO.h"

FILE *FileIO_Write() {
    FILE *file = NULL;
    mkdir(FILEDIR, 0777);

    file = fopen(FILEPATH, "wb");

    if (file == NULL)
    {
        perror( "File could not be opened" );
        abort();
    }

    return file;
}