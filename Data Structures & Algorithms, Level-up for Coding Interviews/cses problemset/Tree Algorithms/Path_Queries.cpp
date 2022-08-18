#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define mod 1000000007

ll n;
vi v;
vvi arr;
vi val;

vi b;

void fill(vi x){
    for(auto i:x)v.push_back(i);
}

void dfs(int src,int par,vi x){
    x.push_back(src);
    v.push_back(src);
    bool flag = false;
    for(auto child:arr[src]){
        if(child != par){
            if(flag){
                fill(x);
            }
            dfs(child,src,x);
            flag = true;
        }
    }
}

void update(ll idx,ll val){
    for(ll i=idx;i<2*n;i += i&-i)
        b[i] += val;
}

ll query(ll idx){
    ll sum = 0;
    for(ll i=idx;i>0;i -= i&-i)
        sum += b[i];
    return sum;
}

void print(vi x){
    for(auto i:x)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    ll q;
    cin >> n >> q;
    val.resize(n);
    arr.resize(n);
    for(int i=0;i<n;i++)cin >> val[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(0,-1,{});
    // print(v);

    while(q--){
        ll type;
        cin >> type;
        if(type == 1){

        }
    }




    return 0;
}