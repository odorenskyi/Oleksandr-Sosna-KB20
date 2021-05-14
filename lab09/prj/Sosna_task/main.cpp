#include <iostream>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include "MyDevInfo.h"

using namespace std;
int N = 0;
int res_2 = 0;
void copyright()
{
    cout << "Sosna Olexandr. CNTU 2021. (c)" << endl;
}
void electro()
{
    setlocale(LC_ALL, "Ukr");
    int x = 0;
    double res = 0;
    while(x < 1)
    {
        cout << "Уведiть кiлькiсть спожитої за мiсяць електроенергiї(число бiльше за 1): ";
        cin >> x;
    }
    res = electricity(x);
    cout << "Результат: " << res/100 << " гривень." << endl;
}

void tempCF()
{
    setlocale(LC_ALL, "Ukr");
    float arrTemp[12];
    for(int i = 0; i < 12; i++)
    {
        while(true)
        {
            cout << "Уведiть температуру за " << i + 1 << " мiсяць (вiд -100 до 100): ";
        if(!(scanf("%f", &arrTemp[i])))
        {
            scanf("%*[^\n]");
            continue;
        }
        if(arrTemp[i] >= -100.0 && arrTemp[i] <= 100.0)
        {
            break;
        }
        else
        {
            cout << "Невiрно введенi данi!" << endl;
        }
        }
    }
    cout << endl;

    cout << "Середньорiчна температура за Цельсiєм: " << temperature_1(arrTemp) << endl;
    cout << "Середньорiчна температура за Фаренгейтом: " << temperature_2(arrTemp) << endl;
}

void bit_task()
{
    setlocale(LC_ALL, "Ukr");
    while(true)
    {
        cout << "Уведiть число у дiапазонi вiд 0 до 5740500: ";
        cin >> N;
        if(N >= 0 && N <= 5740500)
        {
            cout << dec << bit_operation(N) << endl;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    copyright();
    float arrTemp[12];
    int x, y, z;
    float S;
    char input = 0;
    while(true)
    {
        cout << "Для виклику задачi 8.1 - n, для виклику задачi 9.1 - v, для виклику задачi 9.2 - c, Для виклику задачi 9.3 - x" << endl;
        cout << "Уведiть ключ для викликання певної функцiї." << endl;
        cin >> input;
        if(input == 'n')
        {

            do {cout << "Введiть значення x: ";
            cin >> x;
            cout << "Введiть значення y: ";
            cin >> y;
            do {cout << "Введiть значення z: ";
            cin >> z;
            if (z < 0)
                cout << "z не може бути меньше 0 " << endl;
            }while (z < 0);
            if (((y+4*((x*x*x) + cos(z))) ==0))
                cout << "Введений неправильний набiр даних" << endl;
            }while ((y+4*((x*x*x) + cos(z))) ==0);
            S = s_calculation(x, y, z);
    cout << "\n S = " << s_calculation(x, y, z) << endl;
        }
        else if(input == 'v')
        {
            electro();

            cout << "Для виходу з програми натиснiть z або Z" << endl;
        }
        else if(input == 'c')
        {
            tempCF();

            cout << "Для виходу з програми натиснiть z або Z" << endl;
        }
        else if(input == 'x')
        {
            bit_task();

            cout << "Для виходу з програми натиснiть z або Z" << endl;
        }
        else if(input == 'z' || input == 'Z')
        {
            break;
        }
        else
        {
            cout << '\a';
            cout << "Ви увели неправильний символ!" << endl;
        }
    }
}
