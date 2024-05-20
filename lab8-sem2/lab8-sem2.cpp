#include <iostream>
#include <cstring> 

using namespace std;

// �������-������ ��� ����������� ������������� �������� � ����� �� �� �������
template <typename T>
void findMaxAndCount(const T array[], int size, T& maxVal, int& count) {
    maxVal = array[0]; 
    count = 1; 

    for (int i = 1; i < size; ++i) {
        if (array[i] > maxVal) { // ���� �������� ������� ������ �� ������� ����������� ��������
            maxVal = array[i]; 
            count = 1; 
        }
        else if (array[i] == maxVal) { // ���� �������� ������� ������� ������������� ��������
            count++; 
        }
    }
}

// ������������ ��� ���� char*
template <>
void findMaxAndCount(const char* const array[], int size, const char*& maxVal, int& count) {
    maxVal = array[0]; 
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (strlen(array[i]) > strlen(maxVal)) { // ��������� ����� �� �� ��������
            maxVal = array[i];
            count = 1;
        }
        else if (strlen(array[i]) == strlen(maxVal)) {
            count++;
        }
    }
}

int main() {
    int intArray[] = { 1, 2, 3, 3, 2, 4, 5, 5, 5 };
    int maxInt, intCount;

    findMaxAndCount(intArray, 9, maxInt, intCount);
    cout << "Max value in intArray: " << maxInt << ", Count: " << intCount << endl;

    const char* strArray[] = { "apple", "banana", "orange", "banana", "grapefruit", "orange" };
    const char* maxStr;
    int strCount;

    findMaxAndCount(strArray, 6, maxStr, strCount);
    cout << "Max value in strArray: " << maxStr << ", Count: " << strCount << endl;

    return 0;
}
