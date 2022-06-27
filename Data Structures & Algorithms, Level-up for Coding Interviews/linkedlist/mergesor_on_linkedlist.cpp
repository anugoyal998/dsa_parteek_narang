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

node* merge(node* a, node* b){
    node* dummy = new node(-1);
    while(a and b){
        if(a->data <= b->data){
            dummy->next = a;
            dummy = dummy->next;
            // dummy->next = NULL;
            a = a->next;
        }else{
            dummy->next = b;
            dummy = dummy->next;
            // dummy->next = NULL;
            b = b->next;
        }
    }

    while(a){
        dummy->next = a;
        dummy = dummy->next;
        // dummy->next = NULL;
        a = a->next;
    }

    while(b){
        dummy->next = b;
        dummy = dummy->next;
        // dummy->next = NULL;
        b = b->next;
    }
    return dummy->next;
}

node* midPoint(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeSort(node* head){
    if(!head or !head->next)return head;
    node* mid = midPoint(head);

    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}

int main(){
    node *head = NULL;
    insertAtHead(head,0);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    printLL(head);
    head = mergeSort(head);
    printLL(head);
    return 0;
}