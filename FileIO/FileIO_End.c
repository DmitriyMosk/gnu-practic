#include "FileIO.h"

void FileIO_End(FILE *file) {
    fclose(file);
}