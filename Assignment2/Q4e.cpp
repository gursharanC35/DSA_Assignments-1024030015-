// Write a program to convert a character from uppercase to lowercase. 

#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character in uppercase: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;  
        cout << "Lowercase character: " << ch << endl;
    } else {
        cout << "Not an uppercase character!" << endl;
    }

    return 0;
}
