#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
public:
    vector<int> seg;
    SegmentTree(int n){
        seg.resize(4*n+2); // segment tree size is 4*n
    }

    // TC --> O(4*N)
    void buildSegmentTree(int i,int low,int high,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        buildSegmentTree(2*i+1,low,mid,arr);
        buildSegmentTree(2*i+2,mid+1,high,arr);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }

    // TC --> O(logN)
    int rangeMinQuery(int i,int low,int high,int l,int r){
        // no overlap
        if(high < l or r < low)return INT_MAX;
        // complete overlap
        if(low >= l and high <= r)return seg[i];
        // partial overlap
        int mid = (low + high) / 2;
        int left = rangeMinQuery(2*i+1,low,mid,l,r);
        int right = rangeMinQuery(2*i+2,mid+1,high,l,r);
        return min(left,right);
    }

    // TC --> O(logN)
    void pointUpdate(int i,int low,int high,int idx,int val){
        if(low == high){
            seg[i] = val;
            return;
        }
        int mid = (low + high) / 2;
        if(idx <= mid)pointUpdate(2*i+1,low,mid,idx,val);
        else pointUpdate(2*i+2,mid+1,high,idx,val);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }
};

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTree sgt(n);
    sgt.buildSegmentTree(0,0,n-1,arr);
    // You'r give q queries.
    // Each querie has 2 types.
    // Type 1: Given l,and r --> find minimum in the range [l,r]
    // Type 2: Given idx, val --> update arr[idx] = val
    // Range Minimum Queries (RMQ)
    int q;
    cin >> q;
    while (q--){
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1)
            cout << sgt.rangeMinQuery(0,0,n-1,l,r) << endl;
        else
            sgt.pointUpdate(0,0,n-1,l,r);
    }

    return 0;
}