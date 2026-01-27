#include "strlen.h"

long strlen(const char* str)
{
    const char* i = str;
    while (*i) i++;
    return i - str;
}