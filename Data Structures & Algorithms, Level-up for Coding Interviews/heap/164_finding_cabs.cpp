#include "bits/stdc++.h"
using namespace std;

class Point{
    public:
    int x,y;
    double dis;
    Point(int x,int y){
        this->x = x;
        this->y = y;
        dis = sqrt(x*x + y*y);
    }
};

class Cmp{
    public:
    bool operator()(Point p1, Point p2){
        return p1.dis > p2.dis;
    }
};

int main(){
    // Given N Cartesian Points in a 2D plane each represents
    // the location of the cab. You are standing at origin, you
    // want to know the names of nearest k cars.   

    int n,k;
    cin >> n >> k;
    priority_queue<Point,vector<Point>,Cmp> pq;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        Point p(x,y);
        if(pq.size() < k)
            pq.push(p);
        else
            if(pq.top().dis > p.dis)
                pq.pop(),pq.push(p);
    }
    while(!pq.empty() and k--){
        Point p = pq.top();
        cout << p.x << " " << p.y << endl;
        pq.pop();
    }
    return 0;
}