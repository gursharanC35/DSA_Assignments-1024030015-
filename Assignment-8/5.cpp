#include<iostream>
using namespace std;

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}
void heapify(int a[],int i,int n){
    while(true){
        int largest=i;
        int l=left(i);
        int r=right(i);

        if(l<n && a[l]>a[largest]){
            largest=l;
        }
        
        if(r<n && a[r]>a[largest]){
            largest=r;
        }
        
        if(largest == i)break;
        swap(a[largest],a[i]);
        i=largest;
    }
}

void buildmaxheap(int a[],int n){
    for (int i = (n/2)-1; i >= 0; i--)
    {
        heapify(a,i,n);
    }
    
}

void printArray(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}

int main(){
    int a[]={4,5,2,6,2,7,24,82,21,88};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"Before heapify : ";
    printArray(a,n);

    buildmaxheap(a,n);
    cout<<"After heapify : ";
    printArray(a,n);

    return 0;
}
