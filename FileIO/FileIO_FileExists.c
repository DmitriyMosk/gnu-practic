#include "FileIO.h"

int FileIO_FileExists(void) {
    return access(FILEPATH, F_OK);
}