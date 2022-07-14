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

void rec_preorder(node* root){
    if(!root) return;
    cout << root->data << " ";
    rec_preorder(root->left);
    rec_preorder(root->right);
}

void iterative_preorder(node* root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout << root->data << " ";
        if(root->right)st.push(root->right);
        if(root->left)st.push(root->left);
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
    rec_preorder(root);
    cout << endl;
    iterative_preorder(root);
    return 0;
}