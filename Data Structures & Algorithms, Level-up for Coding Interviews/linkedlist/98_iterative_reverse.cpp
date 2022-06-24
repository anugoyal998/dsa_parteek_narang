#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(node* &head,int data){
    if(!head){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

void insertInMiddle(node* &head,int data,int pos){
    if(pos == 0){
        insertAtHead(head,data);
    }else{
        node *temp = head;
        for(int jump = 1;jump <= pos-1; jump++){
            temp = temp->next;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void printLL(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* iterativeRev(node* head){
    if(!head)return head;
    if(head and !head->next)return head;
    node* prev = NULL;
    while(head){
        node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    head = prev;
    return head;
}

int main(){
    node *head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    printLL(head);
    head = iterativeRev(head);
    printLL(head);
    return 0;
}