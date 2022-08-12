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

    string txt,pat;
    cin >> txt >> pat;

    vector<int> lps = LPS(pat);
    int m = pat.length();
    int n = txt.length();

    int i = 0, j = 0;
    int cnt = 0;
     while((n-i) >= (m-j)){
        if(pat[j] == txt[i])i++,j++;

        if(j == m){
            cnt++;
            j = lps[j-1];
        }else if(i<n and pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }  
    cout << cnt << endl;

    return 0;
}