#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

// Вспомогательные функции
Point nextToTop(stack<Point>& S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Определяем ориентацию: 0 = коллинеарные, 1 = по часовой стрелке, 2 = против часовой стрелки
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Сравнение для сортировки точек по полярному углу
bool compare(Point p1, Point p2, Point p0) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);
    return o == 2;
}

// Функция для построения выпуклой оболочки
void convexHull(vector<Point>& points, int n) {
    // Найти точку с наименьшей координатой y (если таких несколько, выбрать с наименьшей x)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Поместить точку с минимальной координатой y на первую позицию
    swap(points[0], points[min]);

    // Сортировать точки по полярному углу относительно первой точки
    Point p0 = points[0];
    sort(points.begin() + 1, points.end(), [p0](Point p1, Point p2) {
        return compare(p1, p2, p0);
    });

    // Создать стек и поместить туда первые три точки
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Обработать остальные точки
    for (int i = 3; i < n; i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Вывести результаты
    cout << "Convex Hull is:" << endl;
    vector<Point> hull;
    while (!S.empty()) {
        hull.push_back(S.top());
        S.pop();
    }

    // Вывод точек в нужном порядке
    for (int i = hull.size() - 1; i >= 0; i--) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    convexHull(points, n);
    return 0;
}
