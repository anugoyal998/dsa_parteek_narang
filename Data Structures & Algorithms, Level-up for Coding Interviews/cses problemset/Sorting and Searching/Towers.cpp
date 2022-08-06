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
    multiset<ll> s;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        if(s.size() == 0)s.insert(x);
        else{
            auto it = lower_bound(s.begin(), s.end(),x+1);

            if(it == s.end()){
                s.insert(x);
            }else{
                s.erase(it);
                s.insert(x);
            }
        }
    }

    cout << s.size() << endl;


   return 0;
}