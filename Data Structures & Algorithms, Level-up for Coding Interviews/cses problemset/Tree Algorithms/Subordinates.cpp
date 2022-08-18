#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007
vector<vector<int>> arr;

vector<int> ans;

void dfs(int src,int parent){
    for(auto child:arr[src]){
        if(child != parent){
            ans[src]++;
            dfs(child,src);
            ans[src] += ans[child];
        }
    }
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;

    arr.resize(n+1);
    ans = vector<int>(n+1,0);

    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        arr[x].push_back(i);
    }

    dfs(1,-1);
    ans.erase(ans.begin());

    print(ans);





    return 0;
}