#include<iostream>
#include<stack>
using namespace std;
class Mystack{
    public: 
    stack<int>s1;
    stack<int>s2;
    Mystack(){
    }
        void push(int x){
           while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
           }
           s1.push(x);
           while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
           }
        }
        int pop(){
            int ans=s1.top();
            s1.pop();
            return ans;
        }
        int peek(){
           return s1.top();
        }
        bool empty(){
           return s1.empty();
        }
    
};
int main(){
    Mystack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl;   
    cout << "Popped: " << st.pop() << endl; 
    cout << "Top: " << st.peek() << endl;   

   
    return 0;
}
