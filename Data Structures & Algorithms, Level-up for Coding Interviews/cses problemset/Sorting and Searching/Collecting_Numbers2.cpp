#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n,m;
    cin >> n >> m;
    vi arr(n);
    vi brr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
        brr[arr[i]] = i;
    }
    int cnt = 1;
    set<pair<int,int>> s;
    for(int i=1; i<n;i++){ 
        if(brr[i] < brr[i-1]){
            s.insert({i-1,i});
            cnt++;
        }
    }

    while(m--){
        int a,b;
        cin >> a >> b;
        if(a == b){
            cout << cnt << endl;
            continue;
        }
        a--,b--;
        int i1 = arr[a], i2 = arr[b];
        swap(arr[a], arr[b]);
        swap(brr[i1], brr[i2]);
        if(i1 > i2)swap(i1,i2);
        if(i1-1 >= 0 and brr[i1] < brr[i1-1]){
            if(s.count({i1-1,i1}) == 0){
                s.insert({i1-1,i1});
                cnt++;
            }
        }else if(i1-1 >=0 and brr[i1] > brr[i1-1]){
            if(s.count({i1-1,i1}) != 0){
                s.erase({i1-1,i1});
                cnt--;
            }
        }
        
        if(i1+1 < n and brr[i1+1] < brr[i1]){
            if(s.count({i1,i1+1}) == 0){
                s.insert({i1,i1+1});
                cnt++;
            }
        }else if(i1+1 < n and brr[i1+1] > brr[i1]){
            if(s.count({i1,i1+1}) != 0){
                s.erase({i1,i1+1});
                cnt--;
            }
        }

        if(i2-1 >= 0 and brr[i2] < brr[i2-1]){
            if(s.count({i2-1,i2}) == 0){
                s.insert({i2-1,i2});
                cnt++;
            }
        }else if(i2-1 >=0 and brr[i2] > brr[i2-1]){
            if(s.count({i2-1,i2}) != 0){
                s.erase({i2-1,i2});
                cnt--;
            }
        }

        if(i2+1 < n and brr[i2+1] < brr[i2]){
            if(s.count({i2,i2+1}) == 0){
                s.insert({i2,i2+1});
                cnt++;
            }
        }else if(i2+1 < n and brr[i2+1] > brr[i2]){
            if(s.count({i2,i2+1}) != 0){
                s.erase({i2,i2+1});
                cnt--;
            }
        }

        cout << cnt << endl;
    }
    
    return 0;
}