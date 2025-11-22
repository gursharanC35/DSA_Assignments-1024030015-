// Tri-diagonal Matrix

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = 3*n - 2; 
    int tri[size];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(abs(i-j)<=1){
                cout<<"Enter the values:"<<i<<" "<<j<<endl;
                cin>>tri[i][j];
            }
        }
    }

    cout << "\nTri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << tri[n-1 + i] << " "; 
            }
            else if (i == j+1) {
                cout << tri[i-1] << " ";   
            }
            else if (i+1 == j) {
                cout << tri[2*n-1 + i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
