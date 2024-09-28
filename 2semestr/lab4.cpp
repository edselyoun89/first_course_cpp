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
    task3();
    return 0;
}

int func(int *pi) { 
    if (pi != nullptr) // Проверка на нулевой указатель
    {
        *pi = 1024; 
        return *pi; 
    }
    else
    {
        return 0;
    }
}

void task1() {
    int ival;
    int *pi2 = &ival;
    int result = func(pi2);
}
 
void task2() {
    srand(time(0));

    int variable = rand() % 100 + 1;

    cout << "Случайное значение переменной: " << variable << endl;

    int *ptr1 = &variable;
    int *ptr2 = &variable;

    cout << "Исходное значение переменной: " << variable << endl;

    (*ptr1)++;
    cout << "Значение переменной после увеличения на 1: " << variable << endl;

    (*ptr2)--;
    cout << "Значение переменной после уменьшения на 1: " << variable << endl;

}

void task3() {
    int a, b;
    int *ptr_a, *ptr_b;

    ptr_a = &a;
    ptr_b = &b;

    cout << "Введите значение переменной a: ";
    cin >> a;

    cout << "Введите значение переменной b: ";
    cin >> b;

    int max_value = (*ptr_a > *ptr_b) ? *ptr_a : *ptr_b;

    cout << "Наибольшее значение: " << max_value << endl;
}