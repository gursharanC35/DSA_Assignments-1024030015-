// Write a program to delete all the vowels from the string. 

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

    for(int i=0; i<size; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            for(int j=i; j<size;j++){
                str[j]=str[j+1];
            }
            size--;
            i--;
        }
    }

    cout << "String after removing vowels: " << str << endl;

    return 0;

}
