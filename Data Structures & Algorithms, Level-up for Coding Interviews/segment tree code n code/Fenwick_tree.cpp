#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

class BIT{
    int n;
    vector<int> bit;

public:

    BIT(int n){
        this->n = n;
        bit.resize(n+1);
    }

    void update(int index,int val){
        for(int i=index;i<=n;i += (i&(-i))){
            bit[i] += val;
        }
    }

    int query(int index){
        int ans = 0;
        for(int i=index;i>0;i -= (i&(-i))){
            ans += bit[i];
        }
        return ans;
    }
};

int main(){
    // https://codeforces.com/blog/entry/61364
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)cin >> arr[i];

    BIT bit(n);
    for(int i=1;i<=n;i++)
        bit.update(i,arr[i]);

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << bit.query(r) - bit.query(l-1) << endl;
        }else{
            int index, val;
            cin >> index >> val;
            bit.update(index,-arr[index]);
            arr[index] = val;
            bit.update(index,arr[index]);
        }
    }


    return 0;
}