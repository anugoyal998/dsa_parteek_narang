#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int val;
    Node* next;
};

void insertAtEnd(Node* head,int val){
    Node* newNode = new Node();
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->val = val;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(Node* &head,int val){
    Node* newNode = new Node();
    newNode->val = val;
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}



void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node();
    head->val = 1;
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    print(head);
    insertAtHead(head,0);
    print(head);
    return 0;
}