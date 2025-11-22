// Write a program to reverse a string. 

#include<iostream>
using namespace std;

int main(){
    char str[100];
    int buffer;
    
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int size=0;
    while(str[size] != '\0'){
        size++;
    }

    for(int i=0; i<size/2; i++){
        buffer = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = buffer;
    }

    cout<<"Reversed string : "<<str<<endl;

    return 0;
}
