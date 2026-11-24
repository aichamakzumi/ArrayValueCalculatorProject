#pragma once
#include <iostream>

using namespace std;

class Exception
{
protected:
    char* m_message;

    void SetMessage(const char* message);

public:
    Exception(const char* message);
    Exception(const Exception& other);
    Exception& operator=(const Exception& other);
    virtual ~Exception();

    virtual const char* GetMessage() const;
};
