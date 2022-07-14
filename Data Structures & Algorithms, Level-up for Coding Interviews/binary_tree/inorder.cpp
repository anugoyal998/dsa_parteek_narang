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

void rec_inorder(node* root){
    if(!root)return;
    rec_inorder(root->left);
    cout << root->data << " ";
    rec_inorder(root->right);
}

void iterative_inorder(node* root){
    stack<node*> st;
    while(true){
        if(root){
            st.push(root);
            root = root->left;
        }else{
            if(st.empty())break;
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
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
    rec_inorder(root);
    cout << endl;
    iterative_inorder(root);
    return 0;
}