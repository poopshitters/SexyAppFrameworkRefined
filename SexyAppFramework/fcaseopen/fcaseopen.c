#include "fcaseopen.h"

FILE *fcaseopen(char const *path, char const *mode)
{
    FILE *f = fopen(path, mode);
    return f;
}

void casechdir(char const *path)
{
    chdir(path);
}
