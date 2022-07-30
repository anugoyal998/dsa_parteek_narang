#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll kthParent(ll node,vector<vector<ll>> parent,ll k){
    if(k == 0)return node;
    ll log_val = log2(k);
    ll max_val = pow(2,log_val);
    return kthParent(parent[node][log_val],parent,k-max_val);
}

int main(){
    ll n,q;
    cin >> n >> q;
    ll limit = 30;
    vector<vector<ll>> parent(n+1,vector<ll>(35));
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        parent[i][0]  = x;
    }

    for(ll i=1;i<=limit;i++){
        for(ll j=1;j<=n;j++){
            ll x = parent[j][i-1];
            parent[j][i] = parent[x][i-1];
        }
    }

    for(ll i=0;i<q;i++){
        ll node,k;
        cin >> node >> k;
        cout << kthParent(node,parent,k) << endl;
    }
    return 0;
}