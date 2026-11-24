#include <iostream>
#include "ArrayValueCalculator.h"
#include "ArraySizeException.h"
#include "ArrayDataException.h"

using namespace std;

int main()
{
    ArrayValueCalculator calculator;

    const char* validArray[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    const char* invalidSizeArray[3][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"}
    };

    const char* invalidDataArray[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "error", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    try
    {
        cout << "Test 1: Valid array" << endl;
        int result = calculator.doCalc(validArray);
        cout << "Calculation result: " << result << endl;
    }
    catch (const ArraySizeException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    catch (const ArrayDataException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    cout << endl;

    try
    {
        cout << "Test 2: Invalid array size" << endl;
        int result = calculator.doCalc(invalidSizeArray);
        cout << "Calculation result: " << result << endl;
    }
    catch (const ArraySizeException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    catch (const ArrayDataException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    cout << endl;

    try
    {
        cout << "Test 3: Invalid array data" << endl;
        int result = calculator.doCalc(invalidDataArray);
        cout << "Calculation result: " << result << endl;
    }
    catch (const ArraySizeException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    catch (const ArrayDataException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    cout << endl;

    system("pause");
    return 0;
}
