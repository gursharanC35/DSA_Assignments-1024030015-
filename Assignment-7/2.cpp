#include<iostream>
using namespace std;

void insertionSort(int a[],int n){

    for(int i=1;i<n;i++){
        int index=i;
        int temp=a[i];
        while(index>0 && temp < a[index - 1]){
            a[index]=a[index-1];
            index--;
        }
        a[index]=temp;
    }
}

void printArray(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int a[]={3,5,2,7,4,7,5,3,5,6};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"Array before : "<<endl;
    printArray(a,n);

    insertionSort(a,n);
    cout<<"Array after : "<<endl;
    printArray(a,n);

    return 0;
}
