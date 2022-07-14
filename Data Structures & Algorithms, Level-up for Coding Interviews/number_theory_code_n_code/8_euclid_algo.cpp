#include "bits/stdc++.h"
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    // Let GCD of A and B =g
    // Observation 1:GCD(A, 0)= GCD(0, A) =A
    // Observation 2:GCD(A, B) = GCD(B, A)
    // Observation 3: GCD(A, B) = GCD(A-B,B) = GCD(A, B-A) // IMP observation
    return 0;
}