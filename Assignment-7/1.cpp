#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    int minindex,temp;
    for (int i = 0; i < n-1; i++)
    {   
        minindex=i;
        for (int j = i+1; j < n; j++)
        {
                if(a[j]<a[minindex]){
                minindex=j;
            }
        }
        if(minindex!=i){
            temp=a[i];
            a[i]=a[minindex];
            a[minindex]=temp;
        }
        
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

    selectionSort(a,n);
    cout<<"Array after : "<<endl;
    printArray(a,n);

    return 0;
}
