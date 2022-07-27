#include <bits/stdc++.h>
using namespace std;

int main() {
    // https://www.codechef.com/problems/CARSELL
	// your code goes here
	int t;
	cin >> t;
	int mod = 1e9+7;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)cin>>arr[i];
	    sort(arr.begin(),arr.end());
	    reverse(arr.begin(),arr.end());
	    int cnt = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        if(arr[i]-cnt <= 0)break;
	        ans = (ans + arr[i]%mod - cnt%mod)%mod;
	        cnt++;
	    }
	    cout << ans << endl;
	}
	return 0;
}
