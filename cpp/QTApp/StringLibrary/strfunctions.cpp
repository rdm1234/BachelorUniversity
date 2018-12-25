#include "strfunctions.h"

int mystr::strlen(const char * string)
{
    int i = 0;
    while (string[i]!='\0') ++i;
    return i;
}
