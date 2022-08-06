#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

bool isSafe(int i,int j,vvi arr){
    int n = 8;
    for(int k=0;k<n;k++){
        if(arr[k][j]==1)return 0;
    }
    int row = i;
    int col = j;
    while(row>=0 and col>=0){
        if(arr[row][col] == 1)return 0;
        row--;col--;
    }
    row = i;
    col = j;
    while(row>=0 and col<n){
        if(arr[row][col] == 1)return 0;
        row--;col++;
    }
    return 1;
}

int help(int i,vvi arr){
    if(i == 8)return 1;
    int ans = 0;
    for(int j=0;j<8;j++){
        if(arr[i][j] == -1)continue;
        if(isSafe(i,j,arr)){
            arr[i][j] = 1;
            ans += help(i+1,arr);
            arr[i][j] = 0;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    vvi arr(8,vi(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char ch;
            cin >> ch;
            if(ch == '.')arr[i][j] = 0;
            else arr[i][j] = -1;
        }
    }
    cout << help(0,arr);
    return 0;
}