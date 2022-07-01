#include "bits/stdc++.h"
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] >= '0' and s[i] <= '9')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() and st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() and prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
void print(stack<char> s)
{
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int evaluate(string s)
{
    int ans = 0;
    stack<char> st;
    for (auto c : s)
    {
        // 1452++3-+68++
        if (c >= '0' and c <= '9')
            st.push(c);
        else
        {
            int a = st.top() - '0';
            st.pop();
            if (st.empty())
            {
                if (c == '-')
                {
                    a *= -1;
                    st.push(a);
                }
                continue;
            }
            int b = st.top() - '0';
            st.pop();
            int cnt = 0;
            if (c == '+')
                cnt = a + b;
            else if (c == '-')
                cnt = b - a;
            else if (c == '*')
                cnt = a * b;
            else
                cnt = b / a;
            st.push(cnt);
        }
        print(st);
    }
    return st.top();
}
int calculate(string s)
{
    s = infixToPostfix(s);
    cout << s << endl;
    return evaluate(s);
}

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}