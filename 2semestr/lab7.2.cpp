#include <iostream>

using namespace std;

// Функция для обмена верхней и нижней половин матрицы
void swapUpperLower(int** matrix, int M, int N) {
    if (M % 2 != 0) {
        cout << "Количество строк нечетное. Невозможно выполнить операцию." << endl;
        return;
    }

    // Обмен верхней и нижней половин
    for (int i = 0; i < M / 2; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[M / 2 + i][j];
            matrix[M / 2 + i][j] = temp;
        }
    }
}

void printMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int M, N;
    cout << "Введите количество строк: ";
    cin >> M;
    cout << "Введите количество столбцов: ";
    cin >> N;

    int** matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        cout << "Введите элементы строки " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, M, N);

    swapUpperLower(matrix, M, N);

    cout << "Матрица после обмена верхней и нижней половин:" << endl;
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
