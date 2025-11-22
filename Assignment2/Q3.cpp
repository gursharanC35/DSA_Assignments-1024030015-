//3) Design the Logic to Find a Missing Number in a Sorted Array. 


#include<iostream>
using namespace std;

int main(){
    int n,arr[100],num;

    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter elements of array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Missing number : ";
    for(int i=0; i<n-1; i++){
        while(arr[i+1] != arr[i]+1){
            cout<<arr[i]+1<<" ";
            arr[i]++;
        }
    }

    return 0;
}
