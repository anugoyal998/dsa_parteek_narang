#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

void print(vector<vector<ll>> v){
    for(auto i:v){
        for(auto j:i)cout << j <<  " ";
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)arr[i] = i+1;
    ll sum = (n*(n+1)) / 2;
    if(sum&1){
        cout << 0 << endl;
    }else{
        sum /= 2;
        // vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
        // dp[1][0] = dp[1][1] = 1;
        vector<ll> prev(sum+1,0);
        prev[0] = prev[1] = 1;
        for(int i=2;i<=n;i++){
            vector<ll> cur(sum+1,0);
            cur[0] = 1;
            // dp[i][0] = 1;
            for(int j=1;j<=sum;j++){
                cur[j] = prev[j];
                // dp[i][j] = dp[i-1][j];
                if(j >= i){
                    cur[j] = (cur[j] + prev[j-i]) % mod;
                    // dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
                }
            }
            prev = cur;
        }
        cout << (prev[sum] / 2) << endl;
    }

    return 0;
}