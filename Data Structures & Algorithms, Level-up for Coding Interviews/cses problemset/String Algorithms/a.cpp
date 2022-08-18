#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif


    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> arr(k);
    for(int i=0; i<k; i++){
        cin >> arr[i];
    }
    int n = s.length();

    vector<int> hash(n);
    int d = 26;
    for(int i=0; i<n; i++){
        int num = s[i]-'a' + 1;
        if(i == 0){
            hash[i] = num;
        }else{
            hash[i] = (d * hash[i-1] + num) % mod;
        }
    }

    print(hash);

    for(auto str:arr){
        int hash_val = 0;
        for(auto ch:str){
            int num = ch - 'a' + 1;
            hash_val = (hash_val * d + num) % mod;
        }
        cout << hash_val << endl;
    }



    return 0;
}