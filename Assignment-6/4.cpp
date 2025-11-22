#include<iostream>
#include <cctype>
using namespace std;

class node{
    public:

    char data;
    node *next;
    node *prev;

    node(char value){
        data=value;
        next=prev=NULL;
    }
}*head=NULL;

void insertEnd(node *p,char c){
    if(p==NULL){
        head=new node(c);
        return;
    }

    while(p->next != NULL){
        p=p->next;
    }
    p->next=new node(c);
    p->next->prev=p;
}

bool isPalindrome() {
    if (head == NULL) return true;     
    node* tail = head;
    while (tail->next != NULL) tail = tail->next;

    if (head == tail) return true;       
    node* l = head;
    node* r = tail;

    while (l != r && l->prev != r) {
        if (l->data != r->data) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter a word : ";
    cin>>s;
   
    for (char ch : s) {
        insertEnd(head,tolower(ch));
    }
    
    if(isPalindrome()){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }

    return 0;
}
