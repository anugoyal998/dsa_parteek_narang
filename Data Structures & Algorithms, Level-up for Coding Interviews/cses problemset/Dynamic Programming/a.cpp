#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int m;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    vector<vector<ll>> dp(n,vector<ll>(m+3,0));

    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(i == 0){
                if(arr[i] == 0 or arr[i] == j)
                    dp[i][j]  = 1;
                else
                    dp[i][j] = 0;
            }else{
                if(arr[i] == 0 or arr[i] == j)
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%mod;
                else
                    dp[i][j] = 0;
            }
        }
    }

    ll ans = 0;
    for(int i=1;i<=m;i++)
        ans = (ans + dp[n-1][i])%mod;
    
    cout << ans << endl;

    return 0;
}