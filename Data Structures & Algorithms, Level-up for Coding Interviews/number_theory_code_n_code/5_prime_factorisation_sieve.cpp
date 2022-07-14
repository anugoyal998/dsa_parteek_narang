#include "bits/stdc++.h"
using namespace std;

void sieve(int n){
    vector<int> a(n+1,-1);

    for(int i=2;i<=n;i++){
        if(a[i] == -1){
            for(int j=i;j<=n;j+=i){
                if(a[j] == -1)
                    a[j] = i;
            }
        }
    }

    while(n!=1){
        cout << a[n] << " ";
        n /= a[n];
    }
    cout << 1 << endl;
}

int main(){
    // TC --> O(logN) for each query
    int n;
    cin >> n;
    sieve(n);

    
    return 0;
}