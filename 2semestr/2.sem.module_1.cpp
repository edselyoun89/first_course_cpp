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

void task1();

const int MAX_TRAINS = 3;

struct TRAIN {
    string NAZN;
    int NUMR;
    string TIME1;
    string TIME2;
};

bool compareTrains(const TRAIN& train1, const TRAIN& train2) {
    return train1.NUMR < train2.NUMR;
}

string calculateTravelTime(const string& departureTime, const string& arrivalTime) {
    int departureMinutes = stoi(departureTime.substr(0, 2)) * 60 + stoi(departureTime.substr(3, 2));
    int arrivalMinutes = stoi(arrivalTime.substr(0, 2)) * 60 + stoi(arrivalTime.substr(3, 2));

    int travelTimeMinutes = arrivalMinutes - departureMinutes;

    int hours = travelTimeMinutes / 60;
    int minutes = travelTimeMinutes % 60;

    return "Время в пути: " + to_string(hours) + " часов " + to_string(minutes) + " минут";
}


int main() {
    TRAIN RASP[MAX_TRAINS];

    for (int i = 0; i < MAX_TRAINS; ++i) {
        cout << "Введите информацию о поезде " << i + 1 << ":\n";
        cout << "Пункт назначения: ";
        cin >> RASP[i].NAZN;
        cout << "Номер поезда: ";
        cin >> RASP[i].NUMR;
        cout << "Время отправления: ";
        cin >> RASP[i].TIME1;
        cout << "Время прибытия: ";
        cin >> RASP[i].TIME2;
        cout << "\n";
    }

    sort(RASP, RASP + MAX_TRAINS, compareTrains);

    cout << "\nСортировка записей по номерам поездов:\n";
    for (int i = 0; i < MAX_TRAINS; ++i) {
        cout << "Поезд: " << i + 1 << ":\n";
        cout << "Пункт назначения: " << RASP[i].NAZN << "\n";
        cout << "Номер поезда: " << RASP[i].NUMR << "\n";
        cout << "Время отправения: " << RASP[i].TIME1 << "\n";
        cout << "Время прибытия: " << RASP[i].TIME2 << "\n";
        cout << "\n";
    }

    int searchTrainNumber;
    cout << "Введите номер поезда, чтобы узнать время в пути: ";
    cin >> searchTrainNumber;

    bool trainFound = false;
    for (int i = 0; i < MAX_TRAINS; ++i) {
        if (RASP[i].NUMR == searchTrainNumber) {
            cout << "\nПоезд найден:\n";
            cout << "Пункт назначчения: " << RASP[i].NAZN << "\n";
            cout << "Номер поезда: " << RASP[i].NUMR << "\n";
            cout << "Время отправления: " << RASP[i].TIME1 << "\n";
            cout << "Врея прибытия: " << RASP[i].TIME2 << "\n";
            cout << calculateTravelTime(RASP[i].TIME1, RASP[i].TIME2) << "\n";
            trainFound = true;
            break;
        }
    }

    if (!trainFound)  {
        cout << "Поезд с номером " << searchTrainNumber << " не найден.\n";
    }

    return 0;
}
