#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter position to insert : ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position."<<endl;
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;

    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val;
    n++;

    cout << "Element inserted successfully."<<endl;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete : ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully.\n";
}

void linearSearch(int arr[], int n) {
    int el, found = 0;
    cout << "Enter value to search: ";
    cin >> el;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el) {
            cout << "Element found at position " << i + 1 <<endl;
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int arr[100], n = 0, choice;

    do {
        cout << "==MENU=="<<endl;
        cout << "1. CREATE"<<endl;
        cout << "2. DISPLAY"<<endl;
        cout << "3. INSERT"<<endl;
        cout << "4. DELETE"<<endl;
        cout << "5. LINEAR SEARCH"<<endl;
        cout << "6. EXIT"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                insertElement(arr, n);
                break;
            case 4:
                deleteElement(arr, n);
                break;
            case 5:
                linearSearch(arr, n);
                break;
            case 6:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice! Try again."<<endl;
        }
    } while (choice != 6);

    return 0;
}
