#include<iostream>
#include <cstdio>
#include <math.h>
using namespace std;

/*int main()
{
    cout << "Один метр это:"<< endl;
    cout << "\t10 дм" << "\t100 см" << "\t1000 мм" << endl;
    cout << "Одна тонна это:"<< endl;
    cout << "\t10 ц" << "\t1000 кг" << endl;
    cout << "Один час это:"<< endl;
    cout << "\t60 мин"<< "\t3600 сек"<< endl;
}*/
/*nt main()
{
    char a,b,c,d;
    cout << "Сложение:";
    cin >> a;
    cout << "Вычитание:";
    cin >> b;
    cout << "Умножение:";
    cin >> c;
    cout << "Деление:";
    cin >> d;
    cout << "Сложение: " << a << "\tВычитание: " << b <<"\nУмножение: " << c << "\tДеление: " << d << endl;
    return 0;
    
}*/
/*int main()
{
    int x = 65530;
    int y = 10;
    x = x + y;
    cout << "65530+10= "<< x;
    cin.get();
    return 0;
}*/
/*int main()
{
    cout << "size of char = " << sizeof(char) << "\n";
    cout << "size of short = " << sizeof(short)<<"\n";
    cout << "size of int = " << sizeof(int)<<"\n";
    cout << "size of float = " << sizeof(float) <<"\n";
    cout << "size of double = " << sizeof(double) <<"\n";
}*/
/*int main()
{
    string first, last;
    int months;
    cout << "Введите имя: ";
    cin >> first;
    cout << "Введите фамилию: ";
    cin >> last;
    cout << "Количество прожитых месяцев: ";
    cin >> months;
    int years = months / 12;
    cout << first[0] << ". " << last << endl;
    cout << "Возраст: " << years<< " лет" << endl;
    return 0;
}*/
/*int main()
{
    int z = 160;
    int x = 50;
    int c = 40;
    int w = z * x * c;
    double bytes = w * sizeof(char);
    double kilobytes = bytes / 1024;
    double megabytes = kilobytes / 1024;
    cout << "Вес книги:" << endl;
    cout << "Байты: " << bytes << endl;
    cout << "Килобайты: " << kilobytes << endl;
    cout << "Мегабайты: " << megabytes << endl;
    return 0;
}*/
/*int main() {

    int a, b;
    cout << "Введите число A: ";
    cin >> a;
    cout << "Введите число B: ";
    cin >> b;

    int count = a / b;

    cout << "Количество отрезков B, размещенных на отрезке A: " << count << endl;

    return 0;
}*/
/*int main() {
    int x;
    double y;
    int Cubes = 0;
    double Weigth = 0;

    cout << "Количество слоев: ";
    cin >> x;
    cout << "Вес одного кубика: ";
    cin >> y;

    for (int i = 1; i <= x; i++) {
        int z = i * i;
        Cubes += z;
        Weigth += z * y;
    }
    cout << "Общее число кубиков: " << Cubes << endl;
    cout << "Суммарный вес кубиков: " << Weigth << endl;
    return 0;
}*/

/*int main()
{
bool A, B, C;
    cout << "Введите значение переменной A: ";
    cin >> A;
    cout << "Введите значение переменной B: ";
    cin >> B;
    cout << "Введите значение переменной C: ";
    cin >> C;

    bool r1 = !A || B;
    cout << "Значение r1: " << r1 << endl;
    bool r2 = !C && B;
    cout << "Значение r2: " << r2 << endl;
    bool r3 = A || (B || C);
    cout << "Значение r3: " << r3 << endl;
    bool r4 = A && !(B || C);
    cout << "Значение r4: " << r4 << endl;
    return 0;

}*/

 /*int main()
 {
    int x;
    cout << "Введите значение x: ";
    cin >> x;
    
    bool a = !(x > 0 and x < 5);
    cout << "Значение выражения а: " << a << endl;
    
    bool b = (x > 10) and (x <= 20);
    cout << "Значение выражения b: " << b << endl;
    
    return 0;
 }*/


/*int main()
{
    int number;
    cout << "Введите четырехзначное число: ";
    cin >> number;
    
    int n1 = number / 1000;
    int n2 = (number / 100) % 10;
    int n3 = (number / 10) % 10;
    int n4 = number % 10;
    
    if ((n1 == n4) and (n2 == n3)) {
        cout << "The above statement is true." << endl;
    } else {
        cout << "The above statement is false." << endl;
    }
    return 0;
}*/




/*int main() {
    int num;
    cout << "Введите двузначное число: ";
    cin >> num;

    if (num >= 10 and num <= 99) {
        int d1 = num / 10;  
        int d2 = num % 10;
        int sum = d1 + d2;
        int a;
        cout << "Сумма цифр числа: " << sum << endl;

        if (sum >= 10) {
            cout << "Сумма цифр является двузначным числом" << endl;
        } else {
            cout << "Сумма цифр не является двузначным числом" << endl;
        }
        cout << "Введите число a" << endl;
        cin >> a;
        if (a > sum) {
            cout << "Число больше суммы его цифр" << endl;
        } else {
            cout << "Число не больше суммы его цифр" << endl;
        }
    } else {
        cout << "Введено недопустимое число. Введите двузначное число." << endl;
    }

    return 0;
}*/

/*int main() {
    int a, b, c;
    cout << "Введите длины сторон треугольника: ";
    cin >> a >> b >> c;

    if (a == b || a == c || b == c) {
        cout << "Треугольник является равнобедренным" << endl;
    } else {
        cout << "Треугольник не является равнобедренным" << endl;
    }

    return 0;
}*/

int main() {
    int k;
    cout << "Введите номер дня (1-365): ";
    cin >> k;

    int first = 1;
    int current = (first + k - 1) % 7;

    if (current == 0 or current == 6) {
        cout << "Выходной день" << endl;
    } else {
        cout << "Рабочий день" << endl;
    }

    return 0;
}


float performAction(int action, float a, float b) {
    float result;
    switch (action) {
        case 1:  
            result = a + b;
            break;
        case 2:  
            result = a - b;
            break;
        case 3: 
            result = a * b;
            break;
        case 4:  
            result = a / b;
            break;
        default:
            cout << "Недопустимый номер действия." << endl;
            break;
    }
    return result;
}

/*int main() {
    int N;
    float A, B;
    cout << "Введите номер действия (1-4): ";
    cin >> N;
    cout << "Введите первое число: ";
    cin >> A;
    cout << "Введите второе число (не равное 0): ";
    cin >> B;

    float result = performAction(N, A, B);

    cout << "Результат: " << result << endl;

    return 0;
}*/
