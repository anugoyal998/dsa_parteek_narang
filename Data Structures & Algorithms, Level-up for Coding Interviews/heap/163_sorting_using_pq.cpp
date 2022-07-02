#include "bits/stdc++.h"
using namespace std;

class Compare{
    public:
    bool operator()(int a,int b){
        return a > b; // increasing order
    }
};

int main(){
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr) / sizeof(int);
    priority_queue<int> max_heap; // max heap
    // priority_queue<int,vector<int>,greater<int>> min_heap; // min heap
    priority_queue<int,vector<int>,Compare> min_heap; // min heap
    for(int x:arr)max_heap.push(x);
    for(int x:arr)min_heap.push(x);
    while(!max_heap.empty()){
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;
    while(!min_heap.empty()){
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    return 0;
}