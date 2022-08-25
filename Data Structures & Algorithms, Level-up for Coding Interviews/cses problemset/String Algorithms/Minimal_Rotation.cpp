#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    string s;
    cin >> s;

    int n = s.length();
    s += s;

    string x = s.substr(0,n);
    string ans = x;
    for(int i=n;i<2*n;i++){
        x.erase(x.begin());
        x += s[i];
        ans = min(ans,x);
    }

    cout << ans << endl;


    return 0;
}