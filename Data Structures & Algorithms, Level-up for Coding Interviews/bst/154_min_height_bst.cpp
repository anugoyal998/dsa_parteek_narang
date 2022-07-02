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

Node* sortedArrayToBST(vector<int> arr,int start,int end){
    if(start > end)return NULL;

    int mid = (start + end) >> 1;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;
}

void printInOrder(Node* root){
    if(!root)return;
    printInOrder(root->left);
    cout << root-> key << " ";
    printInOrder(root->right);
}

int main() {
    // Given a sorted array, construct a BST of minimum height.
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* root = sortedArrayToBST(arr,0,arr.size()-1);
    printInOrder(root);
    return 0;
}