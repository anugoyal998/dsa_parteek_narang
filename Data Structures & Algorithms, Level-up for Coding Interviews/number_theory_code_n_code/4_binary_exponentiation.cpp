#include "bits/stdc++.h"
using namespace std;

long long int fast_pow(int x,int y,long long int m/* modulo*/ = 1000000007){
    long long int res = 1;
    long int a = 1LL*x;
    long long int n = 1LL*y;

    while(n){
        if(n&1){
            res = (res * (a % m)) % m, n--;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }
    return res;
}

int main(){
    int a,n;
    cin >> a >> n;
    cout << fast_pow(a,n) << endl;
    return 0;
}