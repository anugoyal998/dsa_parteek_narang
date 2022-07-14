#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>

class Node{
    public:
    Node *left,*right;
    int data;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* buildLevelOrdere(vi arr,int i,int n){
    if(i>=n)return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildLevelOrdere(arr,2*i+1,n);
    root->right = buildLevelOrdere(arr,2*i+2,n);
    return root;
}

void printLevelOrdere(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node){
            cout << node->data << " ";
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
}

void heapify(vi &arr,int i,int n){
    if(i>=n)return;
    int left_idx = 2*i + 1;
    int right_idx = 2*i + 2;
    int maxe = arr[i];
    int idx = i;
    if(left_idx < n and arr[left_idx] > maxe){
        maxe = arr[left_idx];
        idx = left_idx;
    }
    if(right_idx < n and arr[right_idx] > maxe){
        maxe = arr[right_idx];
        idx = right_idx;
    }
    if(idx == i)return;
    swap(arr[i],arr[idx]);
    heapify(arr,idx,n);
}

void buildHeap(vi &arr){
    int n = arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i,n);
    }
}

int main(){
    vi arr = {3,6,5,0,8,2,1,9};
    int n = arr.size();
    buildHeap(arr);
    Node* root = buildLevelOrdere(arr,0,n);
    printLevelOrdere(root);
    return 0;
}