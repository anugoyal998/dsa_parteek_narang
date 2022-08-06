#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

void help(vector<int> arr,vector<int> &vis,int element){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= element){
            
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> brr(m);
    for(int i=0; i<n;i++)cin >> arr[i];
    for(int i=0; i<m;i++)cin >> brr[i];
    sort(arr.begin(), arr.end());
    vector<int> vis(n,0);
    for(auto element:brr){
        int index = lower_bound(arr.begin(), arr.end(),element) - arr.begin();
        if(arr[index] > element){
            index--;
            if(index < 0)cout << -1 << endl;
            else{
                if(vis[index])cout << -1 << endl;
                else{
                    vis[index] = 1;
                    cout << arr[index] << endl;
                }
            }
        }else{
            if(vis[index])cout << -1 << endl;
            else{
                vis[index] = 1;
                cout << arr[index] << endl;
            }
        }
    }
    return 0;
}