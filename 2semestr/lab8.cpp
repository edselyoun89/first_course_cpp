#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;

const int MAX_STRING_LENGTH = 10; 
const int NUM_ITEMS = 5;

struct item {
    char data[MAX_STRING_LENGTH + 1];
    item* next;
};

void deleteList(item* head) {
    while (head != nullptr) {
        item* temp = head;
        head = head->next;
        delete temp;
    }
}

void RandomString(char* str, int maxLength) {
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = rand() % maxLength + 1; 
    for (int i = 0; i < length; ++i) {
        str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    str[length] = '\0'; 
}

int main() {
    srand(time(nullptr));

    item* head = new item;
    RandomString(head->data, MAX_STRING_LENGTH);
    head->next = nullptr;

    item* current = head;
    for (int i = 0; i < NUM_ITEMS - 1; ++i) {
        current->next = new item;
        current = current->next;
        RandomString(current->data, MAX_STRING_LENGTH);
        current->next = nullptr;
    }

    cout << "Список до удаления:" << endl;
    current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }

    deleteList(head);

    cout << "Список после удаления:" << endl;
    if (head == nullptr) {
        cout << "Список пуст" << endl;
    }

    return 0;
}
