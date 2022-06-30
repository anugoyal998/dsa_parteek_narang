#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(){
    int d;
    cin >> d;
    if(d==-1)return NULL;
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

class Pair{
    public:
    int inc;
    int exc;
    Pair(){
        inc = exc = 0;
    }
};

Pair maxSubsetSum(node* root){
    Pair p;
    if(root == NULL) return p;

    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + max(right.inc, right.exc);

    return p;
}

int main(){
    // Find the largest sum of a subset of nodes in a binary tree,
    // such that if a node is included in the sum then its parent
    // and children must not be included in the subset sum.

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    Pair p = maxSubsetSum(root);
    cout << max(p.exc,p.inc) << endl;
    return 0;
}