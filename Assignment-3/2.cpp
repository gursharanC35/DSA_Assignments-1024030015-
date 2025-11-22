//Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”

#include<iostream>
#include<string>
using namespace std;

struct stack{
    int top;
    int size;
    char *S;

    stack(int x){
        top=-1;
        size=x;
        S=new char[size];
    }


char pop(){
    char x;
    if(top == -1){
        return '\0';
    }
    else{
        x=S[top];
        top--;
        return x;
    }
}

void push(char x){
    if(top==size-1){ 
        cout<<"Stack overflow";
    }
    else{
        top++;
        S[top]=x;
    }
}


};

int main(){

    char word[100];
    int n;

    cout<<"Enter a word to reverse : ";
    cin.getline(word,100);
 
    for(int i=0; word[i] != '\0'; i++){
        n=i+1;
    }

    stack st(n);

    for(int i=0; i<n; i++){
        st.push(word[i]);
    }
    
    cout<<"Reversed word : "<<endl;
    for(int i=0; i<n; i++){
        cout<<st.pop();
    }

    return 0;
}
