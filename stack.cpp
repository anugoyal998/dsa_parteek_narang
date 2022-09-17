#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int arr[N];

int top = -1;

void push(int val){
    int x = 1e5-1;
    if(top == x)return;
    top++;
    arr[top] = val;
}

void pop(){
    if(top == -1)return;
    top--;
}

int getTop(){
    if(top == -1)return -1;
    return arr[top];
}

bool isEmpty(){
    if(top == -1)return true;
    return false;   
}

int size(){
    return top+1;
}

void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    print(st);
    cout << st.size() << endl;
    return 0;
}