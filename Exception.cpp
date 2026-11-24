#include "Exception.h"

void Exception::SetMessage(const char* message)
{
    if (message)
    {
        int len = 0;
        while (message[len] != '\0')
        {
            len++;
        }
        m_message = new char[len + 1];
        for (int i = 0; i <= len; i++)
        {
            m_message[i] = message[i];
        }
    }
    else
    {
        m_message = new char[1];
        m_message[0] = '\0';
    }
}

Exception::Exception(const char* message)
    : m_message(nullptr)
{
    SetMessage(message);
}

Exception::Exception(const Exception& other)
    : m_message(nullptr)
{
    SetMessage(other.m_message);
}

Exception& Exception::operator=(const Exception& other)
{
    if (this != &other)
    {
        delete[] m_message;
        SetMessage(other.m_message);
    }
    return *this;
}

Exception::~Exception()
{
    delete[] m_message;
}

const char* Exception::GetMessage() const
{
    return m_message;
}
