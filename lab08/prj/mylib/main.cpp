#include <iostream>
#include <math.h>
#include <clocale>
#include "MyDevInfo.h"
#include <fstream>
#include <ctime>

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
float checkfl(float num){
  bool valid = false;
  while (!valid){
    valid = true;
    cout << "Введіть коректне число: ";
    cin >> num;
    if(cin.fail()) {
            cin.clear();
      cin.ignore();
      cout << "Не коректне число! ";
      valid = false;
    }

  }
  return num;
}


int checkint(int num){
  bool valid = false;
  while (!valid){
    valid = true;
    cout << "Введіть число: ";
    cin >> num;
    if(cin.fail()) {
            cin.clear();
      cin.ignore();
      cout << "Не число! ";
      valid = false;
    }

  }
  return num;
}
int filefindstring(string infl, string outfl){ // 0 = nothing work, 1 = all works

    string texte;
    int upletters=0;


        ifstream file2;
        file2.open(infl, ios::in);
        if(file2.is_open()){
            cout<< "Файл успішно відкрито"<<endl;

            while (getline(file2, texte)){
                if(texte.length()<=10){
                    cout<< "\t Помилка \n \t У файлі знаходиться не рядок"<<endl;
                    return 0;
                }
                for (int i = 0; i< texte.length(); i++) {
                    if ((texte[i] >= 'А' && texte[i] <= 'Я')||(texte[i]=='І')||(texte[i]=='Ї')||(texte[i]=='Є')) {
                        upletters++;
                    }
                }
            }
            file2.close();

            ofstream file;
            file.open(outfl,ios::out);
            if(file.is_open()){
                cout<< "Файл успішно відкрито"<<endl;
                file << "Розробник: Сосна Олександр. Центральноукраїнський нацiональний технiчний унiверситет Місто Кропивницький, Україна 2021"<<endl;
                file<< "Кількість символів верхнього регістра у рядкові із вхідного файла: "<< upletters<<endl;
                string s2 = ("Коли малим ти вперше став на ноги — Яка ж то радість матері була! Від тихої колиски до порога Вона тебе за руку провела. Вона прибігла стомлена з роботи, І, може, сон їй очі замикав, А дома — новий клопіт і турботи, І довга низка непочатих справ.");
                if (s2.find(texte) != string::npos) {
                    file<< "Рядок із вхідного файла знайдено у вірші Василя Симоненка \"Вклонися їй\""<<endl;
                }else{
                    file<< "Рядок із вхідного файла НЕ знайдено у вірші Василя Симоненка \"Вклонися їй\""<<endl;
                }
                cout<<"Роботу завершено. Все записано у файлі"<<endl;
                return 1;
            }else{
                cout<< "Файл не відкрито/Не знайдено"<<endl;
            }
            file.close();
        }else{
            cout<< "Файл не відкрито/Не знайдено"<<endl;
            return 0;
        }

}

int filesize(string infl){//размер файла
    time_t cur_date = time(0);
    fstream file;
    file.open(infl, ios::app);
    if(file.is_open()){

            cout<< "Файл успішно відкрито"<<endl;
            file<<endl << "Час дозапису: "<<ctime(&cur_date);
            file << "Об\'єм файлу (у байтах): ";

            int size = 0;
            file.seekg (0, std::ios::end);
            size = file.tellg();
            file<< size;

            file.close();
            return 1;

    }else{
            cout<< "Файл не відкрито/Не знайдено"<<endl;
            return 0;
    }
}

int lab10task3(string file){
    int res;
    fstream fil3;
    fil3.open(file, ios::app);
    if(fil3.is_open()){
            cout<< "Файл успішно відкрито"<<endl;
            cout<< "Числа для s_calculation"<<endl;
            float x=checkfl(x);
            float y=checkfl(y);
            float z=checkfl(z);
            fil3<< "\nРезультат s_calculation: "<< s_calculation(x,y,z)<<endl;
            cout<<"Переведення числа в двійковий код"<<endl;
            int b=checkint(b);
            fil3<< "Число "<< b<< " у двійковому коді: ";
            for (int i=sizeof(b)*8-1; i>=0; --i){
                fil3<<(int)((b>>i)&1);
            }
            fil3.close();
            res = 1;
    }else{
            cout<< "Файл не відкрито/Не знайдено"<<endl;
            res = 0;
    }
    return res;
}


