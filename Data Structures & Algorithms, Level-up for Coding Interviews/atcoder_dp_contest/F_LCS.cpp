#include "bits/stdc++.h"
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.length(),m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++)dp[0][j] = 0;
    for(int j=0;j<=n;j++)dp[j][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
            ans = s[i-1] + ans;
            i--;j--;
        }else{
            int maxe = max(dp[i][j-1],dp[i-1][j]);
            if(dp[i][j-1] == maxe){
                j--;
            }else{
                i--;
            }
        }
    }
    cout << ans << endl;   
    return 0;
}