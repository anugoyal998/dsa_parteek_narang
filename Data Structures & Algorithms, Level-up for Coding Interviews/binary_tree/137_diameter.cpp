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

node* buildTree(){
    int d;
    cin >> d;
    if(d==-1)return NULL;
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

int height(node* root){
    return root == NULL ? 0 : 1 + max(height(root->left), height(root->right));
}
// O(N^2) time complexity
int diameter(node* root){
    if(root == NULL)return 0;

    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1,max(d2,d3));
}

class HDPair{
    public:
    int height;
    int diameter;
    HDPair(){
        height = 0;
        diameter = 0;
    }
};
// O(N) time complexity
HDPair optDiameter(node* root){
    HDPair p;
    if(root == NULL)return p;
    HDPair left =  optDiameter(root->left);
    HDPair right = optDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    
    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;
    p.diameter = max(d1,max(d2,d3));

    return p;
}

int main(){
    // Find the diameter of the binary tree, diameter is defined
    // as the largest distance between any two nodes of the tree.
    // The diameter may or may not pass through root node

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << optDiameter(root).diameter << endl;
    return 0;
}