#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,st,n) for(int i=st;i<n;i++)
#define mod 1000000007
#define maxN 1000001
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
     
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    loop(i,0,n)cin>>arr[i];
    vector<ll> dp(x+1,0);
    sort(arr,arr+n);
    if(x<arr[0]){
        cout<<0;return 0;
    }
    dp[arr[0]] = 1;
    for(int i=arr[0]+1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i<arr[j])break;
            else if(i>arr[j]){
                dp[i] = (dp[i] + dp[i-arr[j]])%mod;
            }else{
                dp[i] = (dp[i] + 1)%mod;
            }
        }
    }
    cout<<dp[x];
     return 0;
}