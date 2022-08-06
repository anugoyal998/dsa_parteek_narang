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

    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        arr.push_back({start,1});
        arr.push_back({end,-1});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int ans = 0;
    for(auto i:arr){
        cnt += i.second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}