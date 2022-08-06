#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
    vector<int> st, lazy;
public:
    SegmentTree(int n){
        st.resize(4*n+2);
        lazy.resize(4*n+2);
    }

    void build(int ind,int low,int high, vector<int> arr){
        if(low == high){
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        st[ind] = st[2*ind+1] + st[2*ind+2];
    }

    void update(int ind,int low,int high,int l,int r,int val){
        // update previous remaining updates
        if(lazy[ind] != 0){
            st[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if(high < l or r < low){
            return;
        }
        // complete overlap
        if(low >= l and high <= r){
            st[ind] += (high - low + 1) * val;
            if(low != high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        // partial overlap
        int mid = (low + high) / 2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+1,mid+1,high,l,r,val);
        st[ind] = st[2*ind+1] + st[2*ind+2];
    }

    int query(int ind,int low,int high,int l,int r){
        // update previous remaining updates
        if(lazy[ind] != 0){
            st[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if(high < l or r < low){
            return 0;
        }
        // complete overlap
        if(low >= l and high <= r) return st[ind];
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(ind,low,mid,l,r);
        int right = query(ind,mid+1,high,l,r);
        return left + right;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    SegmentTree st(n);
    st.build(0,0,n-1,arr);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << st.query(0,0,n-1,l,r) << endl;
        }else{
            int l,r,val;
            cin >> l >> r >> val;
            st.update(0,0,n-1,l,r,val);
        }
    }



    return 0;
}