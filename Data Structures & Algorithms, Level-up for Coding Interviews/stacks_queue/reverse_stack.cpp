#include "bits/stdc++.h"
using namespace std;

void insert_at_bottom(stack<int> &st,int val){
    if(st.size() == 0){
        st.push(val);
        return;
    }
    int t = st.top();
    st.pop();
    insert_at_bottom(st,val);
    st.push(t);
}

void reverse(stack<int> &s){
    if(s.size() == 0){
        return;
    }
    int t = s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s,t);
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
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    print(s);
    reverse(s);
    print(s);
    return 0;
}