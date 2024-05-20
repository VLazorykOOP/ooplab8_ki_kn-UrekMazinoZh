#include <iostream>

using namespace std;

// ����, �� ����� �����
template<typename T>
class Array {
private:
    T* data;
    int size;
public:
    // ����������� � ������� ������
    Array(int size) : size(size) {
        data = new T[size];
    }

    // ����������
    ~Array() {
        delete[] data;
    }

    // �������� ������������
    T& operator[](int index) {
        return data[index];
    }

    // ������� ����� ������
    int getSize() const {
        return size;
    }

    // ���� ��������� ��� ������
    class ArrayIterator {
    private:
        T* ptr;
    public:
        // ����������� � ���������� �� ������� ������
        ArrayIterator(T* ptr) : ptr(ptr) {}

        // �������� ������������
        T& operator*() {
            return *ptr;
        }

        // �������� ����������
        ArrayIterator& operator++() {
            ++ptr;
            return *this;
        }

        // �������� ��������� �� ��������
        bool operator!=(const ArrayIterator& other) const {
            return ptr != other.ptr;
        }
    };

    // ������� ���������� �������� ������
    ArrayIterator begin() {
        return ArrayIterator(data);
    }

    // ������� ������� �������� ������
    ArrayIterator end() {
        return ArrayIterator(data + size);
    }
};

int main() {
    // ��������� ������ �� ���������� ���� ������
    Array<int> arr(5);
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = i * 10;
    }

    // ������ ������ �� ��������� ��������� �� ��������� ���� ��������
    cout << "Array elements: ";
    for (Array<int>::ArrayIterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
