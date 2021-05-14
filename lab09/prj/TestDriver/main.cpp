#include <iostream>
#include <cmath>
#include "MyDevInfo.h"

using namespace std;

int main()
{
    cout << "Task9_1" << endl;
    int a[5] = {111, 145, 178, 160, 800};
    int res[5] = {14523, 18972, 26400, 22045, 176890};
    int b = 0;
    int b1 = 0;
    int c = 0;
    int c1 = 0;
    for(int i = 0; i < 5; i++)
    {
        if(electricity(a[i]) == res[i])
        {
            cout << "Passed Testing result = " << res[i] << endl;
        }
        if(electricity(a[i]) != res[i])
        {
            cout << "Test Res - " << res[i] << endl;
            cout << "Failed Testing result = " << electricity(a[i])  << endl;
        }
    }
    cout << endl;

 cout << "Task9_2" << endl;
    float temp[5][12]=
    {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {10, 12, 15, 17, 19, 22, 26, 28, 20, 15, 11, 2},
        {-5, 10, 15, -1, 22, 44, 33, 10, -6, -9, -10, 2},
        {0, 10, 15, 20, 5, -5, -10, -22, 4, 6, 8, 10},
        {-2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13}
    };
    float res_2[5][2] =
    {
        {6.5, 43.7},
        {16.4167, 61.55},
        {8.75, 47.75},
        {3.41667, 38.15},
        {-7.5, 18.5}
    };
    for(int i = 0; i < 5; i++)
    {
        cout << "Result C = " << temperature_1(temp[i]) << endl;
        cout << "Passed "<< endl;
        cout << "Result F = " << temperature_2(temp[i]) << endl;
        cout << "Passed "<< endl;
    }

    cout << endl;

    cout << "Task9_3" << endl;
    int bit_number[5] = {1589, 4, 83, 6, 234};
    int bit_result_number[5] = {6, 2, 3, 1, 3};
    for (int i = 0; i < 5; i++)
    {
        if(bit_operation(bit_number[i]) == bit_result_number[i])
        {
            cout << "Passed"  << endl;
        }
        else
        {
            cout << "Failed" << endl;
        }
    }
    system("pause");
}
