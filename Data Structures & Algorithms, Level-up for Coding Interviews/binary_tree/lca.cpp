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

node* lca(node* root,node* p,node* q){
    if(!root or root == p or root == q)return root;
    node* left = lca(root->left,p,q);
    node* right = lca(root->right,p,q);

    if(left == NULL)
        return right;
    else if(right == NULL){
        return left;
    }else{
        return root;
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);  
    cout << lca(root,root->left,root->right)->data << endl; 
    return 0;
}