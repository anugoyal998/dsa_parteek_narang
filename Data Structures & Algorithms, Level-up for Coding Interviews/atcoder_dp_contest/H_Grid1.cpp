#include "bits/stdc++.h"
using namespace std;
int mod = 1e9+7;

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin >> ch;
            if(ch == '.')arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> cur(n,0);
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1)
                cur[j] = 0;
            else if(i == 0 and j == 0)
                cur[j] = 1;
            else{
                int up = 0, left = 0;
                if(i>0)up = prev[j];
                if(j>0)left = cur[j-1];
                cur[j] = (up + left) % mod;
            }
        }
        prev = cur;
    }
    cout << prev[n-1] << endl;
    return 0;
}