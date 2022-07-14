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

int minValue(node* root){
    int mine = root->data;
    while(root->left){
        mine = root->left->data;
        root = root->left;
    }
    return mine;
}

node* deleteNode(node* root,int key){
    if(!root)return root;

    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }else{
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;  
        }
        root->data = minValue(root->right);
        root->right = deleteNode(root->right,root->data);
    }
    return root;
}

int main(){
    
    return 0;
}