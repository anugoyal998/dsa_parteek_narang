#include "bits/stdc++.h"
using namespace std;

int main(){
    // https://atcoder.jp/contests/dp/tasks/dp_b
    // TC --> O(N*K)
    // SC --> O(K)
    int n,k;   
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    
    list<int> dp;
    dp.push_back(0);
    for(int i=1;i<n;i++){
        int ans = INT_MAX;
        int j = i-1;
        auto it = dp.end();
        it--;
        for(;j>=0 and j>=i-k;it--,j--){
            int val = *it + abs(arr[i]-arr[j]);
            ans = min(ans,val);
        }
        if(i>=k)
            dp.pop_front();
        dp.push_back(ans);
    }
    cout << dp.back() << endl;
    return 0;
}