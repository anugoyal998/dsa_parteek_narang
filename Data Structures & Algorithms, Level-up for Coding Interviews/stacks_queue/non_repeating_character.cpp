#include "bits/stdc++.h"
using namespace std;

int main(){   
    // You are given a running stream of characters, output the
    // first non repeating character in the string formed so far
    // after every new character you get in input. Output-1 if
    // such a character doesn't exist.

    char ch;
    cin >> ch;

    int freq[27] = {0};
    queue<char> q;

    while(ch != '.'){
        q.push(ch);
        freq[ch-'a']++;

        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx] > 1)q.pop();
            else {
                cout << q.front();
                break;
            }
        }

        if(q.empty()){
            cout << "-1";
        }
        cin >> ch;
    }
    return 0;
}