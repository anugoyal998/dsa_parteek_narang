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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    loop(i,0,n){
        ll a,b;
        cin>>a>>b;
        arr.pb({b,a});
    }
    sort(arr.begin(),arr.end());
    int ans = 1;
    int st = 0;
    int ed = 1;
    while(ed<n){
        if(arr[st].first<=arr[ed].second){
            ans++;st = ed;ed++;
        }else if(arr[st].first>arr[ed].second){
            ed++;
        }
    }
    cout<<ans;
 
     return 0;
}