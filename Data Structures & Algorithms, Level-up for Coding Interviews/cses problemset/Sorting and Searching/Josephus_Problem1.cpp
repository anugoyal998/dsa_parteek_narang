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
    indexed_set s;
    int n,k; cin>>n>>k;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    int ind = k%n;
    while(n--) {
        auto y = s.find_by_order(ind);
        cout<<*y<<' ';
        s.erase(y);
        if (n) ind = (ind%n + k)%n;
    } 
    return 0;
}