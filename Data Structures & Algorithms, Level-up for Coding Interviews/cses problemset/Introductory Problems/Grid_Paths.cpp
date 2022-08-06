#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

vvi vis(7,vi(7,0));

map<char,pair<int,int>> mp;

vi dx = {0,0,-1,1};
vi dy = {-1,1,0,0};

bool isSafe(int i,int j){
    if(i<0 or j<0 or i==7 or j==7)return false;
    return vis[i][j] == 0;
}

// ??????R??????U??????????????????????????LD????D?

int help(int i,int j,int idx,string s){
    if(idx == 48){
        if(i == 7 and j == 0)return 1;
        return 0;
    }
    vis[i][j] = 1;
    int ans = 0;
    if(s[idx] != '?'){
        int row = i + mp[s[idx]].first;
        int col = j + mp[s[idx]].second;
        if(isSafe(row,col)){
            ans += help(row,col,idx+1,s);
        }
    }else{
        for(int k=0;k<4;k++){
            int row = i+dx[k];
            int col = j+dy[k];
            if(isSafe(row,col))ans += help(row,col,idx+1,s);
        }
    }
    vis[i][j] = 0;
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    string s;
    cin >> s;
    mp['U'] = {-1,0};
    mp['D'] = {1,0};
    mp['L'] = {0,-1};
    mp['R'] = {0,1};

    cout << help(0,0,0,s);

    return 0;
}