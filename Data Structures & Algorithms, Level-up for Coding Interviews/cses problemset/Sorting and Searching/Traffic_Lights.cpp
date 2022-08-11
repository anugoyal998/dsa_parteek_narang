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
    int x,n;
    cin >> x >> n;
    set<int> pos;
    multiset<int> len;
    pos.insert(0);
    pos.insert(x);
    len.insert(x);
    for(int i=0; i<n; i++){
        int add;
        cin >> add;
        pos.insert(add);
        auto it = pos.find(add);
        int prevVal = *prev(it);
        int nextVal = *next(it);
        len.erase(len.find(nextVal-prevVal));
        len.insert(add-prevVal);
        len.insert(nextVal-add);
        cout << *len.rbegin() << endl;
    }
    return 0;
}