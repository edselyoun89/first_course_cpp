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
    task2();
    return 0;
}

struct Point {
    double x;
    double y;
};

double angleBetweenVectors(const Point* p1, const Point* p2) {
    double dotProduct = (p1->x * p2->x) + (p1->y * p2->y); // Рассчитываем скалярное произведение векторов

    // Рассчитываем длины векторов
    double length1 = sqrt(p1->x * p1->x + p1->y * p1->y);
    double length2 = sqrt(p2->x * p2->x + p2->y * p2->y);
    
    double cosTheta = dotProduct / (length1 * length2); // Рассчитываем косинус угла между векторами

    double thetaRadians = acos(cosTheta);  // Получаем угол в радианах из косинуса

    double thetaDegrees = thetaRadians * (180.0 / M_PI);     // Преобразуем радианы в градусы

    return thetaDegrees;
}

void task1(){
    string arr[] = {"C++", "is", "one", "of", "the", "world's", "most", "popular", "programming", "languages"};
    string* pointers[10];

    char targetLetter;

    cout << "Введите букву: ";
    cin >> targetLetter;
    
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (!arr[i].empty() && arr[i][0] == targetLetter) {
            pointers[count] = &arr[i];
            count++;
        }
    }

    cout << "Строки, начинающиеся на букву '" << targetLetter << "':" << std::endl;
    for (int i = 0; i < count; ++i) {
        cout << *pointers[i] << endl;
    }
}


void task2() {
    Point p1, p2;
    
    cout << "Введите координаты первой точки (x y): ";
    cin >> p1.x >> p1.y;
    
    cout << "Введите координаты второй точки (x y): ";
    cin >> p2.x >> p2.y;
    
    double angle = angleBetweenVectors(&p1, &p2);
    
    cout << "Угол между векторами: " << angle << " градусов" << endl;
}

