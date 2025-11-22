//Binary search
#include<iostream>
using namespace std;

int main(){
    int n, end, beg, el, mid;
    bool found=false;
    int arr[100];
 
    cout<<"Enter no of elements in the array : ";
    cin>>n;

    cout<<"Enter elements in ascending order in the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the target element : ";
    cin>>el;

    beg=0,end=n-1;
    
    while(beg<=end){
        mid = (beg+end)/2;

        if(arr[mid] == el){
            found = true;
            break;
        }
        else if(arr[mid] > el){
            end=mid-1;
        }
        else if(arr[mid] < el){
            beg=mid+1;
        }
    }

    if(found){
        cout<<"Element found at "<<mid+1<<" position in array.";
    }
    else{
        cout<<"Element not found in the array.";
    }

    return 0;

}
