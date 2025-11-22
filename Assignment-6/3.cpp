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

int size(node *p){
    if(p==NULL){
        return 0;
    }

    int size=0;
    node *temp=p;
    do{
        size++;
        temp=temp->next;
    }while(temp!=first);

    return size;
}

int main(){
    first=new node(1);
    first->next=new node(2);
    first->next->next=new node(3);
    first->next->next->next=new node(4);
    first->next->next->next->next=new node(5);
    first->next->next->next->next->next=first;

    printList();
    cout<<endl;
    cout<<"Size of list : "<<size(first);

    return 0;
}
