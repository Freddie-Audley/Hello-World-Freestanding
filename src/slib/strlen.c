#include "strlen.h"

long strlen(const char* str)
{
    const char* i = str;
    for (; *i; ++i) {}
    return i - str;
}