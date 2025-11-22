#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int top, size;
    int *a;

public:
    Stack(int n) {
        size = n;
        top = -1;
        a = new int[size];
    }

    ~Stack() {
        delete[] a;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
        } else {
            a[++top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return a[top--];
    }

    bool isEmpty() { return top == -1; }
    int stackTop() { return isEmpty() ? -1 : a[top]; }
};

bool isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

int Eval(char *postfix) {
    Stack st(strlen(postfix));
    int x1, x2, r;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            st.push(postfix[i] - '0'); 
        } else {
            x2 = st.pop();
            x1 = st.pop();
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            st.push(r);
        }
    }
    return st.stackTop();
}

int main() {
    char postfix[] = "234*+82/-"; 
    cout << "Result is " << Eval(postfix) << endl;
    return 0;
}
