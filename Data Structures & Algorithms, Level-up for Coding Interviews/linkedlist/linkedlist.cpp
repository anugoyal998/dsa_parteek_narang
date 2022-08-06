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
};

void insertAtBack(Node* node,int val){
    Node* temp = node; // starting
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
}

void insertAtFront(Node* &node,int val){
    if(node == NULL){
        Node* newNode = new Node(val);
        node = newNode;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = node;
    node = newNode;
}

void print(Node* node){
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void reverse(Node* &node){
    Node* prev = NULL;
    Node* temp = node;
    while(temp->next != NULL){
        Node* n = temp->next;
        temp->next = prev;
        prev = temp;
        temp = n;
    }
    temp->next = prev;
    node = temp;
}

int main(){
    Node* node = new Node(1);

    node->

    for(int i=2;i<=10;i++)
        insertAtBack(node,i);
    
    insertAtFront(node,0);

    print(node);
    reverse(node);
    print(node);
    return 0;
}