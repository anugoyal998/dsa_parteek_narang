#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

class Movie{
    public:
    int start, end;
    Movie(int start, int end){
        this->start = start;
        this->end = end;
    }
};

bool cmp(const Movie& a, const Movie& b){
    if(a.end != b.end) return a.end < b.end;
    return a.start < b.start;
}

void print(vector<Movie> v){
    for(Movie m:v){
        cout << m.start << " " << m.end << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n,k;
    cin >> n >> k;
    vector<Movie> arr;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(Movie(a,b));
    }
    sort(arr.begin(), arr.end(),cmp);

    print(arr);

    queue<Movie> q;
    q.push(arr[0]);
    int cnt = 1;
    for(int i=1;i<n;i++){
        Movie pre = q.front();
        Movie cur = arr[i];

        if(pre.end >= cur.start){
            // overlap
            int size = q.size();
            if(size < k){
                q.push(cur);
                cnt++;
            }
        }else{
            q.pop();
            q.push(cur);
            cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}