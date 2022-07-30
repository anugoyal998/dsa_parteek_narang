#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,st,n) for(int i=st;i<n;i++)
#define nline cout<<endl;
#define mod 1000000007
#define maxN 1000001
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define print_arr(arr) for(auto i:arr)cout<<i<<' ';
     
void fill_vector(vi &arr,int n){
    loop(i,0,n){
        cin>>arr[i];
    }
}
     
void solve(){
    int n;
    cin >> n;
    vi arr(n);
    fill_vector(arr,n);
    vi dp(n,INT_MAX);
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    loop(i,2,n){
        dp[i] = min(dp[i],dp[i-1]+abs(arr[i]-arr[i-1]));
        dp[i] = min(dp[i],dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n-1]<<endl;

}
     
int main(){
    solve();
    return 0;
}