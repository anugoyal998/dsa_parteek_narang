#include "bits/stdc++.h"
using namespace std;

vector<int> arr;
vector<vector<int>> seg;

void build(int idx,int low,int high){
    if(low==high){
        seg[idx].push_back(arr[low]);
        return;
    }

    int mid = (low + high) / 2;
    build(2*idx,low,mid);
    build(2*idx+1,mid+1,high);

    int i = 0, j = 0;
    while(i<seg[2*idx].size() and j<seg[2*idx+1].size()){
        if(seg[2*idx][i] <= seg[2*idx+1][j])
            seg[idx].push_back(seg[2*idx][i]), i++;
        else
            seg[idx].push_back(seg[2*idx+1][j]), j++;
    }

    while(i<seg[2*idx].size())
        seg[idx].push_back(seg[2*idx][i]), i++;
    while(j<seg[2*idx+1].size())
        seg[idx].push_back(seg[2*idx+1][j]), j++;
}

int query(int idx,int low,int high,int l,int r,int k){
    if(low > r or high < l)return 0;
    if(low >= l and high <= r){
        int res = upper_bound(seg[idx].begin(),seg[idx].end(),k-1) - seg[idx].begin();
        return res;
    }

    int mid = (low + high) / 2;
    int left = query(2*idx,low,mid,l,r,k);
    int right = query(2*idx+1,mid+1,high,l,r,k);
    return left + right;
}

int main(){
    // Given an array of size N and Q queries of form L, R, K, find number of elements in the range
    // Lto R which are strictly smaller than K   
    // SC --> O(NlogN)
    int n;
    cin >> n;
    arr.resize(n+1);
    seg.resize(4*n+2);
    for(int i = 1; i <= n;i++)cin >> arr[i];
    build(1,1,n);
    int q;
    cin >> q;
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        cout << query(1,1,n,l,r,k) << endl;
    }


    return 0;
}