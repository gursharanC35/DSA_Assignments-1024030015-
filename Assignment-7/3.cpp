#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){

    for(int i=0;i<n-1;i++){
        bool skip=true;
        for (int j = 0; j < n-i-1; j++)
        {   
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                skip=false;
            }
        }
        if(skip){
            break;
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

    bubbleSort(a,n);
    cout<<"Array after : "<<endl;
    printArray(a,n);

    return 0;
}
