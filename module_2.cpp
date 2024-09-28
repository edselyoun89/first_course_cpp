#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
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
    return 0;
}

/*int main() {
    const int SIZE = 100; // Максимальный размер массива символов
    char arr[SIZE];
    int count = 0; // Счетчик гласных букв

    cout << "Введите массив символов: ";
    cin.getline(arr, SIZE);

    // Проверяем каждый символ в массиве
    for (int i = 0; arr[i] != '\0'; i++) {
        // Преобразуем символ к верхнему регистру, чтобы учесть и заглавные и строчные гласные буквы
        char c = toupper(arr[i]);

        // Проверяем, является ли символ гласной буквой
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    std::cout << "Количество гласных букв: " << count << std::endl;

    return 0;
}*/