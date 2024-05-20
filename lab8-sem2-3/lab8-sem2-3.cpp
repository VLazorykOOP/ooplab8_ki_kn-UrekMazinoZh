#include <iostream>

using namespace std;

// ����� �����'������ ������
template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}
};

// ���� �����'������ ������
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // �����������
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // ����������
    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // ��������� �������� � ����� ������
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

    // ��������� �������� � ������� ������
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

    // ��������� ������ ������
    int getSize() const {
        return size;
    }

    // ��������� ������
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
    // ���������������� ���� �����'������ ������ � ����� int
    DoublyLinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);
    cout << "Int List: ";
    intList.display(); 

    // ���������������� ���� �����'������ ������ � ����� char
    DoublyLinkedList<char> charList;
    charList.append('a');
    charList.append('b');
    charList.append('c');
    cout << "Char List: ";
    charList.display(); 

    return 0;
}
