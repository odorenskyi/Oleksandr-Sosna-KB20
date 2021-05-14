#include <iostream>
#include <math.h>
#include <clocale>
#include "MyDevInfo.h"

using namespace std;

double s_calculation(float x, float y, float z){
    double s;
    s = (z+y+z)*2 - sqrt(fabs(2*3.14*sqrt(0.5*z)/(y+4*((x*x*x) + cos(z)))));
    return s;
}

int electricity(int input_info)
{
    double s = 0;
    int p1 = 0;
    int p2 = 0;
    int s_1 = 0;
    double summa = 0;
    if(input_info <= 150)
    {
        s = input_info * 130.843;
    }
    if(input_info > 150)
    {
        s = 150 * 130.843;
        p1 = input_info - 150;
    }
    if(input_info > 150 && input_info <= 800)
    {
        s_1 = p1 * 241.945;
    }
    if(input_info > 800)
    {
        p2 = input_info - 800;
        s_1 = (p1 - p2) * 241.945 + p2 * 534.047;
    }
    summa = s_1 + s;
    return summa;
}
float temperature_1(float yeartemp[12])
{
    float res;
    for(int i = 0; i < 12; i++)
    {
        res += yeartemp[i];
    }
    res /= 12.0;
    return res;
}

float temperature_2(float yeartemp[12])
{
    float res = 0;
    return res = temperature_1(yeartemp) / 5 * 9 + 32;
}

int bit_operation(unsigned int num)
{
    int mask = 0b00000000000000000000000000000001;
    int mask_2 = 0b00000000000000000000000000000001;
    int D10 = 0b00000000000000000000001000000000;
    int counter = 0;
    int zero = 0;
    int one = 0;
    for(int i = 0; i < (log2(num)); i++)
    {
        if(!(num & mask))
        {
            zero++;
        }
        if(num & mask)
        {
            one++;
        }
        mask <<= 1;
    }
    if(num & (mask_2 << 10))
    {
    cout << "Binary One -  ";
    return one;
    }
    if(!(num & (mask_2 << 10)))
    {
    cout << "Binary Zero -  ";
    return zero;
    }
}

