#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

unordered_map<string,int> mp;

vector<ll> dp;

// int f(int i,int n,string s){
//     if(i >= n)return 1;
//     if(dp[i] != -1)return dp[i];
//     string x = "";
//     int ans = 0;
//     for(int j=i;j<n;j++){
//         x += s[j];  
//         if(mp.find(x) != mp.end()){
//             ans += f(j+1,n,s);
//         }
//     }
//     return dp[i] = ans;
// }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    string s;
    cin >> s;
    int n = s.length(),k;
    cin >> k;
    for(int i=0; i<k;i++){
        string x;
        cin >> x;
        mp[x] = 1;
    }

    dp = vector<ll>(n+1,0);
    dp[n] = 1;

    for(int i=n-1;i>=0;i--){
        string x = "";
        for(int j=i;j<n;j++){
            x += s[j];
            if(mp.find(x) != mp.end()){
                dp[i] += dp[j+1];
            }
        }
    }

    cout << dp[0] << endl;


    

    return 0;
}