#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
} *first = NULL;

void create(int arr[], int n) {
    if (n == 0) return;

    node *last;
    for (int i = 0; i < n; i++) {
        node *t = new node;
        t->data = arr[i];
        t->next = NULL;
        if (i == 0) {
            first = t;
            last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

int middleEl(node *p){
    node *fp=p,*sp=p;
    while(fp!=NULL && fp->next!= NULL){
        sp=sp->next;
        fp=fp->next->next;
    }
    
        return sp->data;
}    
 
int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    create(arr, n);

    cout<<"Middle element is : "<<middleEl(first)<<endl;

    return 0;
}
