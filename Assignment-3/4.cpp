#include <iostream>
#include <cstring>
using namespace std;

struct stack {
    int top;
    int size;
    char *e;

    stack(int x) {
        size = x;
        top = -1;
        e = new char[size];
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            e[++top] = x;
        }
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        } else {
            return e[top--];
        }
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    int priority(char c) {
        if (c == '+' || c == '-') return 1;
        else if (c == '*' || c == '/') return 2;
        else if (c == '^') return 3;
        return 0;
    }

    void postfix(char str[]) {
        char exp[200];
        int j = 0;
        int n = strlen(str);

        for (int i = 0; i < n; i++) {
            char c = str[i];

            if (isalnum(c)) {
                exp[j++] = c;
            }
            
            else if (c == '(') {
                push(c);
            }
            
            else if (c == ')') {
                while (!isEmpty() && e[top] != '(') {
                    exp[j++] = pop();
                }
                pop(); 
            }
            
            else {
                while (!isEmpty() && priority(e[top]) >= priority(c)) {
                    exp[j++] = pop();
                }
                push(c);
            }
        }

        while (!isEmpty()) {
            exp[j++] = pop();
        }

        exp[j] = '\0'; 

        cout << "Postfix expression: " << exp << endl;
    }

    ~stack() {
        delete[] e;
    }
};

int main() {
    char str[100];
    cout << "Enter the expression (infix) to be converted to postfix: ";
    cin.getline(str, 100);

    stack st(strlen(str));
    st.postfix(str);

    return 0;
}
