#include "bits/stdc++.h"
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){}
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtBack(Node* &node,int value){
    if(!node){
        node = new Node(value);
        return;
    }
    Node* temp = node;
    while(temp->next)temp = temp->next;
    temp->next = new Node(value);
}

void printNode(Node* node){
    while(node){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void reverseNode(Node* &node){
    Node* prev = NULL;
    Node* temp = node;
    while(temp){
        Node* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    node = prev;
}

Node* recReverse(Node* node){
    if(!node or !node->next)return node;
    Node* head = recReverse(node->next);
    node->next->next  = node;
    node->next = NULL;
    return head;
}

int main(){
    Node* node = new Node(1);
    insertAtBack(node,2);
    insertAtBack(node,3);
    insertAtBack(node,4);
    insertAtBack(node,5);
    printNode(node);
    reverseNode(node);
    node = recReverse(node);
    printNode(node);
    return 0;
}