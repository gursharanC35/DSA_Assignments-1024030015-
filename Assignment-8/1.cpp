//Write program using functions for binary tree traversals: Pre-order, In-order and Post
//order using recursive approach.

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

void preorder(node *p){
        if(p!=NULL){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
    return ;
}

void inorder(node *p){
        if(p!=NULL){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
    return ;
}void postorder(node *p){
        if(p!=NULL){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
    return ;
}

int main(){
    node *root=new node(1);
    root->lchild=new node(2);
    root->rchild=new node(3);
    root->lchild->lchild=new node(4);
    root->lchild->rchild=new node(5);

    preorder(root);
    inorder(root);
    postorder(root);

    return 0;
}
