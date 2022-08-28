#include "bits/stdc++.h"
using namespace std;

int getIthBit(int n,int i){
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}

void setIthBit(int &n,int i){
    int mask = (1<<i);
    n |= mask;
}

void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n &= mask;
}

void clearLastIBits(int &n,int i){
    int mask = (-1<<i);
    n &= mask;
}

int countSetBits(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n = (n&(n-1));
    }
    return cnt;
}

int main(){
    cout << countSetBits(9) << endl;
    return 0;
}