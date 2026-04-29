#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *arr;
    int size;

public:
    
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    
    void insertEnd(int value) {
        int *newArr = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Inserted " << value << " at end.\n";
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid position!\n";
            return;
        }

        int *newArr = new int[size + 1];

        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == index) {
                newArr[i] = value;
            } else {
                newArr[i] = arr[j++];
            }
        }

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Inserted " << value << " at index " << index << ".\n";
    }

    
    void deleteAt(int index) {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        if (index < 0 || index >= size) {
            cout << "Invalid position!\n";
            return;
        }

        int *newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                newArr[j++] = arr[i];
            }
        }

        cout << "Deleted element at index " << index << ".\n";

        delete[] arr;
        arr = newArr;
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    
    int countOccurrences(int value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                count++;
            }
        }
        return count;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;

    
    da.insertEnd(10);
    da.insertEnd(20);
    da.insertEnd(30);
    da.insertEnd(40);
    da.insertEnd(50);
    da.display();

    
    da.insertAt(2, 25);
    da.display();

    
    da.deleteAt(0);
    da.display();

    da.deleteAt(2);
    da.display();

    da.deleteAt(3);
    da.display();

    
    int pos = da.search(40);
    if (pos != -1)
        cout << "Element 40 found at index " << pos << endl;
    else
        cout << "Element not found\n";

    
    cout << "Occurrences of 20: " << da.countOccurrences(20) << endl;

    return 0;
}
