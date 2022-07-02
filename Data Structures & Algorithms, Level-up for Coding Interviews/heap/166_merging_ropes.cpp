#include "bits/stdc++.h"
using namespace std;

int main(){
    // Given N Ropes each having a different size, your task is
    // join the ropes together. The cost of joining 2 ropes of
    // different sizes X and Y is (X+Y). Find the minimum cost to
    // join all the ropes together.   

    int n;
    cin >> n;
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    while(!pq.empty() and pq.size() > 1){
        int t1 = pq.top();pq.pop();
        int t2 = pq.top();pq.pop();
        int sum = t1 + t2;
        pq.push(sum);
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}