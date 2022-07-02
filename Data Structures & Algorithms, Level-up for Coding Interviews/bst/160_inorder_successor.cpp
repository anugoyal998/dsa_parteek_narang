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

Node* inOrderSuccessor(Node* root, Node* target){
    if(target->right){
        Node* temp = target->right;
        while(temp->left){
            temp = temp->left;
        }
        return temp;
    }

    Node* temp = root;
    Node* succ = NULL;

    while(temp){
        if(temp->key > target->key){
            succ = temp;
            temp = temp->left;
        }else if(temp->key < target->key){
            temp = temp->right;
        }else break;
    }

    return succ;
}

int main(){
    // Given a BST. Find the inorder successor of a given target
    // node.

    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insert(root,x);
    }

    Node* t = root->right;

    cout << inOrderSuccessor(root,t)->key << endl;

    return 0; 
}