#include <iostream>

using namespace std;

// Вузол двозв'язного списку
template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}
};

// Клас двозв'язного списку
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // Конструктор
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Деструктор
    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Додавання елементу в кінець списку
    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Видалення елементу з початку списку
    void removeFront() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    // Отримання розміру списку
    int getSize() const {
        return size;
    }

    // Виведення списку
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Параметризований клас двозв'язного списку з типом int
    DoublyLinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);
    cout << "Int List: ";
    intList.display(); 

    // Параметризований клас двозв'язного списку з типом char
    DoublyLinkedList<char> charList;
    charList.append('a');
    charList.append('b');
    charList.append('c');
    cout << "Char List: ";
    charList.display(); 

    return 0;
}
