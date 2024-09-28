#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
T average(T* array, int size) {
    if (size == 0) {
        throw invalid_argument("Array size must be greater than zero");
    }

    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

template <typename T>
void inputArray(T* array, int size) {
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Array size must be greater than zero" << endl;
        return 1;
    }

    cout << "Enter the type of array (1 for int, 2 for float): ";
    int type;
    cin >> type;

    try {
        if (type == 1) {
            int* intArray = new int[n];
            inputArray(intArray, n);
            cout << "Average of intArray: " << average(intArray, n) << endl;
            delete[] intArray;
        } else if (type == 2) {
            float* floatArray = new float[n];
            inputArray(floatArray, n);
            cout << "Average of floatArray: " << average(floatArray, n) << endl;
            delete[] floatArray;
        } else {
            cerr << "Invalid type selected" << endl;
            return 1;
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
