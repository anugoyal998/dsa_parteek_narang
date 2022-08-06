#include "bits/stdc++.h"
using namespace std;

const int N = 1e5+1;
vector<int> g[N];
int memo[N];

int dp(int src){
    int &ans = memo[src];
    if(ans != -1)return ans;
    ans = 0;
    for(auto x:g[src]){
        ans = max(ans,dp(x) + 1);
    }
    return ans;
}

int main(){
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	memset(memo, -1, sizeof(memo));

    int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp(i));
	}

	cout << ans;
    return 0;
}