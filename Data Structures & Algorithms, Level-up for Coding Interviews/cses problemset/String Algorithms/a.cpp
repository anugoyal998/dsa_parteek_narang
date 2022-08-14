#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long int
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.length();
    if(n<m){
        cout << 0 << endl;
    }else{
        ll ans = n-m+1;
        int cnt = n-m;
        while(cnt--){
            ans = (ans*26)%mod;
        }
        cout << ans << endl;
    }

    return 0;
}