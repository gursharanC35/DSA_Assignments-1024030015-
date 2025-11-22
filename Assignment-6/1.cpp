#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) { data = val; prev = next = NULL; }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() { head = NULL; }

    void insertFirst(int val) {
        DNode* newNode = new DNode(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertLast(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found!\n"; return; }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found!\n"; return; }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev) temp->prev->next = newNode;
        else head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node " << key << " not found!\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node " << key << ".\n";
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) { data = val; next = NULL; }
};

class CircularList {
public:
    CNode* head;
    CircularList() { head = NULL; }

    void insertFirst(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) { head = newNode; head->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) { head = newNode; head->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    void deleteNode(int key) {
        if (head == NULL) return;
        CNode *temp = head, *prev = NULL;
        do {
            if (temp->data == key) {
                if (temp == head) {
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    if (head->next == head) head = NULL;
                    else { last->next = head->next; head = head->next; }
                } else prev->next = temp->next;
                delete temp;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    void search(int key) {
        if (head == NULL) { cout << "List empty.\n"; return; }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (head == NULL) { cout << "List is empty.\n"; return; }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyList dlist;
    CircularList clist;
    int choice, type, val, key;

    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Operate on Doubly Linked List\n";
        cout << "2. Operate on Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> type;

        if (type == 3) break;

        while (true) {
            cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After Node\n";
            cout << "4. Insert Before Node (Doubly only)\n5. Delete Node\n6. Search Node\n";
            cout << "7. Display\n8. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 8) break;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    if (type == 1) dlist.insertFirst(val);
                    else clist.insertFirst(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    if (type == 1) dlist.insertLast(val);
                    else clist.insertLast(val);
                    break;
                case 3:
                    cout << "Enter key (after which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> val;
                    if (type == 1) dlist.insertAfter(key, val);
                    else clist.insertAfter(key, val);
                    break;
                case 4:
                    if (type == 2) { cout << "Not available for circular list!\n"; break; }
                    cout << "Enter key (before which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> val;
                    dlist.insertBefore(key, val);
                    break;
                case 5:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    if (type == 1) dlist.deleteNode(val);
                    else clist.deleteNode(val);
                    break;
                case 6:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if (type == 1) dlist.search(val);
                    else clist.search(val);
                    break;
                case 7:
                    if (type == 1) dlist.display();
                    else clist.display();
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
    return 0;
}
