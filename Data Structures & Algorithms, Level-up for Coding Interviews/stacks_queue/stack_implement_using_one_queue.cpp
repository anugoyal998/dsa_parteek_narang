#include "bits/stdc++.h"
using namespace std;

class MyStack{
    public:
    queue<int> q;
    void push(int val){
        q.push(val);
        int sz = q.size()-1;
        while(sz--){
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};

void print(MyStack s){
    while(!s.empty()){
        cout << s.top() <<  " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    print(s);
    return 0;
}