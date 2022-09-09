#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    bool flag = false;
    if(n < 0)
        flag = true;
    n = abs(n);
    vector<int> arr;
    int temp = n;
    while(temp){
        int rem = temp % 10;
        arr.push_back(rem);
        temp /= 10;
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    if(arr[0] == 0){
        int i = 0;
        for(;i<arr.size();i++){
            if(arr[i] != 0)break;
        }
        ans = arr[i];
        for(int j=0;j<arr.size();j++){
            if(j != i){
                ans = ans*10 + arr[j];
            }
        }
    }else{
        for(int j=0;j<arr.size();j++){
            ans = ans*10 + arr[j];
        }
    }
    if(flag)
        ans *= -1;

    cout << ans << endl;

    return 0;
}