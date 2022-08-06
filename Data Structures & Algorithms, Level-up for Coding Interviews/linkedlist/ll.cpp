#include "bits/stdc++.h"
using namespace std;

class Node{
    public:
    Node* next;
    int val;
    Node(int val){
        this->val = val;
        next = NULL;
    }
    Node(){
        next = NULL;
        val = -1;
    }
};

void insertAtHead(Node* &node,int val){
    if(!node){
        node = new Node(val);
        return;
    }
    Node* n = new Node(val);
    n->next = node;
    node = n;
}

void insertAtBack(Node* &node,int val){
    if(!node){
        node = new Node(val);
        return;
    }
    Node* temp = node;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void reverse(Node* &node){
    if(!node or !node->next)return;
    Node* temp = node;
    Node* prev = NULL;
    while(temp->next){
        Node* n = temp->next;
        temp->next = prev;
        prev = temp;
        temp = n;
    }
    temp->next = prev;
    node = temp;
}

void print(Node* node){
    while(node){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node* node = NULL;
    insertAtHead(node,1);
    insertAtHead(node,2);
    insertAtHead(node,3);
    insertAtHead(node,4);
    insertAtHead(node,5);
    insertAtHead(node,6);
    insertAtHead(node,7);
    insertAtBack(node,0);
    print(node);
    reverse(node);
    print(node);
    return 0;
}