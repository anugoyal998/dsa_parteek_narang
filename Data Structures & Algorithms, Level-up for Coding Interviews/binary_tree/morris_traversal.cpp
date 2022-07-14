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

vector<int> morris_traversal_inorder(node* root){
    vector<int> ans;
    node* cur = root;
    while(cur){
        if(!cur->left){
            ans.push_back(cur->data);
            cur = cur->right;
        }else{
            node* prev = cur->left;
            while(prev->right and prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }else{
                prev->right = NULL;
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return ans;
}

vector<int> morris_traversal_preorder(node* root){
    vector<int> ans;
    node* cur = root;
    while(cur){
        if(!cur->left){
            ans.push_back(cur->data);
            cur = cur->right;
        }else{
            node* prev = cur->left;
            while(prev->right and prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<int> ans = morris_traversal_inorder(root);
    for(auto i:ans){
        cout << i  << " ";
    }
    cout << endl;
    ans = morris_traversal_preorder(root);
    for(auto i:ans){
        cout << i  << " ";
    }
    return 0;
}