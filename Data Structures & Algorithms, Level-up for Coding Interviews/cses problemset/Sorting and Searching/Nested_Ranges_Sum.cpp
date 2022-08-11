#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

class Point{
    public:
    int start, end, index;
    Point(int start, int end, int index){
        this->start = start;
        this->end = end;
        this->index = index;
    }
};

bool cmp(const Point& p1, const Point& p2){
    if(p1.start != p2.start)return p1.start < p2.start;
    return p1.end > p2.end;
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    vector<Point> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b; 
        v.push_back(Point(a,b,i));
    }
    sort(v.begin(),v.end(),cmp);

    vector<int> ans1(n,0), ans2(n,0);
    ordered_set<pair<int,int>> s;
    for(int i=n-1;i>=0;i--){
        s.insert({v[i].end,-1*i});
        ans1[v[i].index] = s.order_of_key({v[i].end,-1*i});
    }
    s.clear();
    for(int i=0;i<n;i++){
        s.insert({v[i].end,-1*i});
        ans2[v[i].index] = s.size() - s.order_of_key({v[i].end,-1*i}) - 1;
    }

    print(ans1);
    print(ans2);


    return 0;
}