#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

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
    seg[i] = max(seg[2*i],seg[2*i+1]);
}

int query(int i,int low,int high)

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> arr[i];

    build(1,1,n);

    while(q--){
        int k;
        cin >> k;
    }


    return 0;
}