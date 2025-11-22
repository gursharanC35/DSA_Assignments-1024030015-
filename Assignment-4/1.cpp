// Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include<iostream>
using namespace std;

class queue{
    private:
    int size;
    int front;
    int rear;
    int *q;

    public:
    queue(int size);
    ~queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
    int peek();
};

queue::queue(int x){
    size=x;
    front=-1;
    rear=-1;
    q=new int[size];
};

queue::~queue(){
    delete []q;
}

void queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        q[rear]=x;
    }
}

int queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
        return x; 
    }
    else{
        front++;
        x=q[front+1];
    }
}

bool queue::isEmpty(){
    if(front == rear)
        return true;
    else 
    return false;
}

bool queue::isFull(){
    if( rear == size-1)
        return true;
    else 
    return false;
}

int queue::peek(){
    if (isEmpty()){
        cout << "Queue underflow" << endl;
        return -1;
    }
    return q[front];
}

void queue::display(){
    for (int i = front+1; i <= rear; i++){
        cout<<q[i]<<" ";
    }
    
}


int main(){
    int n,choice,x;
    cout<<"Enter size of queue : ";
    cin>>n;

    queue q(n);

    do{
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Checking if Empty\n";
        cout << "6. Checking if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                if(q.isEmpty()) 
                cout << "Queue is empty\n";
                else 
                cout << "Queue is not empty\n";
                break;
            case 6:
                if(q.isFull())
                cout << "Queue is full\n";
                else 
                cout << "Queue is not full\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
    
}
