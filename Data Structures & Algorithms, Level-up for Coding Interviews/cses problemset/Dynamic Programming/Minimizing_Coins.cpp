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
    sort(arr,arr+n);
    vi dp(x+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>i)break;
            else{
                if(dp[i-arr[j]]!=INT_MAX)
                dp[i] = min(dp[i],1 + dp[i-arr[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)dp[x] = -1;
    cout<<dp[x];
 
     return 0;
}