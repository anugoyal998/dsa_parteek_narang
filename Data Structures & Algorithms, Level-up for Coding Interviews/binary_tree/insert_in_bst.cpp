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

node* insert(node* r,int val){
    if(!r)return new node(val);
    node* root  = r;
    while(true){
        if(root->data <= val){
            if(root->right){
                root = root->right;
            }else{
                root->right = new node(val);
                break;
            }
        }else{
            if(root->left){
                root = root->left;
            }else{
                root->left = new node(val);
                break;
            }
        }
    }
    return r;
}

int main(){
    
    return 0;
}