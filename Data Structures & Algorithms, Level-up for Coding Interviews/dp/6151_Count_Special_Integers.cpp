#include "bits/stdc++.h"
using namespace std;

int dp[2][10][1024];

class Solution {
    
    vector<bool> Unmask (int mask) {
        vector<bool> result(10, false);
        
        for (int j = 0; j <= 9; j ++) {
            if (mask & (1 << j)) result[j] = true;
        }
        return result;
    }
    
    int Mask (const vector<bool>& is_taken) {
        int result = 0;
        for (int j = 0; j < 10; j ++)
            if (is_taken[j]) result += (1 << j);
        return result;
    }
    
    int f(int pos,int mask,bool small,string s){
        if(pos == s.length())return 1;
        
        int &ans = dp[small][pos][mask];
        if(ans != -1)return ans;
        
        ans = 0;
        
        vector<bool> is_taken = Unmask(mask);
        int start = (pos == 0)? 1 : 0;
        int end = small? 9 : (s[pos] - '0');
        
        for (int j = start; j <= end; j ++) {
            if (is_taken[j]) continue;
            
            is_taken[j] = true;
            ans +=  f(pos+1, Mask(is_taken), small? true : (j != end), s);
            is_taken[j] = false;
        }
        return ans;
    }
    
    
public:
    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        
        string s = to_string(n);
        int ans = f(0, 0, false, s);
        
        for (int j = 1; j < s.length(); j ++) {
            memset(dp, -1, sizeof(dp));
            string all_9s (j, '9');
            
            ans += f(0, 0, false, all_9s);
        }
        return ans;
    }
};

int main(){
    // https://leetcode.com/contest/weekly-contest-306/problems/count-special-integers/
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countSpecialNumbers(n) << endl;
    return 0;
}