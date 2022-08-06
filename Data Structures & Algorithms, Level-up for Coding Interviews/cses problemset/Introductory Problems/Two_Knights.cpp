#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long int
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    ll n;
    cin >> n;
    if(n == 1)cout << 0 << endl;
    else if(n == 2){
        cout << 0 << endl;
        cout << 6 << endl;
    }else{
        cout << 0 << endl;
        cout << 6 << endl;
        for(ll i=3;i<=n;i++)  {
            ll x = i*i;
            ll ans = (x*(x-1))/2;
            ll y = i-2;
            ll sum = y*(y+1);
            sum *= 4;
            ans -= sum;
            cout << ans << endl;
        }
    }
    return 0;
}