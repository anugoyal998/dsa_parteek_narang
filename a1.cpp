#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        int ele = arr[i];
        int x = sqrt(ele);
        int y = x * x;
        if(y == ele){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}