#include "bits/stdc++.h"
using namespace std;
// memoization or top-down
// TC --> O(N)
// SC --> O(N) /*Stack Space*/ + O(N) /*dp array*/
int fibonacci(int n,vector<int> &dp){
    if(n == 0 or n == 1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}
// Tabulation or bottom up
// TC --> O(N)
// SC --> O(N) /*dp array*/
int fibonacci_tabulation(int n){
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// space optimization Tabulation
// TC --> O(N)
// SC --> O(1)
int fibonacci_space_optimized(int n){
    int prev1 = 0, prev2 = 1;
    int fib;
    for(int i=2;i<=n;i++){
        fib = prev2 + prev1;
        prev1 = prev2;
        prev2 = fib;
    }
    return fib;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fibonacci(n,dp) << endl;
    cout << fibonacci_tabulation(n)  << endl;
    cout << fibonacci_space_optimized(n) << endl;
    
    return 0;
}