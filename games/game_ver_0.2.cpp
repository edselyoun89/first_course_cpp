#include <iostream>
#include <vector>

// Класс для представления клетки океана
class Cell {
public:
    enum class State { EMPTY, OCCUPIED };

    Cell(State state = State::EMPTY) : state(state) {}

    State getState() const { return state; }
    void setState(State newState) { state = newState; }

private:
    State state;
};

// Класс для представления окрестности клетки
class Neighbourhood {
public:
    Neighbourhood() {}

    void addCell(const Cell& cell) {
        cells.push_back(cell);
    }

    // Дополнительные методы для работы с клетками окрестности

private:
    std::vector<Cell> cells;
};

// Класс для представления океана
class Ocean {
public:
    Ocean(size_t r, size_t c) : rows(r), cols(c), data(r * c) {}

    Neighbourhood generateNeighbourhood(size_t i, size_t j, size_t r) {
        Neighbourhood neighbourhood;

        // Генерация окрестности для клетки с координатами (i, j) радиуса r

        return neighbourhood;
    }

    void tick() {
        // Проход по всем клеткам океана и выполнение необходимых действий на каждой итерации
    }

private:
    size_t rows, cols;
    std::vector<Cell> data;
};

int main() {
    size_t width, height;
    std::cout << "Enter width of the ocean: ";
    std::cin >> width;
    std::cout << "Enter height of the ocean: ";
    std::cin >> height;

    Ocean ocean(width, height);

    // Здесь можно добавить код для инициализации и запуска симуляции

    return 0;
}
