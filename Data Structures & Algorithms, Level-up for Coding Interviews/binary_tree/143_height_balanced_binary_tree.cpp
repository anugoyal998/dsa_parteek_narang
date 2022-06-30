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

pair<int,bool> isHeightBalanced(node* root){
    pair<int,bool> p;
    if(root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int,bool> left = isHeightBalanced(root->left);
    pair<int,bool> right = isHeightBalanced(root->right);
    int height = max(left.first,right.first) + 1;
    if(abs(left.first-right.first) <= 1 and left.second and right.second){
        return {height,true};
    }
    return {height,false};
}

int main(){
    // Given a binary tree, check if it is height balanced.
    // A non-empty binary tree T is balanced if:
    // Left subtree of T is balanced
    // 2) Right subtree of T is balanced
    // 3) The difference between heights of left subtree and right
    // subtree is not more than 1.


    node* root = new node(1);
    // root->left = new node(2);
    root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << isHeightBalanced(root).second << endl;
    return 0;
}