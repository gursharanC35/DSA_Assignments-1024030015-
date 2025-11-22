#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int *a;

public:
    Stack() {
        cout << "Enter size of stack: ";
        cin >> size;
        top = -1;
        a = new int[size];
    }

    ~Stack() {
        delete[] a;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << a[i] << endl;
        }
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            a[++top] = x;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return a[top--];
        }
    }

    int peek(int pos) {
        int index = top - pos + 1;
        if (index < 0 || index > top) {
            cout << "Invalid position\n";
            return -1;
        } else {
            return a[index];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    int stackTop() {
        if (isEmpty()) return -1;
        return a[top];
    }
};

int main() {
    Stack st;
    int choice, value, pos;

    do {
        cout << "\n---MENU---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Stack Top\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;

        case 2:
            value = st.pop();
            if (value != -1) cout << "Popped: " << value << endl;
            break;

        case 3:
            cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty\n");
            break;

        case 4:
            cout << (st.isFull() ? "Stack is Full\n" : "Stack is NOT Full\n");
            break;

        case 5:
            st.display();
            break;

        case 6:
            cout << "Enter position from top to peek: ";
            cin >> pos;
            value = st.peek(pos);
            if (value != -1) cout << "Element at position " << pos << " is: " << value << endl;
            break;

        case 7:
            value = st.stackTop();
            if (value != -1) cout << "Top element: " << value << endl;
            else cout << "Stack is empty\n";
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
