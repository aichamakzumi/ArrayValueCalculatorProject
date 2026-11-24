#pragma once
#include "ArraySizeException.h"
#include "ArrayDataException.h"
#include "FormatException.h"

class ArrayValueCalculator
{
private:
    int StringToInt(const char* str);

public:
    int doCalc(const char* const* const* arr, int rows, int cols);
    int doCalc(const char* const* const* arr, int rows, const int* cols);

    template <size_t Rows, size_t Cols>
    int doCalc(const char* const (&arr)[Rows][Cols])
    {
        if (Rows != 4 || Cols != 4)
        {
            throw ArraySizeException("Array size must be 4x4");
        }

        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                try
                {
                    int value = StringToInt(arr[i][j]);
                    sum += value;
                }
                catch (const FormatException& ex)
                {
                    throw ArrayDataException(i, j, arr[i][j], ex);
                }
            }
        }
        return sum;
    }
};
