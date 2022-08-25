#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

ll n,q;
vector<ll> in;
vector<ll> out;
vector<ll> val;
vector<ll> v;
vvi arr;
int timer = 0;

void dfs(ll src,ll parent){
    in[src] = timer++;
    // v.push_back(src);
    for(auto child:arr[src]){
        if(child != parent){
            dfs(child,src);
        }
    }
    out[src] = timer++;
    // v.push_back(src);
}

void update(ll idx,ll val){
    for(ll i=idx;i<2*n;i += i&-i)
        v[i] += val;
}

ll query(ll idx){
    ll sum = 0;
    for(ll i=idx;i>0;i -= i&-i)
        sum += v[i];
    return sum;
}

void print(vector<ll> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    cin >> n >> q;
    in.resize(n);
    out.resize(n);
    val.resize(n);
    arr.resize(n);
    for(ll i=0;i<n;i++){
        cin >> val[i];
    }
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(0,-1);

    v.resize(2*n);
    print(in);
    print(out);
    for(ll i=0;i<n;i++){
        update(in[i],val[i]);
    }
    for(ll i=0;i<n;i++){
        update(out[i],-val[i]);
    }

    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll s,x;
            cin >> s >> x;
            s--;
            update(out[s],-val[s]);
            val[s] = x;
            update(out[s],val[s]);
        }else{
            ll s;
            cin >> s;
            s--;
            cout << query(in[s]) << endl;
        }
    }



    return 0;
}