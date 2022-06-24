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

Node* detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* detectFirstNode(Node* head){
    Node* meet = detectCycle(head);
    Node* start = head;
    while(start != meet){
        start = start->next;
        meet = meet->next;
    }
    return start;
}

int main(){
    // Floyd's cycle detection Algorithm
    // https://www.youtube.com/watch?v=jcZtMh_jov0
    return 0;
}