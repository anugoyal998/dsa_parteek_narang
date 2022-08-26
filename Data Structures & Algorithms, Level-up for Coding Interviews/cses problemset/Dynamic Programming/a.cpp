#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int f(int i,int j,vector<int> arr,vector<vector<int>> &dp){
    if(i>j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    
    
    int left = arr[i] + min(f(i+2,j,arr,dp),f(i+1,j-1,arr,dp));
    int right = arr[j] + min(f(i,j-2,arr,dp),f(i+1,j-1,arr,dp));
    
    return dp[i][j] = max(left,right);
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
    for(int i=0; i<n;i++)cin >> arr[i];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << f(0,n-1,arr,dp) << endl;

    return 0;
}