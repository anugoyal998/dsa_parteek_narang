#include "bits/stdc++.h"
using namespace std;
#define loop(i,n) for(int i = 0; i < n; i++)
#define vvi vector<vector<int> >
#define vi vector<int>

void mul(vvi &A, vvi B,int dim){
    vvi res(dim,vi(dim));

    loop(i,dim){
        loop(j,dim){
            res[i][j] = 0;
            loop(k,dim)
                res[i][j] += A[i][k] * B[k][j];
        }
    }

    loop(i,dim)loop(j,dim) A[i][j] = res[i][j];
}

void power(vvi &A,int dim,int n){
    vvi I(dim,vi(dim));
    loop(i,dim)loop(j,dim){
        if(i == j)
            I[i][j] = 1;
        else 
            I[i][j] = 0;
    }

    // loop(i,n)
    //     mul(I,A,dim);

    while(n){
        if(n&1)
            mul(I,A,dim),n--;
        mul(A,A,dim),n/=2;
    }

    loop(i,dim)loop(j,dim) A[i][j] = I[i][j];
}

void print(vvi a){
    for(auto i:a){
        for(auto j:i) cout << j <<  " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    // Time Complexity O(M^3 * logN)

    int t;
    cin >> t;
    while(t--){
        int dim,n;
        cin >> dim >> n;
        vvi arr(dim,vi(dim));
        loop(i,dim)loop(j,dim) cin >> arr[i][j];
        power(arr,dim,n);
        print(arr);
    }
    return 0;
}