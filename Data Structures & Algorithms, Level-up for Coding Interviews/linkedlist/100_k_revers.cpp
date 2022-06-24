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

node* kReverse(node* head,int k){
    // 1 2 3 4 5 6 7 8 9 10 11
    if(!head) return head;

    node* prev = NULL;
    node* current = head;
    node* temp;
    int cnt = 1;
    while(current and cnt <=k){
        temp = current->next;
        current->next = prev;
        prev  = current;
        current = temp;
        cnt++;
    }

    if(temp){
        head->next = kReverse(temp,k);
    }
    return prev;
}

int main(){
    node *head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    head = kReverse(head,2);

    printLL(head);
    return 0;
}