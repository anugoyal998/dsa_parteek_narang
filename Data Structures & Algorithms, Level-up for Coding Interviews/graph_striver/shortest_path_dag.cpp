#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>


void print(vi v){
    for(auto it:v)
        cout << it << " ";
    cout << endl;
}

void topoSort(int node,vector<pair<int,int>> arr[],int vis[],stack<int> &st){
    vis[node] = 1;
    for(auto it:arr[node]){
        if(!vis[it.first]){
            topoSort(it.first,arr,vis,st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> arr[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        arr[u].push_back({v,wt});
    }
    int vis[n] = {0};
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,arr,vis,st);
        }
    }

    vector<int> dist(n,INT_MAX);
    dist[0] = 0; 
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it:arr[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    print(dist);

    return 0;
}