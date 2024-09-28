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

void task1(), task2();


int main() {
    task1();
    return 0;
}

void print2(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void task1() {
    const int size = 3;
    int arr[size];
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    int m, n;

    cout << "Введите значение m: ";
    cin >> m;

    cout << "Введите значение n: ";
    cin >> n;

    cout << "Исходный массив: ";
    print2(arr, size);

    // a)
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 10 == 0) {
            arr[i] = 0;
        }
    }

    cout << " a): ";
    print2(arr, size);

    // b)
    int b[size];
    for (int i = 0; i < size; ++i) {
        b[i] = arr[i];
        if (b[i] % 2 != 0) {
            b[i] *= 2;
        } else {
            b[i] /= 2;
        }
    }

    cout << " b): ";
    print2(b, size);

    // c)
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0 && i % 2 == 0) {
            arr[i] -= m;
        }

        if (i % 2 != 0) {
            arr[i] += n;
        }
    }

    cout << " c): ";
    print2(arr, size);
}





void task2() {
    const int rows = 2;
    const int cols = 3;

    int matrix[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Введите элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int minEvenRow = -1;
    int minMultipleRow = -1;
    bool foundEven = false;
    bool foundMultiple = false;

    
    for (int i = 0; i < rows; ++i) {
        bool isEvenRow = true;

        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 != 0) {
                isEvenRow = false;
                break;
            }
        }

        if (isEvenRow && (!foundEven || i < minEvenRow)) {
            minEvenRow = i;
            foundEven = true;
        }
    }

    int a;
    cout << "Введите число a: ";
    cin >> a;

    for (int i = 0; i < rows; ++i) {
        bool isMultipleRow = true;

        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % a != 0) {
                isMultipleRow = false;
                break;
            }
        }

        if (isMultipleRow && (!foundMultiple || i < minMultipleRow)) {
            minMultipleRow = i;
            foundMultiple = true;
        }
    }

    
    if (foundEven) {
        cout << "a) Минимальный номер строки, состоящей только из четных элементов: " << minEvenRow << endl;
    } else {
        cout << "a) Такой строки не найдено." << endl;
    }

    if (foundMultiple) {
        cout << "b) Минимальный номер строки, состоящей только из элементов, кратных числу " << a << ": " << minMultipleRow << endl;
    } else {
        cout << "b) Такой строки не найдено." << endl;
    }

    cout << "Ваш двумерный массив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}