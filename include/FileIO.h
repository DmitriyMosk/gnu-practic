#include "stdio.h"
#include "stdlib.h"
#include <sys/stat.h>
#include <unistd.h>

#define FILEDIR     "data/"
#define FILEPATH    "data/top_10.dat"

#define FILE_EXISTS 0

int FileIO_FileExists(void);

FILE *FileIO_Write();
FILE *FileIO_Read();

void FileIO_End(FILE *file);