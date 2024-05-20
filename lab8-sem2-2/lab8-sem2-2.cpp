#include <iostream>

using namespace std;

// Функція-шаблон для сортування методом Шелла
template <typename T>
void shellSort(T array[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            T temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

// Специфікація для типу char*
template <>
void shellSort(char* array[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            char* temp = array[i];
            int j;
            for (j = i; j >= gap && strcmp(array[j - gap], temp) > 0; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    int intArray[] = { 12, 8, 45, 6, 32, 10 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    shellSort(intArray, intSize);
    cout << "After sorting: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    const char* strArray[] = { "banana", "apple", "orange", "grape", "pineapple" };
    int strSize = sizeof(strArray) / sizeof(strArray[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < strSize; ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;

    shellSort(strArray, strSize);

    cout << "After sorting: ";
    for (int i = 0; i < strSize; ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;

    return 0;
}
