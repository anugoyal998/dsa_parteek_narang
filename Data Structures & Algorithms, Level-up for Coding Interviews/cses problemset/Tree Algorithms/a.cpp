#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define mod 1000000007

ll n;
vi color;
vi in,out;
vi bit;
vvi arr;
ll timer = 0;

void print(vi v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

void dfs(int src,int par){
    in[src] = timer++;
    for(auto child:arr[src]){
        if(child != par){
            dfs(child,src);
        }
    }
    out[src] = timer++;
}


void update(ll idx){
    unordered_map<ll,ll> mp;
    for(ll i=idx;i<2*n;i += i&-i){
        mp[color[i]] = 1;
        bit[i] = mp.size();
    }
}

ll query(ll idx){
    ll sum = 0;
    for(ll i=idx;i>0;i -= i&-i)
        sum += bit[i];
    return sum;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    cin >> n;
    color.resize(n);
    in.resize(n);
    out.resize(n);
    arr.resize(n);

    for(int i = 0; i < n; i++)cin >> color[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(0,-1);

    bit.resize(2*n);

    for(int i=0;i<n;i++){
        update(out[i]);
    }
    print(in);
    print(out);
    print(bit);

    for(int i=0;i<n;i++){
        cout << query(out[i]) - query(in[i]) << " ";
    }

    return 0;
}