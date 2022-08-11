#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

    int n,m;
    cin >> n >> m;
    ordered_set<int> s;
    for(int i=0;i<n; i++){
        int a;cin >> a;
        s.insert(a);
    }
    vector<int> brr(m);
    for(int i=0;i<m;i++)cin >> brr[i];
    for(auto ele:brr){
        if(s.find(ele) != s.end()){
            cout << ele << endl;
            s.erase(ele);
        }else{
            int val = s.order_of_key(ele);
            if(val > 0){
                auto it = s.find_by_order(val-1);
                cout << *it << endl;
                s.erase(it);
            }else cout << -1 << endl;
        }
    }

    return 0;
}