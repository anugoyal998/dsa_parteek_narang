// https://leetcode.com/problems/sliding-window-maximum/
#include "bits/stdc++.h"
using namespace std;

void slidingWindowMax(vector<int> a,int k){
    deque<int> q(k);
    int i;
    int n = a.size();
    // 1. Process only K elements
    for(i=0;i<k;i++){
        while(!q.empty() and a[i] > a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // 2. Process remaining elements
    for(;i<n;i++){
        cout << a[q.front()] << " " ;
        // remove element from the left
        while(!q.empty() and q.front() <= i-k){
            q.pop_front();
        }
        while(!q.empty() and a[i] >= a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << a[q.front()] << endl ;
}

int main(){
    return 0;
}