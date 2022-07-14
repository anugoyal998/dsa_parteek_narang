#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i,st,ed) for(int i=st;i<ed;i++)
#define vi vector<int>
#define vvi vector<vi>
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline cout << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define _debug(x) cout << #x <<" "; __print(x); cout << endl;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

void __print(ll t) {cout << t;}
void __print(int t) {cout << t;}
void __print(string t) {cout << t;}
void __print(char t) {cout << t;}
void __print(lld t) {cout << t;}
void __print(double t) {cout << t;}
void __print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void __print(pair <T, V> p);
template <class T> void __print(vector <T> v);
template <class T> void __print(set <T> v);
template <class T, class V> void __print(map <T, V> v);
template <class T> void __print(multiset <T> v);
template <class T, class V> void __print(pair <T, V> p) {cout << "{"; __print(p.ff); cout << ","; __print(p.ss); cout << "}";}
template <class T> void __print(vector <T> v) {cout << "[ "; for (T i : v) {__print(i); cout << " ";} cout << "]";}
template <class T> void __print(set <T> v) {cout << "[ "; for (T i : v) {__print(i); cout << " ";} cout << "]";}
template <class T> void __print(multiset <T> v) {cout << "[ "; for (T i : v) {__print(i); cout << " ";} cout << "]";}
template <class T, class V> void __print(map <T, V> v) {cout << "[ "; for (auto i : v) {__print(i); cout << " ";} cout << "]";}

class MyGraph{
    public:
    int m,n;
    vvi arr;
    MyGraph(int n,int m,vvi arr){
        this->m=m;this->n=n;this->arr = arr;
    }
};

long long int fast_pow(int x,int y,long long int m/* modulo*/ = 1000000007){
    long long int res = 1;
    long int a = 1LL*x;
    long long int n = 1LL*y;

    while(n){
        if(n&1){
            res = (res * (a % m)) % m, n--;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }
    return res;
}

bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)return false;
    }
    return true;
}

int gcd(int a,int b){
    return __gcd(a,b);
}

int lcm(int a,int b){
    return (a * b) / gcd(a,b);
}

MyGraph input_graph(){
    int n,m;
    cin >> n >> m;
    vvi arr(n);
    loop(i,0,m){
        int u,v;
        cin >> u >> v;
        arr[u].pb(v);
        // arr[v].pb(u);
    }
    return MyGraph(n,m,arr);
}

void solve(){
    // Kahn's Algorithm
    MyGraph g = input_graph();
    int n = g.n, m = g.m;
    vvi arr = g.arr;
    vi indegree(n,0)   ;
    loop(i,0,n){
        for(auto j:arr[i])
        indegree[j]++;
    }
    queue<int> q;
    loop(i,0,n){
        if(indegree[i] == 0)q.push(i);
    }
    vi topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:arr[node]){
            indegree[i]--;
            if(indegree[i] == 0)q.push(i);
        }
    }
    _debug(topo);
}

int main() {
#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif
    solve();
}