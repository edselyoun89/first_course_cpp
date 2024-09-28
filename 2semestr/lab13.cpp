#include <iostream>
#include <algorithm>

using namespace std;

const int ASCII_SIZE = 256; 

int DlinaStroki(const string& s) {
    int lastIndex[ASCII_SIZE];
    fill(lastIndex, lastIndex + ASCII_SIZE, -1);
    int maxLength = 0;
    int start = -1;

    for (int i = 0; i < s.length(); ++i) {
        if (lastIndex[static_cast<unsigned char>(s[i])] > start) {
            start = lastIndex[static_cast<unsigned char>(s[i])];
        }
        lastIndex[static_cast<unsigned char>(s[i])] = i;

        maxLength = max(maxLength, i - start);
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Введите строку: ";
    cin >> input;

    int length = DlinaStroki(input);
    cout << "Длина самой длинной подстроки без повторяющихся символов: " << length << endl;

    return 0;
}
