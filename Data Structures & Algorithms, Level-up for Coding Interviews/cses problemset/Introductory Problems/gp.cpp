#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

string s;

bool check(string a){
    if(a.length() != 48)return false;
    for(int i=0;i<48;i++){
        if(s[i] != '?' and s[i] != a[i])return false;
    }
    return true;
}

vector<pair<char,pair<int,int>>> d = {
    {'U',{-1,0}},
    {'D',{1,0}},
    {'L',{0,-1}},
    {'R',{0,1}}
};

bool isSafe(int i,int j){
    if(i<0 or j<0 or i==7 or j==7)return false;
    return true;
}

int help(int i,int j,string sof,vvi vis){
    if(i == 7 and j == 0){
        if(check(sof))return 1;
        return 0;
    }

    vis[i][j] = 1;
    int ans = 0;

    for(int k=0;k<4;k++){
        int row = i + d[k].second.first;
        int col = j + d[k].second.second;
        if(isSafe(row,col) and !vis[row][col])
            ans += help(row,col,sof+d[k].first,vis);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    cin >> s;

    vvi vis(7,vi(7,0));
    cout << help(0,0,"",vis);

    return 0;
}