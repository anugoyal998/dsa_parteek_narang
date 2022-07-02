#include "bits/stdc++.h"
using namespace std;

vector<int> mergeKArrays(vector<vector<int> > arr){
    int k = arr.size();
    // triplet --> element, array idx, element idx
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > q;

    vector<int> output;
    // intialize heap
    for(int i=0; i<k; i++){
        int element = arr[i][0];
        q.push({element,i,0});
    }

    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int element = top[0];
        int a_idx  = top[1];
        int e_idx = top[2];

        output.push_back(element);
        if(e_idx + 1 < arr[a_idx].size()){
            q.push({arr[a_idx][e_idx + 1],a_idx,e_idx+1});
        }
    }

    return output;
}

int main(){

    // The k-way merge problem consists of merging k sorted
    // arrays to produce a single sorted array with the same
    // elements.
    // k-way merges are used in external sorting procedures.
    // External sorting algorithms are a class of sorting
    // algorithms that can handle massive amounts of data.

    vector<vector<int> > arr = {
        {10,15,20,30},
        {2,5,8,14,24},
        {0,11,60,90}
    };

    vector<int> result = mergeKArrays(arr);

    for(auto x:result){
        cout << x << " ";
    }
    
    return 0;
}