#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

void dfs(vector<vector<pair<int, int> > > arr,vi &vis,int node,stack<int> &st){
    vis[node] = 1;
    for(auto p:arr[node]){
        if(!vis[p.first]){
            dfs(arr,vis,p.first,st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> arr(n);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        arr[u].push_back({v,wt});
    }
    int src;
    cin >> src;
    vi vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(arr,vis,i,st);
        }
    }
    vi dist(n,INT_MIN);
    dist[src] = 0;
    while(st.size()){
        int u = st.top();
        st.pop();
        if(dist[u] == INT_MIN)continue;
        for(auto p:arr[u]){
            if(dist[u]+p.second > dist[p.first]){
                dist[p.first] = dist[u] + p.second;
            }
        }
    }

    for(auto i:dist){
        cout << i << " ";
    }
    return 0;
}