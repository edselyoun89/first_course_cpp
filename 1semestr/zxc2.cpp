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

const int MAX_TRAINS = 8;

struct TRAIN {
    string NAZN;
    int NUMR;
    string TIME1;
    string TIME2;
};

// Функция для сравнения по номерам поездов
bool compareTrains(const TRAIN& train1, const TRAIN& train2) {
    return train1.NUMR < train2.NUMR;
}

string calculateTravelTime(const string& departureTime, const string& arrivalTime) {
    // Здесь можно реализовать более сложный алгоритм для расчета времени в пути
    // В данном примере просто выводим разницу во времени
    return "Travel time: " + to_string(stoi(arrivalTime) - stoi(departureTime)) + " hours";
    return 0;

}


int main() {
    TRAIN RASP[MAX_TRAINS];

    // Ввод данных с клавиатуры
    for (int i = 0; i < MAX_TRAINS; ++i) {
        cout << "Enter information for train " << i + 1 << ":\n";
        cout << "Destination: ";
        cin >> RASP[i].NAZN;
        cout << "Train number: ";
        cin >> RASP[i].NUMR;
        cout << "Departure time: ";
        cin >> RASP[i].TIME1;
        cout << "Arrival time: ";
        cin >> RASP[i].TIME2;
        cout << "\n";
    }

    // Сортировка записей по номерам поездов
    sort(RASP, RASP + MAX_TRAINS, compareTrains);

    // Вывод отсортированных записей
    std::cout << "\nSorted records by train numbers:\n";
    for (int i = 0; i < MAX_TRAINS; ++i) {
        cout << "Train " << i + 1 << ":\n";
        cout << "Destination: " << RASP[i].NAZN << "\n";
        cout << "Train number: " << RASP[i].NUMR << "\n";
        cout << "Departure time: " << RASP[i].TIME1 << "\n";
        cout << "Arrival time: " << RASP[i].TIME2 << "\n";
        cout << "\n";
    }

    // Вывод информации о поезде и времени в пути
    int searchTrainNumber;
    cout << "Enter the train number to get travel time: ";
    cin >> searchTrainNumber;

    auto it = find_if(RASP, RASP + MAX_TRAINS, [searchTrainNumber](const TRAIN& train) {
        return train.NUMR == searchTrainNumber;
    });

    if (it != RASP + MAX_TRAINS) {
        cout << "\nTrain found:\n";
        cout << "Destination: " << it->NAZN << "\n";
        cout << "Train number: " << it->NUMR << "\n";
        cout << "Departure time: " << it->TIME1 << "\n";
        cout << "Arrival time: " << it->TIME2 << "\n";
        cout << calculateTravelTime(it->TIME1, it->TIME2) << "\n";
    } else {
        cout << "Train with number " << searchTrainNumber << " not found.\n";
    }


}






