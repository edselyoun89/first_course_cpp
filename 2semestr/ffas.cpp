#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;

int main() {
    struct weather
    {
        int tempreature, speed, rainfall;
        char direction[15];
        };
        int dayNum = 1;
        float avgTemp, avgSpeed;
        int t, s = 0;
        char flag[5];
        while (flag != "quit")
        {
            cout << "День " << dayNum << "\n";
            weather day;
            cout << "Введите температуру: ";
            cin >> day.tempreature;
            cout << "Введите осадки: ";
            cin >> day.rainfall;
            cout << "Введите направление ветра: ";
            cin >> day.direction;
            cout << "Введите скорость ветра: ";
            cin >> day.speed;
            t += day.tempreature;
            cout << "Закончить ввод сведений(quit)" << "\n" << "Продолжить ввод сведений(+)" << "\n";
            cin >> flag;
            dayNum += 1;
            }
            }
            