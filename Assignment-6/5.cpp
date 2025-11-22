#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool isCircular(Node* head) {
    if (head == NULL)
        return false; 

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

bool isCircular1(Node* head) {
    if (!head) return false;
    Node *slow = head, *fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}


int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->next->next = head;

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}
