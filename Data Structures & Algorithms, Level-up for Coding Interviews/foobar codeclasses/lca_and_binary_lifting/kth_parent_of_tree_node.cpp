#include "bits/stdc++.h"
using namespace std;

class TreeAncestor {
    vector<vector<int>> parent;
public:
    TreeAncestor(int n, vector<int>& a) {
        int limit = log2(n) + 1;
        parent = vector<vector<int>>(n,vector<int>(limit));
        // 2^0th parent
        for(int i=0;i<n;i++){
            parent[i][0] = a[i];
        }
        for(int i=1;i<limit;i++){
            for(int j=0;j<n;j++){
                int x = parent[j][i-1]; // 2^(i-1)th parent 
                if(x == -1)parent[j][i] = x;
                else{
                    parent[j][i] = parent[x][i-1]; // 2^(i-1)th parent of x
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node == -1)return -1;
        if(k == 0)return node;
        int log_val = log2(k);
        int max_val = pow(2,log_val);
        return getKthAncestor(parent[node][log_val],k-max_val);
    }
};

int main(){
    // https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
    // TC --> O(nlogn) SC --> O(nlogn)
    int n;
    cin >> n;
    vector<int> parent(n);
    for(int i = 0; i < n; i++)cin >> parent[i];
    TreeAncestor* obj = new TreeAncestor(n,parent);
    int q;
    cin >> q;
    while(q--){
        int node, k;
        cin >> node >> k;
        cout << obj->getKthAncestor(node,k) << endl;
    }
    return 0;
}