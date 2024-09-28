#include <iostream>

// Определение узла односвязного списка
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

// Функция для добавления нового элемента в конец списка
void append(Node*& head, int value) {
    if (!head) {
        head = new Node(value);
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
    }
}

// Функция для поиска элемента в списке
Node* find(Node* head, int value) {
    Node* current = head;
    while (current) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Введите количество элементов в списке: ";
    cin >> n;

    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        append(head, value);
    }

    int searchValue;
    cout << "Введите значение для поиска: ";
    cin >> searchValue;

    // Поиск элемента
    Node* node = find(head, searchValue);
    if (node) {
        cout << "Элемент найден: " << node->value << endl;
    } else 
        cout << "Элемент не найден" << endl;
    }

    return 0;
}