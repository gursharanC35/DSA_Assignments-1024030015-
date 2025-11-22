#include<iostream>
using namespace std;

class stack{
    int size;
    int top;
    char *el;
    
    public:
    stack(int x){
        size=x;
        top=-1;
        el = new char[size];
    }

    bool isFull(){
        if(top == (size-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    void push(char x){
        if(isFull()){
            cout<<"Stack Overflow : ";
        }
        else{
            top++;
            el[top]=x;
        }
    }

    char pop(){
        char x='\0';
        if(isEmpty()){
            return x;
        }
        else{
            x=el[top];
            top--;
        }
        return x;
    }

    bool isBalanced(char ex[]){
        char x;
        for(int i=0; ex[i] != '\0'; i++){
            if(ex[i] == '(' || ex[i] == '{' || ex[i] == '['){
                push(ex[i]);
            }
            else if(ex[i] == ')' || ex[i] == '}' || ex[i] == ']'){
                x=pop();
                if(x == '\0'){
                    return 0;
                }
                else if ((x == '(' && ex[i] != ')') ||
                (x == '{' && ex[i] != '}') ||
                (x == '[' && ex[i] != ']')) {
                return 0;
            }
            }
        }
        if(isEmpty()){
            return 1;
        } 
        else{
            return 0;
        }
    }
};

int main(){
    int size;
    char ex[100];

    cout<<"Enter the expression : ";
    cin.getline(ex,100);

    for(int i=0; ex[i] != '\0'; i++){
        size=i+1;
    }

    stack st(size);

    if(st.isBalanced(ex)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }

    return 0;
}
