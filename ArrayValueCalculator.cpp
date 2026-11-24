#include "ArrayValueCalculator.h"

int ArrayValueCalculator::StringToInt(const char* str)
{
    if (!str || str[0] == '\0')
    {
        throw FormatException("Empty string");
    }

    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }

    if (str[i] == '\0')
    {
        throw FormatException("String contains only whitespace");
    }

    bool negative = false;
    if (str[i] == '-')
    {
        negative = true;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    if (str[i] < '0' || str[i] > '9')
    {
        throw FormatException("Invalid integer format");
    }

    long long result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (negative && (-result < -2147483648LL))
        {
            throw FormatException("Integer overflow");
        }
        if (!negative && (result > 2147483647LL))
        {
            throw FormatException("Integer overflow");
        }
        i++;
    }

    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }

    if (str[i] != '\0')
    {
        throw FormatException("Unconverted trailing characters");
    }

    return negative ? static_cast<int>(-result) : static_cast<int>(result);
}

int ArrayValueCalculator::doCalc(const char* const* const* arr, int rows, int cols)
{
    if (rows != 4 || cols != 4)
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

int ArrayValueCalculator::doCalc(const char* const* const* arr, int rows, const int* cols)
{
    if (rows != 4)
    {
        throw ArraySizeException("Array must have 4 rows");
    }

    for (int i = 0; i < 4; i++)
    {
        if (cols[i] != 4)
        {
            throw ArraySizeException("Each row must have 4 columns");
        }
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
