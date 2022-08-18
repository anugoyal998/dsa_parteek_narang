#include "bits/stdc++.h"
using namespace std;
 
const int N = 200001;
int arr[N];
int seg[4*N];
 
void build(int i,int low,int high){
    if(low == high){
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2*i,low,mid);
    build(2*i+1,mid+1,high);
    seg[i] = min(seg[2*i],seg[2*i+1]);
}
 
int query(int i,int low,int high,int l,int r){
    // no overlap
    if(l > high or r < low)
        return INT_MAX;
    // complete overlap
    if(low >= l and high <= r)
        return seg[i];
    // partial overlap
    int mid = (low + high) >> 1;
    int left = query(2*i,low,mid,l,r);
    int right = query(2*i+1,mid+1,high,l,r);
    return min(left,right);
}

void update(int i,int low,int high,int index){
    if(low == high){
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    if(index <= mid)
        update(2*i,low,mid,index);
    else 
        update(2*i+1,mid+1,high,index);
    seg[i] = min(seg[2*i],seg[2*i+1]);
}
 
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #else
    #endif
 
    
    int n,q,a,b,type;
    cin >> n >> q;
 
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
 
    build(1,1,n);
 
    while(q--){
        cin >> type >> a >> b;
        if(type == 1){
            arr[a] = b;
            update(1,1,n,a);
        }else{
            cout << query(1,1,n,a,b) << endl;
        }
    }
 
 
    return 0;
}