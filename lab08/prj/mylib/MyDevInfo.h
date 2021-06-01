#ifndef MYDEVINFO_H_INCLUDED
#define MYDEVINFO_H_INCLUDED
#include <string>

double s_calculation(float x, float y, float z);
int electricity(int input_info);
float temperature_1(float yeartemp[12]);
float temperature_2(float yeartemp[12]);
int bit_operation(unsigned int num);

float checkfl(float num);
int checkint(int num);
int filefindstring(std::string infl, std::string outfl);
int filesize(std::string infl);
int lab10task3(std::string file);

#endif // MYDEVINFO_H_INCLUDED
