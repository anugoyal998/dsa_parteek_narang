#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

vvi arr;
int n;

vi dijkstra(int src){
    vi dist(n+1,INT_MAX);
    dist[0] = dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child:arr[node]){
            if(dist[child] > dist[node] + 1){
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    return dist;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    cin >> n;

    arr.resize(n+1);

    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vi first = dijkstra(1);
    int max1 = *max_element(first.begin()+1,first.end());

    int node = 0;
    for(int i=1;i<=n;i++){
        if(first[i] == max1){
            node = i;break;
        }
    }

    vi second = dijkstra(node);
    int max2 = *max_element(second.begin()+1,second.end());

    cout << max2 << endl;

    return 0;
}