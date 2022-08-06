#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>

ll f(ll i,ll value_left,vvi arr,vvi &dp){
    if(value_left == 0) return 0;
    if(i<0)return 1e15;
    if(dp[i][value_left] != -1)return dp[i][value_left];
    ll ans = f(i-1,value_left,arr,dp);
    if(value_left - arr[i][1] >= 0)
        ans = min(ans,f(i-1,value_left-arr[i][1],arr,dp) + arr[i][0]);
    return dp[i][value_left] = ans;
}

int main(){
    ll n,w;
    cin >> n >> w;
    ll sum = 0;
    vvi arr(n);
    for(ll i=0; i<n; i++){
        ll wt,val;
        cin >> wt >> val;
        arr[i].push_back(wt);
        arr[i].push_back(val);
        sum += val;
    }

    vvi dp(n,vi(sum+1,-1));

    for(ll i = sum;i>=0;i--){
        if(f(n-1,i,arr,dp) <= w){
            cout << i << endl;
            break;
        }
    }
    return 0;
}