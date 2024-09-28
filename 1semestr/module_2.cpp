#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <cmath>
using namespace std;

void task_1(), task_1A(), task_1B(), task_2(), task_2A(), task_2B(), task_3(), task_3_1(), task_3_2(), task_3_3(), task_3A(), task_3B(), task_4A(), task_4B(), task_4V(), task_5A(), task_5B(), task_6A(), task_6B();

int main() {
    task_3();
    return 0;
}

void task_1() {
    char st[6];
    char ch;
    cout << "type characters and press Enter: ";
    cin >> st;
    ch = st[0];
    st[0] = st[4];
    st[4] = ch;
    cout << "the result is: " << st << endl;
    cin.get();
    cin.get();
}

void task_1A() {
    cout << "Введите строку: ";
    string input;
    getline(cin, input);
    int length = input.length();
    for (int i = length - 1; i >= 0; --i) {
        cout << input[i];
    }
    cout << endl;
}

void task_1B() {
    char input[100];
    int letter = 0;

    cout << "Введите строку: ";
    cin.getline(input, sizeof(input));
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
            input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            letter++;
        }
    }
    cout << "Количество гласных букв: " << letter << endl;
}


void task_2() {
    double num1, num2;

    cout << "enter number 1: ";
    cin >> num1;

    cout << "enter number 2: ";
    cin >> num2;

    double result = num1 + num2;
    cout << "the result is: " << result << endl;

    cout << "press enter to exit";
    cin.ignore();
    cin.get();
}

void task_2A() {
    double num1, num2;

    cout << "enter number 1: ";
    cin >> num1;

    cout << "enter number 2: ";
    cin >> num2;
    double euler = 2.71828;
    double result = pow(euler, num1 + 7)* sqrt(37 * num2 - pow(num1, 3));

    cout << "the result is: " << result << endl;

    cout << "press enter to exit";
    cin.ignore();
    cin.get();
}

void task_2B() {
    double num1, num2;

    cout << "enter number 1: ";
    cin >> num1;

    cout << "enter number 2: ";
    cin >> num2;
    double result = pow((num1 /(1 - num1)), 5) + 4 * num2 - 3 / num1;

    cout << "the result is: " << result << endl;

    cout << "press enter to exit";
    cin.ignore();
    cin.get();
}

void task_3() {
    char ch;
    cout << "type characters and press Enter: ";
    cin >> ch;

    int code = static_cast<int>(ch);

    cout << "ASCII-code is: " << code << endl;

    cout << "the previous character is: " << static_cast<char>(code - 1) << endl;

    cout << "the next character is: " << static_cast<char>(code + 1) << endl;

}

void task_3_1() {
    float floatValue;
    cout << "Enter a float value: ";
    cin >> floatValue;

    int intValue = static_cast<int>(floatValue);

    cout << "Converted int value: " << intValue << endl;
}

void task_3_2() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number) {
        cout << "The number is non-zero, which evaluates to true." << endl;
    } else {
        cout << "The number is zero, which evaluates to false." << endl;
    }
}

void task_3_3() {
    int negativeNumber = -5;
    unsigned int unsignedResult = static_cast<unsigned int>(negativeNumber);

    cout << "Negative number: " << negativeNumber << endl;
    cout << "Converted to unsigned int: " << unsignedResult << endl;
}

void task_3A() {
    long longNum = 10;
    double doubleNum = 5.5;

    double result = longNum + doubleNum;

    cout << "Result: " << result << endl;
}

void task_3B() {
    int intValue;

    cout << "Введите целое число: ";
    cin >> intValue;

    double doubleValue = static_cast<double>(intValue);

    cout << "Результат преобразования в double: " << doubleValue << endl;

}

void task_4A() {
    double A;
    int N;

    cout << "Введите вещественное число A: ";
    cin >> A;

    cout << "Введите целое число N (> 0): ";
    cin >> N;

    if (N <= 0) {
        cout << "Число N должно быть больше 0." << endl;
    }

    double sum = 1.0; 

    for (int i = 1; i <= N; ++i) {
        sum += pow(A, i);
    }

    cout << "Сумма 1 + A + A^2 + ... + A^N равна: " << sum << endl;

}

void task_4B() {
    int N;
    cout << "Введите целое число N (> 1): ";
    cin >> N;

    int a = 0, b = 1, c = 1;

    if (N == 0 || N == 1) {
        cout << "TRUE: " << N << " является числом Фибоначчи." << endl;
    } else {
        while (c < N) {
            c = a + b;
            a = b;
            b = c;
        }

        if (c == N) {
            cout << "TRUE: " << N << " является числом Фибоначчи." << endl;
        } else {
            cout << "FALSE: " << N << " не является числом Фибоначчи." << endl;
        }
    }
}

void task_4V() { 
    int a, b;

    cout << "Введите начало интервала (a): ";
    cin >> a;

    cout << "Введите конец интервала (b): ";
    cin >> b;

    int maxNumber = a;
    int maxSum = 0;

    for (int i = a; i <= b; ++i) {
        int sum = 0;
        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxNumber = i;
        }
    }

    cout << "Число с максимальной суммой делителей: " << maxNumber << endl;
    cout << "Максимальная сумма делителей: " << maxSum << endl;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void task_5A() {
    cout << "Все шестизначные счастливые номера:" << endl;

    for (int number = 100000; number <= 999999; ++number) {

        int firstHalf = number / 1000;
        int secondHalf = number % 1000;

        if (sumOfDigits(firstHalf) == sumOfDigits(secondHalf)) {
            cout << number << endl;
        }
    }


}

double Length(double xA, double yA, double xB, double yB) {
    return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}

void task_5B() {
    double xA, yA, xB, yB, xC, yC, xD, yD;
    
    cout << "Введите координаты точки A (xA yA): ";
    cin >> xA >> yA;

    cout << "Введите координаты точки B (xB yB): ";
    cin >> xB >> yB;

    cout << "Введите координаты точки C (xC yC): ";
    cin >> xC >> yC;

    cout << "Введите координаты точки D (xD yD): ";
    cin >> xD >> yD;

    double lengthAB = Length(xA, yA, xB, yB);
    double lengthAC = Length(xA, yA, xC, yC);
    double lengthAD = Length(xA, yA, xD, yD);

    cout << "Длина отрезка AB: " << lengthAB << endl;
    cout << "Длина отрезка AC: " << lengthAC << endl;
    cout << "Длина отрезка AD: " << lengthAD << endl;
}

int J(int n) {
    if (n / 7 > 2 && n == 0) {
        return n / 7;
    } else {
        return J(n % 7);
    }
}

int V(int p, int q) {
    int sum = 0;
    for (int i = p; i <= q; ++i) {
        sum += J(i);
    }
    return sum;
}

void task_6A() {
    int p, q;
    cout << "Введите значение p: ";
    cin >> p;
    cout << "Введите значение q: ";
    cin >> q;

    int result = V(p, q);
    cout << "Значение функции V(" << p << ", " << q << "): " << result << endl;

}

int countDivisors(int num, int divisor = 1) {
    if (divisor > num) {
        return 0;
    }

    if (num % divisor == 0) {
        return 1 + countDivisors(num, divisor + 1);
    } else {
        return countDivisors(num, divisor + 1);
    }
}

int sumOfDivisorCounts(int n) {
    if (n == 1) {
        return countDivisors(1);
    } else {
        return countDivisors(n) + sumOfDivisorCounts(n - 1);
    }
}

void task_6B() {
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    int result = sumOfDivisorCounts(n);
    cout << "Значение k(1) + k(2) + ... + k(" << n << "): " << result << endl;
}



