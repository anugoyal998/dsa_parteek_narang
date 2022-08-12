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
 
    int n,m;
    cin >> n >> m;
    multiset<int> s;
    for(int i=0;i<n; i++){
        int a;cin >> a;
        s.insert(a);
    }
    vector<int> brr(m);
    for(int i=0;i<m;i++)cin >> brr[i];
 
    for(auto ele:brr){
        if(s.find(ele) != s.end()){
            cout << ele << endl;
            s.erase(s.find(ele));
        }else{
            auto it = s.lower_bound(ele);
            if(it == s.begin()){
                cout << -1 << endl;
            }else{
                it--;
                cout << *it << endl;
                s.erase(it);
            }
        }
    }
 
    return 0;
}