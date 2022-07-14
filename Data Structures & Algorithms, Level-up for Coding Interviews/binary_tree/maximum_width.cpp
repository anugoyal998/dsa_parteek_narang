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

int width(node* root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id = q.front().second-min;
            node* n = q.front().first;
            q.pop();
            if(i == 0)first = cur_id;
            if(i == size-1)last = cur_id;
            if(n->left)
                q.push({n->left,cur_id*2+1});
            if(n->right)
                q.push({n->right,cur_id*2+2});
        }
        ans = max(ans,last-first+1);
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
    cout << width(root) << endl;
    return 0;
}