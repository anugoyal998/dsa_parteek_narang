#include "bits/stdc++.h"
using namespace std;
vector<int> arr;
vector<int> bit;

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int findSumTillI(int i){
    int ans =0;
    for(;i>0;i -= (i&(-i)))ans += bit[i];
    return ans;
}

void update(int i,int x,int n){
    for(;i<=n;i++i += (i&(-i)))bit[i] += x;
}

int main(){
    int n;
    cin >> n;
    arr.resize(n);
    bit.resize(n+1);
    for(int i=0; i<n; i++)cin >> arr[i];
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=0; i<n; i++)prefix[i] = arr[i] + prefix[i-1];

    bit[0] = 0;
    for(int i=1;i<=n;i++){
        int l = i - (i&(-i)) + 1;
        int r = i;
        bit[i] = prefix[r-1] - prefix[l-2];
    }

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            int sum_l = findSumTillI(l);
            int sum_r = findSumTillI(r);
            cout << sum_r - sum_l << endl;
        }else{
            int index, val;
            cin >> index >> val;
        }
    }

    



    return 0;
}