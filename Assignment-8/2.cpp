#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *lchild;
    node *rchild;

    node(int value){
        data=value;
        lchild=NULL;
        rchild=NULL;
    }
};

node * Rsearch(node *p,int value){
    if(p==NULL || p->data==value){
        return p;
    }
    
    if(p->data>value){
        return Rsearch(p->lchild,value);
    }
    else {
        return Rsearch(p->rchild,value);
    }
    
}

node *search(node *p,int value){
    while(p!=NULL){
        if(p->data==value){
            return p;
        }
        else if(p->data<value){
            p=p->rchild;
        }
        else{
            p=p->lchild;
        }
    }
    return NULL;
}

node * maxEl(node *p){
    if(p==NULL){
        return NULL;
    }
    while(p->rchild!=NULL){
        p=p->rchild;
    }
    return p;
}

node * minEl(node *p){
    if(p==NULL){
        return NULL;
    }
    while(p->lchild!=NULL){
        p=p->lchild;
    }
    return p;
}

node * successor(node *r,node *p){
    if(p->rchild!=NULL){
        return minEl(p->rchild);
    }

    node *succ=NULL;

    while(true){
        if(p->data>r->data){
            r=r->rchild;
        }
        else if(p->data<r->data){
            succ=r;
            r=r->lchild;
        }
        else{
            break;
        }
    }
    return succ;
}

node *predessor(node *r,node*p){
    if(p->lchild!=NULL){
        return maxEl(p->lchild);
    }

    node *pre=NULL;

    while(true){
        if(p->data>r->data){
            pre=r;
            r=r->rchild;
        }
        else if(p->data<r->data){
            r=r->lchild;
        }
        else{
            break;
        }
    }
    return pre;
}

int main(){
    node *root=new node(10);
    root->lchild=new node(9);
    root->rchild=new node(11);
    root->lchild->lchild=new node(8);
    root->rchild->rchild=new node(12);

    if(search(root,12) == NULL){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found"<<endl;
    }

    cout<<"Minimum element is : "<<minEl(root)->data<<endl;
    cout<<"Mmum element is : "<<maxEl(root)->data<<endl;
    cout<<"Successor of element is : "<<successor(root,root->lchild->lchild)->data<<endl;
    cout<<"Predessor of element is : "<<predessor(root,root->lchild)->data<<endl;

    return 0;

}
