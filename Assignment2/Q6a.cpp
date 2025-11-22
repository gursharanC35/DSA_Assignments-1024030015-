// Transpose of a matrix

#include<iostream>
using namespace std;

int main(){
    int m,n,arr[100][100],transpose[100][100];;
    
    cout<<"Enter number of rows and columns in the array : ";
    cin>>m>>n;

    cout<<"Enter elements in the array :";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            transpose[j][i]=arr[i][j];
        }
    }

    cout<<"Transpose of the given array is : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
