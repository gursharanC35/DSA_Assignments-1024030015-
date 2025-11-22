#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBST(Node* node, long long minVal, long long maxVal) {
    if (node == nullptr) return true;
    if (node->data <= minVal || node->data >= maxVal) return false;
    return isBST(node->left, minVal, node->data) &&
           isBST(node->right, node->data, maxVal);
}

bool BST(Node* root) {
    return isBST(root, INT8_MIN,INT8_MAX);
}

int main() {

    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->right->right = new Node(14);

    cout << "Tree 1 is " << (BST(root1) ? "a BST\n" : "not a BST\n");

    Node* root2 = new Node(8);
    root2->left = new Node(3);
    root2->right = new Node(10);
    root2->left->left = new Node(1);
    root2->left->right = new Node(12); 

    cout << "Tree 2 is " << (BST(root2) ? "a BST\n" : "not a BST\n");


    return 0;
}
