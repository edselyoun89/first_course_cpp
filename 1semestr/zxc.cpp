#include<iostream>
#include <cstdio>
#include <math.h>
using namespace std;

void task1();

int main() {
    task1();
    return 0;

}

void task1() {

    const int N = 10;

    int a[N] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}; 

    int sum = 0;
    int g = 0;
    int j = 0;

   for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            g++;
            if (g == j) {
                sum += a[i];
            }
        } else {
            j++;
            if (g == j) {
                sum += a[i];
            }
        }
    }

    cout << "Сумма: " << sum <<endl;
}
