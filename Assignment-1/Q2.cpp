#include<iostream>
using namespace std;

 void duplicate(int arr[],int &n){
    int i=0;
    while(i<n-1){
        for(int j=i+1; j<n; ){
            if(arr[i] == arr[j]){
                for(int k=j; k<n; k++){
                arr[k] = arr [k+1];
                }
                n--;
            }
            else j++;
        }
        i++;
    }
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

}

int main(){
    int n,i=0,arr[100]={0};

    cout<<"Enter size of array : "<<endl;
    cin>>n;

    cout<<"Enter elements of aray : "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    duplicate(arr,n);

    return 0;
}
