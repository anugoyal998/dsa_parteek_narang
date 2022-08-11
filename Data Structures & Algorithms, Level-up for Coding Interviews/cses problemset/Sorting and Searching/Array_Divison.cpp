#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long int
#define mod 1000000007

int n,k;
vector<int> arr;

ll check(ll mid){
    ll cnt = 0;
    ll sum = 0;
    ll maxe = -1e18;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum >= mid){
            cnt++;
            maxe = max(maxe,sum);
            sum = 0;
        }
    }
    return cnt == k ? maxe : -1;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    ll start = *min_element(arr.begin(), arr.end());
    ll end = 0;
    for(int i=0; i<n; i++)end += arr[i];
    ll ans = 1e18;
    while(start <= end){
        ll mid = (start + end) / 2;
        ll val = check(mid);
        if(val != -1){
            ans = min(ans, val);
            start = mid+1;
        }else end = mid-1;
    }

    cout << ans << endl;



    return 0;
}