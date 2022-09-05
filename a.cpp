#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll N = 1e4+2;
ll p = 31;
ll m = 1e9+7;

void print(vector<ll> v){
    for(auto i:v)cout << i << " ";
}

int repeatedStringMatch(string a, string b) {
    vector<ll> powers(N);
    powers[0] = 1;
    for(int i=1;i<N;i++){
        powers[i] = (powers[i-1] * p) % m;
    }
    
    int m = a.length(), n = b.length();
    
    vector<ll> hash(n+1,0);
    for(int i=0;i<n;i++){
        ll temp = ((b[i] - 'a' + 1) * powers[i]);
        // cout << temp << " ";
        hash[i+1] = (hash[i] + temp) ;
    }
    
    print(hash);
    
    
    
    
    
    return 0;
}

int main(){

    string a,b;
    cin >> a >> b;
    repeatedStringMatch(a,b);
    
    return 0;
}