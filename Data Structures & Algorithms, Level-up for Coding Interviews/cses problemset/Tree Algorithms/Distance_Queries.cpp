#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>


void dfs(ll node,ll lvl,ll par,vvi arr,vi &level,vvi &lca){
    level[node] = lvl;
    lca[node][0] = par;

    for(ll child : arr[node]){
        if(child != par){
            dfs(child,lvl+1,node,arr,level,lca);
        }
    }
}

void init(vvi arr,ll n,vvi &lca,vi &level,ll maxN){
    dfs(1,0,-1,arr,level,lca);
    for(ll i=1;i<=maxN;i++){
        for(ll j=1;j<=n;j++){
            if(lca[j][i-1] != -1){
                ll par = lca[j][i-1];
                lca[j][i] = lca[par][i-1]; // dp
            }
        }
    }
}

ll getLCA(ll a,ll b,vi level,vvi lca,ll maxN){
    if(level[b] < level[a])
        swap(a,b);
    ll d = level[b] - level[a];

    while(d>0){
        ll i = log2(d);
        b = lca[b][i];
        d -= 1 << i;
    }

    if(a == b)return a;

    for(ll i=maxN;i>=0;i--){
        if(lca[a][i] != -1 and lca[a][i] != lca[b][i]){
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}

ll getDist(ll a,ll b,vi level,vvi lca,ll maxN) {
    ll __lca = getLCA(a,b,level,lca,maxN);
    return level[a] + level[b] - 2 * level[__lca];
}

void solve(){

    ll n,q;
    cin >> n >> q;
    vvi arr(n+1);

    for(ll i=2;i<=n;i++){
        ll a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    ll maxN = ceil(log2(n));
    vi level(n+1);
    vvi lca(n+1,vi(maxN+1,-1));
    init(arr,n,lca,level,maxN);

    while (q--){
        ll a,b;
        cin >> a >> b;
        cout << getDist(a,b,level,lca,maxN) << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
    solve();
}