#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> parent;
vector<int> level;
int limit;

void print(vector<vector<int>> v){
    for(auto i:v){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
}

void print1(vector<int> v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

void dfs(int src,int par,int lvl){
    parent[src][0] = par;
    level[src] = lvl;
    for(auto child:arr[src]){
        if(child != par){
            dfs(child,src,lvl+1);
        }
    }
}

int getKthAncestor(int node,int k){
    if(node == -1)return -1;
    if(k == 0)return node;
    int log_val = log2(k);
    int max_val = pow(2,log_val);
    return getKthAncestor(parent[node][log_val],k-max_val);
}


int lca(int a,int b){
    int level1 = level[a],level2 = level[b];
    if(level2 < level1)
        swap(level2,level1);
    
    int d = level2 - level1;
    b = getKthAncestor(b,d);

    if(a == b)return a;

    for(int i=limit-1;i>=0;i--){
        if(parent[a][i] != -1 and parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    arr.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    limit = log2(n+1);
    parent = vector<vector<int>>(n+1,vector<int>(limit+1));
    level.resize(n+1);
    // 2^(0)th parent
    dfs(1,-1,0);

    for(int i=1;i<=limit;i++){
        for(int j=1;j<=n;j++){
            int x = parent[j][i-1];
            if(x == -1)parent[j][i] = -1;
            else parent[j][i] = parent[x][i-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        // find lca of a and b
        cout << lca(a,b) << endl;
    }

    return 0;
}