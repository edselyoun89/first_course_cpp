#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;

void task_1();

void NewFunction();

int main()
{
    task_1();
    return 0;
}

void task_1() {
    ifstream inputFile("zxc.txt");    
    ofstream outputFile("qwe.txt");

    char ch;
    while (inputFile.get(ch)) {
        if (!ispunct(ch) && !isspace(ch)) {
            outputFile.put(ch);
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Знаки препинания удалены" <<endl;
}

