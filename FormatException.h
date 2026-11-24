#pragma once
#include "Exception.h"

class FormatException : public Exception
{
public:
    FormatException(const char* message);
};
