// Upper triangular Matrix.  

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix : ";
    cin >> n;

    int size = n*(n+1)/2;  
    int lower[size];

    cout << "Enter "<<size<<" elements of lower triangular matrix row-wise: ";
    for (int i = 0; i < size; i++) {
        cin >> lower[i];
    }

    int index=0;
    cout << "Lower triangular matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << lower[index] << " ";
                index++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
