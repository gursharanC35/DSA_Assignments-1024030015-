// Write a program to find sum of every row and every column in a two-dimensional 
// array. 

#include<iostream>
using namespace std;

int main(){
    int m,n,rowSum=0,colSum=0,arr[100][100]={0};

    cout<<"Enter number of rows and columns in the array : ";
    cin>>m>>n;
     
    cout<<"Enter the elements in the array : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Sum of rows of array : "<<endl;
    for(int i=0; i<m; i++){
        rowSum=0;
        for(int j=0; j<n; j++){
            rowSum += arr[i][j];
        }
        cout<<"Sum of row "<<i+1<<" is : "<<rowSum<<endl;
    }

    cout<<"Sum of columns of array : "<<endl;
    for(int i=0; i<n; i++){
        colSum=0;
        for(int j=0; j<m; j++){
            colSum += arr[j][i];
        }
        cout<<"Sum of column "<<i+1<<" is : "<<colSum<<endl;
    }

    return 0;

}
