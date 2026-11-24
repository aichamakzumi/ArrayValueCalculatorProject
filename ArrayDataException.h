#pragma once
#include "Exception.h"
#include "FormatException.h"

class ArrayDataException : public Exception
{
private:
    int m_row;
    int m_col;
    char* m_cellValue;
    char* m_cause;

    void CopyString(char*& dest, const char* src);

public:
    ArrayDataException(int row, int col, const char* cellValue, const char* cause);
    ArrayDataException(int row, int col, const char* cellValue, const Exception& cause);
    ArrayDataException(const ArrayDataException& other);
    ArrayDataException& operator=(const ArrayDataException& other);
    virtual ~ArrayDataException();

    int GetRow() const;
    int GetCol() const;
    const char* GetCellValue() const;
    const char* GetCause() const;
};
