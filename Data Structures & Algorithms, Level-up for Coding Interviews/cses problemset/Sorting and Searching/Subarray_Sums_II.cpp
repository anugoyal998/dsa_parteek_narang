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
    int x;
    cin >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    ll sum = 0;
    unordered_map<ll,int> mp;
    mp[0]++;
    ll count = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        count += mp[sum-x];
        mp[sum]++;
    }
    cout << count << endl;
 
    return 0;
}