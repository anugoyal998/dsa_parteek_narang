#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

template<typename T>
class my_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }    
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};

my_priority_queue<int> left; // max heap
my_priority_queue<int,vector<int>,greater<int>> right; // min heap
int med;    
void addNum(int d){
    if(left.size() == 0 and right.size() == 0){
        med = d;
        left.push(d);
        return;
    }
    if(left.size() > right.size()){
        if(d < med){
            right.push(left.top());
            left.pop();
            left.push(d);
        }else{
            right.push(d);
        }
        med = left.top();
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
        med = left.top();
    }
}

void delNum(int d){
    left.remove(d);
    right.remove(d);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif


    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n;i++)cin >> arr[i];

    for(int i=0;i<n;i++){
        if(i < k){
            addNum(arr[i]);
        }else{
            cout << med << " ";
            delNum(arr[i-k]);
        }
    }

    cout << med << endl;



    return 0;
}