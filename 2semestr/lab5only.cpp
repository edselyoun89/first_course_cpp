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

void processArray(int* arr, int size, int m, int n) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 10 == 0) {
            *(arr + i) = 0;
        }
    }
}
void processArray1(int* arr, int size, int m, int n) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) % 2 == 0) {
            *(arr + i) /= 2; 
        } else {
            *(arr + i) *= 2; 
        }
    }
}

void processArray2(int* arr, int size, int m, int n) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) % 2 != 0) { 
            *(arr + i) -= m;
        }
        if (i % 2 != 0) { 
            *(arr + i) += n; 
        }
    }
}



bool palindrome(const char* str, int length) {
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}



void task1(){
   char input[100]; 

    cout << "Введите строку: ";
    cin.getline(input, 100);

    if (palindrome(input, strlen(input))) {
        cout << input << " является палиндромом." << endl;
    } else {
        cout << input << " не является палиндромом." << endl;
    }
}


void task2() {
    const int size = 3;
    int arr[size];
    int arr1[size];
    int arr2[size];
    int arr3[size];

    cout << "Введите " << size << " элементов массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
        arr1[i]=arr[i];
        arr2[i]=arr[i];
        arr3[i]=arr[i];

    }

    int m, n;
    cout << "Введите значение m: ";
    cin >> m;
    cout << "Введите значение n: ";
    cin >> n;

    processArray(arr1, size, 0, 0);
    cout << "Обработанный массив 1: ";
    for (int j = 0; j < size; ++j) {
        cout << arr1[j] << " ";
    }
    cout << endl;

    processArray1(arr2, size, m, n);
    cout << "Обработанный массив 2: ";
    for (int w = 0; w < size; ++w) {
        cout << arr2[w] << " ";
    }
    cout << endl;

    

    processArray2(arr3, size, m, n);
    cout << "Обработанный массив 3: ";
    for (int e = 0; e < size; ++e) {
        cout << arr3[e] << " "; 
    }
    cout << endl;

}