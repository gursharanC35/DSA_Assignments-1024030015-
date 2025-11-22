#include<iostream>
using namespace std;

class queue{
    int size;
    int front;
    int rear;
    int *q;

    public:

    queue(int x){
        size=x;
        front=-1;
        rear=-1;
        q=new int[size];
    }

    void inqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        rear++;
        q[rear]=x;
    }

    int dequeue(){
        int x=-1;
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return x;
        }
        front++;
        x=q[front+1];

        return x;
    }

    void display(){
        for (int i = front+1; i <= rear; i++){
            cout<<q[i]<<" ";
        }
    }

    bool isEmpty(){
        if(front == rear)
            return true;
        else 
            return false;
    }

    bool isFull(){
        if( rear == size-1)
            return true;
        else 
            return false;
    }
};

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    queue q1(n/2),q2(n/2);

    for (int i = 0; i < n/2; i++){
        q1.inqueue(arr[i]);
    }
    for (int i = n/2; i < n; i++){
        q2.inqueue(arr[i]);
    }
    
    for(int i=0; i<n; i++){
        if(i%2==0 && !q2.isEmpty()){
            cout<<q2.dequeue()<<" ";
        }
        else if(!q1.isEmpty()){
            cout<<q1.dequeue()<<" ";
        }

        }   
    return 0;
}
