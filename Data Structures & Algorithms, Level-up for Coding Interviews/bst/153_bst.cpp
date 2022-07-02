#include "bits/stdc++.h"
using namespace std;

class Node{
    public:
    int key;
    Node *left, *right;

    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};

Node* insert(Node* root,int key){
    if(!root)return new Node(key);
    if(key < root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;
}

void printInOrder(Node* root){
    if(!root)return;
    printInOrder(root->left);
    cout << root-> key << " ";
    printInOrder(root->right);
}

bool search(Node* root,int key){
    if(!root)return false;
    if(root->key == key)return true;
    if(root->key < key)return search(root->right,key);
    else return search(root->left,key);
}

int main(){
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insert(root,x);
    }

    printInOrder(root);
    return 0;
}