#include <iostream>

using namespace std;

template <typename T>
T calculateAverage(const T* array, size_t size) {
    T sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

int main() {
    srand(time(0));
    size_t size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size == 0) {
        cerr << "Ошибка: Размер массива должен быть больше 0" << endl;
        return 1;
    }

    double* array = new double[size];

    cout << "Введите элементы массива:" << endl;
    for (size_t i = 0; i < size; ++i) {
        cin >> array[i];
    }
    int* array1 = new int[size];
    for (size_t i = 0; i < size; ++i) {
        array1[i] = rand()%100;
        cout << array1[i] << " ";
    }
    cout << endl;
    double average = calculateAverage(array, size);
    cout << "Среднее значение double: " << average << endl;
    cout << "Среднее значение int: " << calculateAverage(array1, size) << endl;

    delete[] array;

    return 0;
}
