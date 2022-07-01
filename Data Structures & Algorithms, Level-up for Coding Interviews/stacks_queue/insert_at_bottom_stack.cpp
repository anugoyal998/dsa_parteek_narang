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

void print(stack<int> s){
    while(!s.empty()){ 
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    insert_at_bottom(s,0);
    print(s);
    return 0;
}