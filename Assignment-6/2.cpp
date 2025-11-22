#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int value){
        data=value;
        next=NULL;
    }

}*first=NULL;

void printList(){
    node *temp=first->next;
    cout<<first->data<<" ";
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=first);
    cout<<first->data;
}

int main(){
    first=new node(1);
    first->next=new node(2);
    first->next->next=new node(3);
    first->next->next->next=new node(4);
    first->next->next->next->next=new node(5);
    first->next->next->next->next->next=first;

    printList();

    return 0;
}
