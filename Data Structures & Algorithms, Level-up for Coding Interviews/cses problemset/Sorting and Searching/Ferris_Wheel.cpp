#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    ll n,x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll low = 0, high = n-1;
    ll cnt = 0;

    while(low <= high){
        ll sum = arr[low] + arr[high];
        if(sum > x)high--;
        else low++,high--;
        cnt++;
    }
    cout << cnt << endl;

    

    return 0;
}