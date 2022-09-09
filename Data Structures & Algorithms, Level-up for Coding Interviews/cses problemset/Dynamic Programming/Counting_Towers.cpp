#include <iostream>
using namespace std;
#define ll long long

const int mod = 1e9+7;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    // dp[i][0] = number of ways to fill rows from (i to n) s.t. last row had 2 growing blocks
    // dp[i][1] = number of ways to fill rows from (i to n) s.t. last row had a (1 * 1) type of growing block

    // for dp[i][0]

    // pos1: close both blocks --> dp[i+1][0] + dp[i+1][1]
        // pos11: start 2 blocks of 1 * 1 each
        // dp[i+1][0]
        // pos12: start 1 block of 1 * 2
        // dp[i+1][1]
    
    // pos2: don't close  any of them --> dp[i+1][0]

    // pos3 and pos4: close one of them --> 2 * dp[i+1][0]

    // dp[i][0] = pos1 + pos2 + pos3 + pos4
    //          = dp[i+1][0] + dp[i+1][1] + dp[i+1][0] + 2 * dp[i+1][0]
    //          = 4 * dp[i+1][0] + dp[i+1][1]

    // for dp[i][1]

    // pos1: close the complete block:
        // pos11: start 2 blocks of 1*1 each
        // dp[i+1][0]
        // pos12: start 1 block of 1*2 
        // dp[i+1][1]

    // pos2: don't close the block --> dp[i+1][1]

    // dp[i][1] = pos1 + pos2
    //          = dp[i+1][0] + dp[i+1][1] + dp[i+1][1]
    //          = 2 * dp[i+1][1] + dp[i+1][0]

    // base case: 
    // dp[n-1][0] =  dp[n-1][1] = 1

    // final subproblem
    // dp[0][0] + dp[0][1]

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a = 1, b = 1;
        for(ll i=n-2;i>=0;i--){
            ll pos1 = ((4 * a) % mod + b) % mod;
            ll pos2 = ((2 * b) % mod + a) % mod;
            a = pos1;
            b = pos2;
        }
        ll ans = (a + b) % mod;
        cout << ans << endl;
    }

    return 0;
}