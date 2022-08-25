#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
    vector<int> seg;
    vector<int> lazy;
public:

    SegmentTree(int n){
        seg.resize(4*n+2);
        lazy.resize(4*n+2);
    }

    void build(int i,int low,int high,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*i+1,low,mid,arr);
        build(2*i+2,mid+1,high,arr);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i,int low,int high,int l,int r){
        // complete lazy
        if(lazy[i] != 0){
            int dx = lazy[i];
            lazy[i] = 0;
            seg[i] += dx * (high-low+1);

            if(low != high)
                lazy[2*i+1] += dx, lazy[2*i+2] += dx;
        }
        // no overlap
        if(l > high or r < low)
            return 0;
        // complete overlap
        if(low >= l and high <= r)
            return seg[i];
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);
        return left + right;
    }

    void update(int i,int low,int high,int l,int r,int val){
        if(lazy[i] != 0){
            int dx = lazy[i];
            lazy[i] = 0;
            seg[i] += dx * (high-low+1);

            if(low != high)
                lazy[2*i+1] += dx, lazy[2*i+2] += dx;
        }
        if(low > r or high < l)return;
        if(low >= l and high <= r){
            int dx = (high-low+1)*val;
            seg[i] += dx;
            if(low != high)
                lazy[2*i+1] += val, lazy[2*i+2] += val;
            return;
        }
        int mid = (low + high) >> 1;
        update(2*i+1,low,mid,l,r,val);
        update(2*i+2,mid+1,high,l,r,val);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
    #endif
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTree st(n);
    st.build(0,0,n-1,arr);
    while(q--){
        int type;
        cin >> type;
        if(type == 2){
            int k;
            cin >> k;
            int l = k-1, r = k;
            cout << st.query(0,0,n-1,l,r) << endl;
        }else{
            int l,r,val;
            cin >> l >> r >> val;
            st.update(0,0,n-1,l,r,val);
        }
    }

    return 0;
}