#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    // https://www.codechef.com/problems/RAMDEV
	// your code goes here
	ll l,b;
	cin >> l >> b;
	ll n;
	cin >> n;
	vector<pair<ll,ll>> arr;
	for(ll i=0;i<n;i++){
	    ll a,b;
	    cin >> a >> b;
	    arr.push_back({a,b});
	}
	ll ans = 0;
	for(auto p:arr){
	    ll row = p.first / l;
	    ll col = p.second / b;
	    ll ans1 = row * col;
	    row = p.first / b;
	    col = p.second / l;
	    ll ans2 = row * col;
	    ans += max(ans1,ans2);
	}
	cout << ans << endl;
	return 0;
}
