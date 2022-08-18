#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int n;
vvi arr;

int limit;
vi lvl;
vvi parent;

int findPar(int node,int k){
    if(node == -1)return -1;
    if(k == 0)return node;
    int log_val = log2(k);
    int max_val = pow(2,log_val);
    return findPar(parent[node][log_val],k-max_val);
}

void dfs(int src,int parent,int level){
    lvl[src] = level;
    for(auto child:arr[src]){
        if(child != parent){
            dfs(child,src,level+1);
        }
    }
}

int lca(int a,int b){
    if(lvl[b] < lvl[a])
        swap(a,b);
    int d = lvl[b] - lvl[a];

    while(d>0){
        int i = log2(d);
        b = parent[b][i];
        d -= (1<<i);
    }

    if(a == b)return a;

    for(int i=limit;i>=0;i--){
        if(parent[a][i] != -1 and parent[a][i] != parent[b][i]){
            a = parent[a][i], b = parent[b][i];
        }
    }

    return parent[a][0];
}


// int lca(int a,int b){
//     int level1 = lvl[a], level2 = lvl[b];
//     if(level2 < level1)
//         swap(level2,level1);
    
//     int d = level2 - level1;
//     b = findPar(b,d);

//     if(a == b)return a;

//     for(int i=limit-1;i>=0;i--){
//         if(parent[a][i] != -1 and parent[a][i] != parent[b][i]){
//             a = parent[a][i];
//             b = parent[b][i];
//         }
//     }

//     return parent[a][0];
// }

void print(vvi v){
    for(auto i:v){
        for(auto j:i)cout << j << " ";
        cout << endl;
    }
}

void print1(vi v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int q;
    cin >> n >> q;
    limit = log2(n+1);
    parent = vvi(n+1,vi(limit+1,-1));
    lvl = vi(n+1,0);
    arr.resize(n+1);

    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        arr[x].push_back(i);
        parent[i][0] = x; // 2^0th parent of i
    }

    for(int i=1;i<=limit;i++){  
        for(int j=1;j<=n;j++){
            int x = parent[j][i-1];
            if(x == -1)parent[j][i] = -1;
            else parent[j][i] = parent[x][i-1];
        }
    }

    dfs(1,-1,0);

    // print(parent);
    // print1(lvl);

    while(q--){
        int a,b;
        cin >> a >> b;

        cout << lca(a,b) << endl;
    }

    return 0;
}