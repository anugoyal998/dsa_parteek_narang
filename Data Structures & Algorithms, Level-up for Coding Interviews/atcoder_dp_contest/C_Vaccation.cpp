#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int main(){
    int n;
    cin >> n;
    vvi arr(n);
    for(int i=0; i<n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[i].push_back(a);
        arr[i].push_back(b);
        arr[i].push_back(c);
    }
    vi dp = arr[0];
    for(int i=1;i<n;i++){
        vi temp = dp;
        temp[0] = arr[i][0] + max(dp[1],dp[2]);
        temp[1] = arr[i][1] + max(dp[0],dp[2]);
        temp[2] = arr[i][2] + max(dp[1],dp[0]);
        dp = temp;
    }
    cout << max({dp[0],dp[1],dp[2]}) << endl;
    return 0;
}