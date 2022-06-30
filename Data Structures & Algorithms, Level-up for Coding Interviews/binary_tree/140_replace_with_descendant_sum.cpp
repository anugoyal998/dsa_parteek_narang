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

int replaceWithSum(node* &root){
    if(!root)return 0;
    if(root and !root->left and !root->right)return root->data;

    int temp = root->data;
    root->data = replaceWithSum(root->left) + replaceWithSum(root->right);
    return temp + root->data;
}
void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n){
            cout << n->data << " ";
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }else if(!q.empty()){
            cout << endl;
            q.push(NULL);
        }
    }
}

int main(){
    // Given a binary tree, replace every node by sum of all its
    // descendants, leave leaf nodes intact.

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    levelOrderPrint(root);  
    replaceWithSum(root);
    cout << endl;
    levelOrderPrint(root);  
    return 0;
}