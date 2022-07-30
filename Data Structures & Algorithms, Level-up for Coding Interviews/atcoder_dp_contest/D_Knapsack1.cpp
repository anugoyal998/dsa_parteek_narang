#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>

int main(){
    ll n,w;
    cin >> n >> w;
    vvi arr(n);
    for(ll i=0; i<n; i++){
        ll wt,val;
        cin >> wt >> val;
        arr[i].push_back(wt);
        arr[i].push_back(val);
    }

    vi prev(w+1,0), cur(w+1,0);
    for(ll i=1;i<=w;i++){
        if(i >= arr[0][0])prev[i] = arr[0][1];
    }

    for(ll i=1;i<n;i++){
        cur[0] = 0;
        for(ll j=1;j<=w;j++){
            ll notTake = prev[j];
            ll take = 0;
            if(j >= arr[i][0])take = prev[j - arr[i][0]] + arr[i][1];
            cur[j] = max(take,notTake);
        }
        prev = cur;
    }

    cout << prev[w] << endl;

    return 0;
}