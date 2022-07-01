#include "bits/stdc++.h"
using namespace std;

int prec(char c){
    if(c == '^')return 3;
    if(c == '*' || c == '/')return 2;
    if(c == '+' || c == '-')return 1;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.length();i++){
        if(s[i] >= 'a' and s[i] <= 'z'){
            res += s[i];
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            while(!st.empty() and st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }else{
            while(!st.empty() and prec(st.top()) > prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    // Infix to Postfix
    // algorithm
    // if operand
        // print
    // If("
        // push to stack
    // If
        // pop from stack
    // If operator
        // pop from stack and print untikaa
        // operator with less precedence is found

    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(s) << endl;
    return 0;
}