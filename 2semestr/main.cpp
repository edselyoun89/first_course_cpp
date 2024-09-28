#include <iostream>
#include "temperature_converter.h"
using namespace std;
 

int main() {
    double celsius_temperature;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> celsius_temperature;

    double fahrenheit_temperature = celsius_to_fahrenheit(celsius_temperature);

    cout << "Температура в градусах Фаренгейта: " << fahrenheit_temperature << endl;

    return 0;
}
    