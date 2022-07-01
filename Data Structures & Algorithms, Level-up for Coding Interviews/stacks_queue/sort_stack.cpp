#include "bits/stdc++.h"
using namespace std;

void insert(stack<int> &s,int value){
    if(s.size() == 0){
        s.push(value);
        return;
    }
    if(value >= s.top()){
        s.push(value);
        return;
    }
    int t = s.top();
    s.pop();
    insert(s,value);
    s.push(t);
}

void sort_stack(stack<int> &s){
    if(s.size() == 0 || s.size() == 1)return;
    int t = s.top();
    s.pop();
    sort_stack(s);
    insert(s,t);
}

void print(stack<int> s){
    while(!s.empty()){ 
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(41);
    s.push(3);
    s.push(32);
    s.push(2);
    s.push(11);
    print(s);
    sort_stack(s);
    print(s);
    return 0;
}