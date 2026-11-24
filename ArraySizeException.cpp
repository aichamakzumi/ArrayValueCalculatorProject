#include "ArraySizeException.h"

static int StrLen(const char* s)
{
    if (!s) return 0;
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

static void StrCat(char* dest, const char* src)
{
    if (!dest || !src) return;
    int destLen = StrLen(dest);
    int i = 0;
    while (src[i] != '\0')
    {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

ArraySizeException::ArraySizeException(const char* message)
    : Exception(nullptr)
{
    char buffer[256] = "ArraySizeException: ";
    if (message)
    {
        StrCat(buffer, message);
    }
    SetMessage(buffer);
}
