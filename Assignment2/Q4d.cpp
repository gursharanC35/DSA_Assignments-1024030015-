//(d) Write a program to sort the strings in alphabetical order. 

#include<iostream>
using namespace std;

int main(){
    char str[100];
    char swap;
    
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int size=0;
    while(str[size] != '\0'){
        size++;
    }
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            
            char a = str[j];
            char b = str[j + 1];
            if (a >= 'A' && a <= 'Z') a = a + 32;  
            if (b >= 'A' && b <= 'Z') b = b + 32;  

            if(a>b){
                swap = str[j];
                str[j] = str[j+1];
                str[j+1] = swap;
            }
        }
    }

    cout<<"String in alphabetical order : "<<str<<endl;

}
