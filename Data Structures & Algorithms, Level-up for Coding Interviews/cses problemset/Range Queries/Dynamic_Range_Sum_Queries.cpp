#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int n;
const int N = 200001;

ll bit[N];

void update(int index,int val){
    for(int i=index;i<=n;i += (i&(-i))){
        bit[i] += val;
    }
}

ll query(int index){
    ll ans = 0;
    for(int i=index;i>0;i -= (i&(-i))){
        ans += bit[i];
    }
    return ans;
}


int main(){
    // https://codeforces.com/blog/entry/61364
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int q;
    cin >> n >> q;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin >> arr[i];
    for(int i=1;i<=n;i++)
        update(i,arr[i]);

    while(q--){
        int type;
        cin >> type;
        if(type == 2){
            int l,r;
            cin >> l >> r;
            cout << query(r) - query(l-1) << endl;
        }else{
            int index, val;
            cin >> index >> val;
            update(index,-arr[index]);
            arr[index] = val;
            update(index,arr[index]);
        }
    }


    return 0;
}