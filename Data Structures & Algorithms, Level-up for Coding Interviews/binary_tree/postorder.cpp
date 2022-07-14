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

void rec_postorder(node* root){
    if(!root)return;
    rec_postorder(root->left);
    rec_postorder(root->right);
    cout << root->data << " ";
}
// using 2 stack
void iterative_postorder(node* root){
    stack<node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();s1.pop();
        s2.push(root);
        if(root->left)s1.push(root->left);
        if(root->right)s1.push(root->right);
    }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
// using 1 stack
void iterative_postorder_1(node *root){
    stack<node*> s;
    while(root or !s.empty()){
        if(root){
            s.push(root);
            root = root->left;
        }else{
            node* temp = s.top()->right;
            if(!temp){
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
                while(!s.empty() and temp == s.top()->right){
                    temp = s.top();s.pop();
                    cout << temp->data << " ";
                }
            }else{
                root = temp;
            }
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
    rec_postorder(root);
    cout << endl;
    iterative_postorder(root);
    cout << endl;
    iterative_postorder_1(root);
    return 0;
}