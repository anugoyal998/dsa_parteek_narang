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

class LinkedList{
    public:
    Node* head;
    Node* tail;
};

LinkedList tree2LL(Node* root){
    LinkedList l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }

    if(!root->left and !root->right){
        l.head = l.tail = root;
    }else if(root->left and !root->right){
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }else if(!root->left and root->right){
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }else{
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main(){
    // Given a BST convert it to a sorted linked list, right pointer
    // should behave as next pointer for the linked list.

    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(auto x:arr){
        root = insert(root,x);
    }

    LinkedList l = tree2LL(root);
    Node* temp = l.head;
    while(temp){
        cout << temp->key << " ";
        temp = temp->right;
    }
    return 0;
}