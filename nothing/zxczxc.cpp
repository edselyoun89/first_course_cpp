#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void generateDotFile(const vector<vector<int> >& adjMatrix, int numVertices) {
    ofstream dotFile("graph.dot");

    if (!dotFile) {
        cout << "Ошибка при создании файла" << endl;
        return;
    }

    dotFile << "graph G {" << endl;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (adjMatrix[i][j] == 1) {
                dotFile << i << " -- " << j << ";" << endl;
            }
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
}

int main() {
    int numVertices;
    cout << "Введите количество вершин: ";
    cin >> numVertices;

    vector<vector<int> > adjMatrix(numVertices, vector<int>(numVertices));

    cout << "Введите матрицу смежности:" << endl;
    // Ввод матрицы смежности
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    generateDotFile(adjMatrix, numVertices);

    cout << "Файл graph.dot успешно создан." << endl;

    return 0;
}
