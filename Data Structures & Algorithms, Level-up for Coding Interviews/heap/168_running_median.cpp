#include "bits/stdc++.h"
using namespace std;

int main(){
    // You are given a running stream of integers. Write an
    // efficient algorithm to output median of numbers read so
    // far after every input.   

    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap


    int d;
    cin >> d;
    left.push(d);

    float med = d;
    cout << med <<  " ";

    cin >> d;
    while(d!=-1){
        if(left.size() > right.size()){
            if(d < med){
                right.push(left.top());
                left.pop();
                left.push(d);
            }else{
                right.push(d);
            }
            med = double(left.top() + right.top()) / 2.0;
        }else if(left.size() == right.size()){
            if(d<med){
                left.push(d);
                med = left.top();
            }else{
                right.push(d);
                med = right.top();
            }
        }else{
            if(d < med){
                left.push(d);
            }else{
                left.push(right.top());
                right.pop();
                right.push(d);
            }
            med = double(left.top() + right.top()) / 2.0;
        }
        cout << med <<  " ";
        cin >> d;
    }
    return 0;
}