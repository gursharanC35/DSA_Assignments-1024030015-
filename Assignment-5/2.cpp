#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
} *first = NULL;

// Create linked list from array
void create(int arr[], int n) {
    if (n == 0) return;

    node *last;
    for (int i = 0; i < n; i++) {
        node *t = new node;
        t->data = arr[i];
        t->next = NULL;
        if (i == 0) {
            first = t;
            last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

// Display list
void display(node *p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void deleteAll(int key);
// Count occurrences of key
int searchCount(int key){
    node *temp=first;
    int count=0;

    while(temp != NULL){
        if(temp->data == key){
            count++;
        }
        temp=temp->next;
    }
    return count;
}

// Delete all occurrences of key
// void deleteAll(int key) {
//     // delete nodes at the beginning
//     while (first != NULL && first->data == key) {
//         node *t = first;
//         first = first->next;
//         delete t;
//     }

//     // delete nodes after the head
//     node *temp = first;
//     while (temp != NULL && temp->next != NULL) {
//         if (temp->next->data == key) {
//             node *q = temp->next;
//             temp->next = q->next;
//             delete q;
//         } else {
//             temp = temp->next;
//         }
//     }
// }

// void reverse(){
//     node *prev=NULL,*curr=first,*next=NULL;
//     while(curr){
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     first=prev;
// }

void deleteAll(int key){
    while(first!=NULL && first->data==key){
        node *p=first;
        first=first->next;
        delete p;
    }
    node *temp=first;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->data==key){
            node *t=temp->next;
            temp->next=t->next;
            delete t;
        }
        else{
            temp=temp->next;
        }
    }

}

int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    create(arr, n);

    cout << "Original list: ";
    display(first);

    int key;
    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = searchCount(key);
    cout << "Key " << key << " occurred " << count << " times." << endl;

    deleteAll(key);
    cout << "List after deleting all occurrences of " << key << ": ";
    display(first);

    return 0;
}
