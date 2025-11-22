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

node* insert(node* root, int key) {
    if (root == NULL)
        return new node(key);

    if (key < root->data)
        root->lchild = insert(root->lchild, key);
    else if (key > root->data)
        root->rchild = insert(root->rchild, key);

    return root;
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

node* deleteEl(node *p,int key){
    if(p==NULL){
        return p;
    }

    if(key<p->data){
        return deleteEl(p->lchild,key);
    }
    else if(key>p->data){
        return deleteEl(p->rchild,key);
    }
    else{
        node *temp;
        if(p->lchild==NULL){
            temp=p->rchild;
            delete p;
            return temp;
        }
        else if(p->rchild==NULL){
            temp=p->lchild;
            delete p;
            return temp;
        }
        temp=minEl(p->rchild);
        p->data=temp->data;
        p->rchild=deleteEl(p->rchild,temp->data);
    }

    return p;
}

int maxdepth(node *p){
    if(p==NULL){
        return 0;
    }

    return 1 + max(maxdepth(p->lchild),maxdepth(p->rchild));
}

int mindepth(node *p){
    if(p==NULL){
        return 0;
    }
    
    if(p->lchild==NULL){
        return mindepth(p->rchild);
    }
    if(p->rchild==NULL){
        return mindepth(p->lchild);
    }
    return 1 + min(mindepth(p->lchild),mindepth(p->rchild));
}

int main(){
    node *root=NULL;
    root=insert(root,10);
    insert(root,0);
    insert(root,93);
    insert(root,9);
    insert(root,47);
    insert(root,1);
    insert(root,6);
    insert(root,83);
    insert(root,3);

    deleteEl(root,10);
    cout<<root->data;
}
