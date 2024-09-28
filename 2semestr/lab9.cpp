#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* insertionSort(Node* head) {
    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        if (sorted == nullptr || sorted->data >= current->data) {
            // Вставляем текущий узел в начало отсортированного списка
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }   
            // Вставляем текущий узел после узла temp
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    return sorted;
}

void append(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    srand(time(0));
    Node* head = nullptr;
    const int numElements = 5;
    for (int i = 0; i < numElements; ++i) {
        int randomValue = rand() % 100;
        append(head, randomValue);
    }

    cout << "Исходный список: ";
    printList(head);

    head = insertionSort(head);

    cout << "Отсортированный список: ";
    printList(head);

    deleteList(head);

    return 0;
}
