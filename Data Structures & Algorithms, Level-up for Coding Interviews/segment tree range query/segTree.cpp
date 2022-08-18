#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
    int n;
    vector<int> seg;
    public:
    SegmentTree(int n){
        this->n = n;
        seg.resize(4*n+2);
    }

    void build(int i,int low,int high,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = low + (high-low) / 2;
        build(2*i+1,low,mid,arr);
        build(2*i+2,mid+1,high,arr);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }

    int query(int i,int low,int high,int l,int r){
        // no overlap
        if(r < low or high < l)return INT_MAX;
        // complete overlap
        if(low >= l and high <= r)return seg[i];
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);
        return min(left,right);
    }

    void update(int i,int low,int high,int index,int val){
        if(low == high){
            seg[i] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(index <= mid)
            update(2*i+1,low,mid,index,val);
        else
            update(2*i+2,mid+1,high,index,val);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }


};

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
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
            int i,val;
            cin >> i >> val;
            st.update(0,0,n-1,i,val);
            arr[i] = val;
        }
    }


    return 0;
}