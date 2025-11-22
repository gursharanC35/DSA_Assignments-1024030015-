#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    int arr[100];

    cout << "Enter elements of array :";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int invCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }

    cout << "Number of inversions: " << invCount << endl;
    return 0;

}
