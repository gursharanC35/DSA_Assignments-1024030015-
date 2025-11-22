#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int h){
    int b[h+1];
    int i=l,j=mid+1,k=l;

    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }

    for(;i<=mid;i++){
        b[k++]=a[i];
    }
    
    for(;j<=h;j++){
        b[k++]=a[j];
    }

    for (int i = l; i <= h; i++)
    {
        a[i]=b[i];
    }
    
}
void mergeSort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
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

    mergeSort(a,0,n-1);
    cout<<"Array after : "<<endl;
    printArray(a,n);

    return 0;
}
