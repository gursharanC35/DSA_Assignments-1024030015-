#include<iostream>
using namespace std;

int partition(int a[],int l,int h){
    int x=a[h];
    int i=l-1;

    for (int j = l; j <= h-1; j++)
    {
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}
void quickSort(int a[],int l,int h){
    if(l<h){
        int q=partition(a,l,h);
        quickSort(a,l,q-1);
        quickSort(a,q+1,h);
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

    quickSort(a,0,n-1);
    cout<<"Array after : "<<endl;
    printArray(a,n);

    return 0;
}
