#include <iostream>

using namespace std;

// Клас, що описує масив
template<typename T>
class Array {
private:
    T* data;
    int size;
public:
    // Конструктор з розміром масиву
    Array(int size) : size(size) {
        data = new T[size];
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Оператор індексування
    T& operator[](int index) {
        return data[index];
    }

    // Повертає розмір масиву
    int getSize() const {
        return size;
    }

    // Клас ітератора для масиву
    class ArrayIterator {
    private:
        T* ptr;
    public:
        // Конструктор з вказівником на початок масиву
        ArrayIterator(T* ptr) : ptr(ptr) {}

        // Оператор розіменування
        T& operator*() {
            return *ptr;
        }

        // Оператор інкременту
        ArrayIterator& operator++() {
            ++ptr;
            return *this;
        }

        // Оператор порівняння на нерівність
        bool operator!=(const ArrayIterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Повертає початковий ітератор масиву
    ArrayIterator begin() {
        return ArrayIterator(data);
    }

    // Повертає кінцевий ітератор масиву
    ArrayIterator end() {
        return ArrayIterator(data + size);
    }
};

int main() {
    // Створення масиву та заповнення його даними
    Array<int> arr(5);
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = i * 10;
    }

    // Прохід масиву за допомогою ітератора та виведення його елементів
    cout << "Array elements: ";
    for (Array<int>::ArrayIterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
