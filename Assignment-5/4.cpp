#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *first = NULL;

void create(int arr[], int n) {
    if (n == 0) return;

    Node *last;
    for (int i = 0; i < n; i++) {
        Node *t = new Node;
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

void display(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverse() {
    Node *prev = NULL;
    Node *curr = first;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;         
        curr = next;         
    }

    first = prev; 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    create(arr, n);

    cout << "Original list: ";
    display(first);

    reverse();

    cout << "Reversed list: ";
    display(first);

    return 0;
}
