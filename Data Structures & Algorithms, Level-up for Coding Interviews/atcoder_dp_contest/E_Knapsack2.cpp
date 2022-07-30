#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>

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


    vi prev(sum+1,w), cur(sum+1,w);
    prev[arr[0][1]] = w - arr[0][0];

    for(ll i=1;i<n;i++){
        cur[0] = w;
        for(ll j=1;j<=sum;j++){
            int notTake = prev[j];
            int take = w;
            if(j >= arr[i][1] and prev[j-arr[i][1]] >= arr[i][0]){
                take = prev[j-arr[i][1]] - arr[i][0];
            }
            cur[j] = min(take,notTake);
        }
    }

    int ans = 0;
    for(int i=0;i<=sum;i++){
        if(prev[i] != w)ans = i;
    }

    cout << ans << endl;

    return 0;
}