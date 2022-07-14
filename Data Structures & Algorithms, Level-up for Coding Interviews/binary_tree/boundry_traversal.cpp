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

bool isLeaf(node* root){
    return root and !root->left and !root->right;
}

void leftBoundary(node* root,vector<int> &res){
    node* cur = root->left;
    while(cur){
        if(!isLeaf(cur))res.push_back(cur->data);
        if(cur->left)cur = cur->left;
        else cur = cur->right;
    }
}

void addRight(node* root,vector<int> &res){
    node* cur = root->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur))tmp.push_back(cur->data);
        if(cur->right)cur = cur->right;
        else cur = cur->left;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        res.push_back(tmp[i]);
    }
}

void addLeaves(node* root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left)addLeaves(root->left,res);
    if(root->right)addLeaves(root->right,res);
}

void solve(node* root){
    vector<int> res;
    if(!root)return; 
    if(!isLeaf(root))res.push_back(root->data);
    leftBoundary(root, res);
    addLeaves(root, res);
    addRight(root, res);
    for(auto i:res)cout << i <<  " ";
}

int main(){
    // https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);   
    solve(root);
    return 0;
}