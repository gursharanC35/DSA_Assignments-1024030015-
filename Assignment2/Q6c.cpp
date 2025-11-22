// Find the matrix multiplication 

#include<iostream>
using namespace std;

int main(){
    int m,n,p;
    int arr1[100][100]={0},arr2[100][100]={0},arr[100][100]={0};
    cout<<"Enter numbers of rows and columns in first array : ";
    cin>>m>>n;
    
    cout<<"Enter elements in first array : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr1[i][j];
        }
    }

    cout<<"Enter number of columns in second array : ";
    cin>>p;

    cout<<"Enter elements in second array : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
            cin>>arr2[i][j];
        }
    }


    for (int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < p ; j++){
            for(int k = 0 ; k < n ; k++)
            arr[i][j] += arr1[i][k]*arr2[k][j];
        }
    }
    
    cout<<"Mutplication of both the matrices is : "<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
