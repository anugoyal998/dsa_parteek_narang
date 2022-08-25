#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

void print(vector<string> v){
    for(auto s:v)cout << s << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    string s;
    cin >> s;
    vector<string> v;
    string x = "";
    int size = 0;
    int n  = s.length();
    for(int i=0;i<n;i++){
        if(x == ""){
            x += s[i];size++;
        }else{
            if(x[size-1] > s[i]){
                v.push_back(x);
                x = "";x += s[i];
                size = 1;
            }else{
                x += s[i];
                size++;
            }
        }
    }
    if(x != "")v.push_back(x);
    string mine = *min_element(v.begin(),v.end());
    int index = -1;
    for(int i=0;i<v.size();i++){
        if(v[i] == mine){
            index = i;break;
        }
    }

    string ans = "";
    for(int i=index;i<v.size();i++){
        ans += v[i];
    }
    for(int i=0;i<index;i++){
        ans += v[i];
    }
    print(v);   
    cout << ans << endl;
    return 0;
}