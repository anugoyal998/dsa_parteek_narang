#include "bits/stdc++.h"
using namespace std;

void dfs(vector<vector<int>> arr,vector<int> &vis,int timer,vector<int> &inTime, vector<int> &outTime,int src){
    vis[src] = 1;
    inTime[src] = timer++;
    for(auto i:arr[src]){
        if(!vis[i])dfs(arr,vis,timer,inTime,outTime,i);
    }
    outTime[src] = timer++;
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    // In time --> time when dfs call starts
    // Out time --> time when dfs call ends
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> vis(n,0);
    vector<int> inTime(n);
    vector<int> outTime(n);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(arr,vis,1,inTime,outTime,i);
        }
    }
    print(inTime);
    print(outTime);

    return 0;
}