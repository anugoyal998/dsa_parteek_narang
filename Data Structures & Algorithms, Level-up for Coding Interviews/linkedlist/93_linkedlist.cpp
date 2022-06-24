#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    T data;
    Node<T> *next;
public:
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

int main(){
    Node<int> *n = new Node<int>(10);
    
    return 0;
}