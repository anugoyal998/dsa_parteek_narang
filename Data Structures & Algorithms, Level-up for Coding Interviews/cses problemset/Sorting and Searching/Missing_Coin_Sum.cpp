#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 1;
    for(int i=0;i<n and ans >= arr[i];i++)
        ans += arr[i];
    cout << ans << endl;


    return 0;
}