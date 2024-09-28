#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string testString;

    cout << "Введите слово для проверки на палиндром: ";
    cin >> testString;

    clock_t start = clock();
    bool result = isPalindrome(testString);
    clock_t end = clock();

    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Результат: ";
    if (result) {
        cout << "Строка является палиндромом." << endl;
    } else {
        cout << "Строка не является палиндромом." << endl;
    }
    cout << "Время выполнения: " << elapsed_time << " секунд" << endl;

    return 0;
}
