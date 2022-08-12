#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

vector<int> LPS(string s){
    int n = s.length();
    int len = 0;
    vector<int> arr(n);
    arr[0] = len;
    int i = 1;
    while(i < n){
        if(s[i] == s[len])
            arr[i++] = ++len;
        else{
            if(len != 0)
                len = arr[len-1];
            else
                arr[i++] = 0;
        }
    }
    return arr;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    string s;
    cin >> s;
    int n = s.length();

    vector<int> lps = LPS(s);
    vector<int> ans;
    int j = lps[n-1];

    while(j>0){
        ans.push_back(j);
        j = lps[j-1];
    }

    sort(ans.begin(), ans.end());

    for(auto i:ans)cout << i << " ";
    return 0;
}