#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <cmath>    
#include <cctype>
#include <climits>
#include <vector>
#include <random>
#include <cstdlib> 
#include <ctime> 
using namespace std;

void task1(), task2(), task3();


int main() {
    task1();
    return 0;
}


bool isPalindrome(const char* str, int size) {
    if (str == nullptr || size <= 0) {
        // Обработка некорректных входных данных
        return false;
    }

    int left = 0;
    int right = size - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            // Если символы не совпадают, строка не является палиндромом
            return false;
        }

        // Переход к следующим символам
        left++;
        right--;
    }

    // Если цикл завершается, строка является палиндромом
    return true;
}

struct Point {
    double x;
    double y;
};

// Функция для вычисления угла между векторами и началом координат
double angleBetweenVectors(const Point* p1, const Point* p2) {
    // Вычисление скалярного произведения векторов
    double dotProduct = (p1->x * p2->x) + (p1->y * p2->y);

    // Вычисление длин векторов
    double magnitudeP1 = sqrt((p1->x * p1->x) + (p1->y * p1->y));
    double magnitudeP2 = sqrt((p2->x * p2->x) + (p2->y * p2->y));

    // Вычисление косинуса угла
    double cosAngle = dotProduct / (magnitudeP1 * magnitudeP2);

    // Вычисление угла в радианах
    double angleRad = acos(cosAngle);

    // Возвращение угла в градусах
    return angleRad * (180.0 / M_PI);
}


void task1(){
     // Пример использования функции
    const char* example1 = "radar";
    const char* example2 = "hello";

    if (isPalindrome(example1, strlen(example1))) {
        cout << example1 << " является палиндромом." << endl;
    } else {
        cout << example1 << " не является палиндромом." << endl;
    }

    if (isPalindrome(example2, strlen(example2))) {
        cout << example2 << " является палиндромом." << endl;
    } else {
        cout << example2 << " не является палиндромом." << endl;
    }
}

void task2() {
    Point point1 = {3.0, 4.0};  // Пример координат первой точки
    Point point2 = {1.0, 2.0};  // Пример координат второй точки

    // Вычисление угла между векторами
    double angle = angleBetweenVectors(&point1, &point2);

    // Вывод результата
    std::cout << "Угол между векторами: " << angle << " градусов" << std::endl;

}