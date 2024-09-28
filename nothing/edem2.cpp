//ЛР 16-17 Вариант 6
#include <iostream>
 
using namespace std;
 
// Шаблон функции для поиска минимального элемента в массиве
template <typename T>
T findMin(const T arr[], int size) {
    if (size <= 0) {
        cout << "Массив пуст!" << endl;
        return 0;
    }
    T minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return minElement;
}
 
int main() {
    // Примеры использования шаблона функции
    int intArray[] = {5, 2, 8, 1, 10};
    cout << "Минимальный элемент в массиве целых чисел: " << findMin(intArray, sizeof(intArray) / sizeof(intArray[0])) << endl;
 
    char charArray[] = {'a', 'z', 'b', 'c'};
    cout << "Минимальный элемент в массиве символов: " << findMin(charArray, sizeof(charArray) / sizeof(charArray[0])) << endl;
 
    string stringArray[] = {"milk", "apple", "banana", "cherry"};
    cout << "Минимальный элемент в массиве строк: " << findMin(stringArray, sizeof(stringArray) / sizeof(stringArray[0])) << endl;
 
    return 0;
}