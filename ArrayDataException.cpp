#include "ArrayDataException.h"

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

static void IntToStr(int num, char* buffer)
{
    if (num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    char temp[32];
    int i = 0;
    bool neg = false;
    if (num < 0)
    {
        neg = true;
        num = -num;
    }
    while (num > 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    int j = 0;
    if (neg)
    {
        buffer[j++] = '-';
    }
    while (i > 0)
    {
        buffer[j++] = temp[--i];
    }
    buffer[j] = '\0';
}

void ArrayDataException::CopyString(char*& dest, const char* src)
{
    if (src)
    {
        int len = StrLen(src);
        dest = new char[len + 1];
        for (int i = 0; i <= len; i++)
        {
            dest[i] = src[i];
        }
    }
    else
    {
        dest = new char[1];
        dest[0] = '\0';
    }
}

ArrayDataException::ArrayDataException(int row, int col, const char* cellValue, const char* cause)
    : Exception(nullptr), m_row(row), m_col(col), m_cellValue(nullptr), m_cause(nullptr)
{
    CopyString(m_cellValue, cellValue);
    CopyString(m_cause, cause);

    char buffer[512] = "ArrayDataException: Invalid data in cell [";
    char numBuf[32];
    IntToStr(row, numBuf);
    StrCat(buffer, numBuf);
    StrCat(buffer, "][");
    IntToStr(col, numBuf);
    StrCat(buffer, numBuf);
    StrCat(buffer, "]: '");
    if (cellValue) StrCat(buffer, cellValue);
    StrCat(buffer, "' (Original exception: ");
    if (cause) StrCat(buffer, cause);
    StrCat(buffer, ")");

    SetMessage(buffer);
}

ArrayDataException::ArrayDataException(int row, int col, const char* cellValue, const Exception& cause)
    : ArrayDataException(row, col, cellValue, cause.GetMessage())
{
}

ArrayDataException::ArrayDataException(const ArrayDataException& other)
    : Exception(other.m_message), m_row(other.m_row), m_col(other.m_col), m_cellValue(nullptr), m_cause(nullptr)
{
    CopyString(m_cellValue, other.m_cellValue);
    CopyString(m_cause, other.m_cause);
}

ArrayDataException& ArrayDataException::operator=(const ArrayDataException& other)
{
    if (this != &other)
    {
        Exception::operator=(other);
        delete[] m_cellValue;
        delete[] m_cause;
        m_row = other.m_row;
        m_col = other.m_col;
        CopyString(m_cellValue, other.m_cellValue);
        CopyString(m_cause, other.m_cause);
    }
    return *this;
}

ArrayDataException::~ArrayDataException()
{
    delete[] m_cellValue;
    delete[] m_cause;
}

int ArrayDataException::GetRow() const
{
    return m_row;
}

int ArrayDataException::GetCol() const
{
    return m_col;
}

const char* ArrayDataException::GetCellValue() const
{
    return m_cellValue;
}

const char* ArrayDataException::GetCause() const
{
    return m_cause;
}
