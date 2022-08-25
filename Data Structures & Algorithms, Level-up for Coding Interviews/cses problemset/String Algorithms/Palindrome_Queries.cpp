#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

vector<int> manachers_algorithm(string s){
    int n = s.length();
    string str = "#";
    for(auto c:s){
        str += c;
        str += "#";
    }
    vector<int> p(2*n+1,0);
    int center = 0, right = 0;
    // int max_len = 0, max_center = 0;
    
    for(int i=0;i<=2*n;i++){
        int mirror  = 2*center - i;
        if(right > i)
            p[i] = min(p[mirror],right-i);
        
        int a = i + (p[i] + 1);
        int b = i - (p[i] + 1);
        
        while(b>=0 and a <= 2*n and str[a] == str[b])
            b--,a++,p[i]++;
        
        // if(p[i] >= max_len) 
            // max_len = p[i], max_center = i;
        
        if(i + p[i] > right)
            center = i,right = i + p[i];
    }
    
    // string ans = "";
    // for(int i=max_center-max_len;i<max_center+max_len;i++){
        // if(str[i] != '#')
            // ans += str[i];
    // }
    return p;
}

void q2(vector<int> p,int l,int r){
    int len = r - l + 1;
    l = 2*l;
    r = 2*r + 2;
    int center = (l + r) / 2;
    cout << (p[center] == len ? "YES" : "NO") << endl;
}

void print(vector<int> v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> p = manachers_algorithm(s);
    print(p);
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int k;
            char ch;
            cin >> k >> ch;
            k--;
        }else{
            int l,r;
            cin >> l >> r;
            l--,r--;
            q2(p,l,r);
        }
    }

    return 0;
}