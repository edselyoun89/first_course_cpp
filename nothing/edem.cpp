// Лр 15 Вариант 6
#include <iostream> 
#include <ctime> 
 
using namespace std; 
void rekur(int n, char from, char to, char aux) 
{ 
    if (n == 1) 
    { 
    cout << "Переместить диск 1 с стержня " << from << " на стержень " << to << endl; 
    return; 
    } 
    rekur(n - 1, from, aux, to); 
    cout << "Переместить диск " << n << " с стержня " << from << " на стержень " << to << endl; 
    rekur(n - 1, aux, to, from); 
} 
 
int countZeros(int n) 
{ 
    int count = 0; 
    while ((n & 1) == 0) 
    { 
    n >>= 1; 
    ++count; 
    } 
    return count; 
} 
void iter(int n) { 
    int* position = new int[n + 1]; 
    for (int i = 1; i <= n; i++) 
    { 
    position[i] = 1; 
    } 
 
    int from_peg = 0, to_peg = 0; 
    int m = 1 << n; //2^n 
    for (int i = 1; i < m; i++) 
    { 
    int disk = countZeros(i) + 1; // определение номера диска, который нужно переместить 
    if ((disk & 1) == (n & 1)) 
    { 
    from_peg = position[disk]; 
    to_peg = position[disk] = position[disk] % 3 + 1; 
    } 
    else 
    { 
    from_peg = position[disk]; 
    to_peg = position[disk] = (position[disk] + 1) % 3 + 1; 
    } 
    cout << "Переместить диск " << disk << " со стержня " << from_peg << " на стержень " << to_peg << endl; 
    } 
    delete[] position; 
} 
 
int main() 
{ 
    clock_t start = clock(); 
    setlocale(LC_ALL, "Russian"); 
    cout << "Рекурсия: " << endl; 
    int n = 3; // количество дисков 
 
    rekur(n, 'A', 'C', 'B'); // A, B и C - это имена стержней 
    clock_t end = clock(); 
    double elapsed_time = static_cast <double> (end - start) / CLOCKS_PER_SEC; 
    cout << "Время выполнения: " << elapsed_time << " секунд" << endl; 
    cout << "Итерация: " << endl; 
    iter(n); 
    end = clock(); 
    elapsed_time = static_cast <double> (end - start) / CLOCKS_PER_SEC; 
    cout << "Время выполнения: " << elapsed_time << " секунд" << endl; 
    return 0; 
}