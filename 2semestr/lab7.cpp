#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int countMultiplesOfThree(const int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            count++;
        }
    }
    return count;
}

const int* findMinNegativeAddress(const int arr[], int n) {
    const int* minAddress = nullptr;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (!minAddress || arr[i] < *minAddress) {
                minAddress = &arr[i];
            }
        }
    }
    return minAddress;
}

int main() {
    const int maxSize = 100; // Максимальный размер массива
    int numbers[maxSize]; // Массив для хранения введенных чисел
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    srand(time(0));
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        numbers[i]=rand()%100-50;
        cout << numbers[i] << " ";
    
    }
    cout << '\n';

    bubbleSort(numbers, size);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int count = countMultiplesOfThree(numbers, size);
    cout << "Количество элементов, кратных трём: " << count << endl;

    const int* minNegativeAddress = findMinNegativeAddress(numbers, size);
    if (minNegativeAddress != nullptr) {
        cout << "Адрес минимального отрицательного элемента: " << minNegativeAddress << endl;
    } else {
        cout << "Отрицательных элементов не найдено." << endl;
    }

    return 0;
}

