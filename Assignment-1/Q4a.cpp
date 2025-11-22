// Reverse the elements of an array 
#include<iostream>
using namespace std;

void reverse(int arr[],int &n){
    int buffer;
    for(int i=0; i<n/2; i++){
        buffer = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-1-i] = buffer;
    }

    cout<<"Reversed array is : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n,arr[100];

    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter elements of array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    reverse(arr,n);

    return 0;

}
