#include <iostream>
using namespace std;

template <class T>
T Max(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <class T>
void reverse(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;

    cout << "Select Data Type:";
    cout << "\n1. Integer\n2. Float\n3. Character\nChoice: ";
    cin >> choice;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (choice == 1) {
        int arr[50];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Maximum: " << Max(arr, n) << endl;

        reverse(arr, n);
        cout << "Reversed: ";
        display(arr, n);
    }

    else if (choice == 2) {
        float arr[50];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Maximum: " << Max(arr, n) << endl;

        reverse(arr, n);
        cout << "Reversed: ";
        display(arr, n);
    }

    else if (choice == 3) {
        char arr[50];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Maximum: " << Max(arr, n) << endl;

        reverse(arr, n);
        cout << "Reversed: ";
        display(arr, n);
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}
