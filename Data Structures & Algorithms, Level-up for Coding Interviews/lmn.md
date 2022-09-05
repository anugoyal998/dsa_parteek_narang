# Strings

#### String Tokenization
```cpp
#include "bits/stdc++.h"
#include "sstream"
using namespace std;

int main(){
    string s;
    getline(cin, s);
    string token;
    stringstream ss(s);
    vector<string> tokens;
    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }
    for(auto tkn:tokens){
        cout << tkn << endl;
    }
    return 0;
}
```

#### KMP
```cpp
#include "bits/stdc++.h"
using namespace std;

vector<int> LPS/*Longest Proper Prefix whix is also suffix*/(string s){
    int n = s.length();
    int len = 0;
    vector<int> arr(n);
    arr[0] = len;
    int i = 1;
    while(i<n){
        if(s[i] == s[len]){
            arr[i++] = ++len;
        }else{
            if(len != 0){
                len = arr[len-1];
            }else{
                arr[i++] = 0;
            }
        }
    }
    return arr;
}

int main(){
    // https://practice.geeksforgeeks.org/problems/search-pattern0205/1
    // Worst Case TC --> O(n)
    string pat, txt;
    cin >> pat >> txt;
    vector<int> lps = LPS(pat);
    int m = pat.length();
    int n = txt.length();

    int i = 0, j = 0;
    while((n-i) >= (m-j)){
        if(pat[j] == txt[i])i++,j++;

        if(j == m){
            cout << i-j << " ";
            j = lps[j-1];
        }else if(i<n and pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return 0;
}
```

#### Rabin Karp
```cpp
#include "bits/stdc++.h"
using namespace std;
#define ll long long

int p = 31;
const int N = 1e5+7, m = 1e9+7;
vector<ll> powers(N);

int main(){
	// https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1
	// find occurrences of s in t
	string s,t;
	cin >> s >> t;
	int T = t.length(), S = s.length();

	powers[0] = 1;
	for(int i=1;i<N;i++){
		powers[i] = (powers[i-1] * p) % m;
	}

	vector<ll> h(T+1,0);
	for(int i=0;i<T;i++){
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % m;
	}

	ll h_s = 0;
	for(int i=0;i<S;i++){
		h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % m;
	}

	for(int i=0;i + S - 1 < T;i++){
		ll cur_h = (h[i+S] - h[i] + m) % m;
		if(cur_h == (h_s * powers[i]) % m){
			cout << i << " ";
		}
	}


	return 0;
}
```

#### Z Function
The Z-function for this string is an array of length n where the i-th element is equal to the **greatest number of characters starting from the position  that coincide with the first characters of s**.

```cpp
#include "bits/stdc++.h"
using namespace std;

vector<int> z_function_naive(string s){
    int n = s.length();
    vector<int> z(n,0);
    for(int i=1;i<n;i++){
        while(i+z[i] < n and s[z[i]] == s[i+z[i]])
            z[i]++;
    }
    return z;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){

    // Z-function for string is an array of length n 
    // where ith element is equal to the greatest number of
    // characters starting from position i that coincide with
    // first characters of s.

    // z[i] = length of longest string i.e., at the same time,
    // a prefix of s and prefix of suffix of s starting at i.

    // z_function problem
    // https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb0f5/0000000000ba82c5

    string s;
    cin >> s;
    vector<int> z = z_function(s);
    print(z);
    return 0;
}
```

[z-function problem](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb0f5/0000000000ba82c5)

#### Manachers Algorithm


# Bit Manipulation

```cpp
int getIthBit(int n,int i){
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}

void setIthBit(int &n,int i){
    int mask = (1<<i);
    n |= mask;
}

void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n &= mask;
}

void clearLastIBits(int &n,int i){
    int mask = (-1<<i);
    n &= mask;
}

int countSetBits(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n = (n&(n-1));
    }
    return cnt;
}
```

# Stacks and Queues

#### Infix to Postfix
```cpp
#include "bits/stdc++.h"
using namespace std;

int prec(char ch){
    if(ch == '^')return 3;
    if(ch == '*' or ch == '/')return 2;
    if(ch == '+' or ch == '-')return 1;
    return -1;
}

string infixToPostfix(string s){
    string ans = "";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch >= 'a' and ch <= 'z')
            ans += ch;
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')'){
            while(!st.empty() and st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }else{
            while(!st.empty() and prec(st.top()) > prec(ch)){
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    s = infixToPostfix(s);
    cout << s << endl;
    return 0;
}
```

# Tree

#### Morris Traversal
```cpp
vector<int> morris_traversal_preorder(node* root){
    vector<int> ans;
    node* cur = root;
    while(cur){
        if(!cur->left){
            ans.push_back(cur->data);
            cur = cur->right;
        }else{
            node* prev = cur->left;
            while(prev->right and prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}
```

**[Burn Tree](https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos)**

# Number Theory

#### Sieve of Eratosthenes

```cpp
// TC --> (sqrt(N)) * (log(log(N)))
vi sieve(int n){
    vi is_prime(n+1,1);
    is_prime[0] = is_prime[1] = 0;

    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}
```

#### Prime Factorisation

```cpp
// TC --> sqrt(N)
void primeFact(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                cnt++; n /= i;
            }
            cout << i << " ^ " << cnt << endl;
        }
    }
    if(n > 1)cout << n << " ^ " << 1 << endl;
}
```

```cpp
// Prime factorisation using sieve
void sieve(int n){
    vector<int> a(n+1,-1);

    for(int i=2;i<=n;i++){
        if(a[i] == -1){
            for(int j=i;j<=n;j+=i){
                if(a[j] == -1)
                    a[j] = i;
            }
        }
    }

    while(n!=1){
        cout << a[n] << " ";
        n /= a[n];
    }
    cout << 1 << endl;
}
```

#### GCD

```cpp
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
```

# Trie

```cpp
// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char,Node*> mp;
    bool flag = false;
    //checks if the reference trie is present or not
    bool containKey(char ch) {
        return (mp[ch] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        mp[ch] = node; 
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return mp[ch];
    }
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        //creating new obejct
        root = new Node();
    }

    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    
    return 0;
}
```

# Segment Tree

```cpp
#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
    vector<int> seg;
public:

    SegmentTree(int n){
        seg.resize(4*n+2);
    }

    void build(int i,int low,int high,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*i+1,low,mid,arr);
        build(2*i+2,mid+1,high,arr);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }

    int query(int i,int low,int high,int l,int r){
        // no overlap
        if(l > high or r < low)
            return INT_MAX;
        // complete overlap
        if(low >= l and high <= r)
            return seg[i];
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);
        return min(left,right);
    }

    void update(int i,int low,int high,int index,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        if(index <= mid)
            update(2*i+1,low,mid,index,arr);
        else
            update(2*i+2,mid+1,high,index,arr);
        seg[i] = min(seg[2*i+1],seg[2*i+2]);
    }

};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTree st(n);
    st.build(0,0,n-1,arr);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << st.query(0,0,n-1,l,r) << endl;
        }else{
            int index, val;
            cin >> index >> val;
            arr[index] = val;
            st.update(0,0,n-1,index,arr);
        }
    }

    return 0;
}
```

#### Lazy Propagation

```cpp
#include "bits/stdc++.h"
using namespace std;

class SegmentTree{
    vector<int> seg;
    vector<int> lazy;
public: 

    SegmentTree(int n){
        seg.resize(4*n+2);
        lazy.resize(4*n+2);
    }

    void build(int i,int low,int high,vector<int> arr){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*i+1,low,mid,arr);
        build(2*i+2,mid+1,high,arr);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i,int low,int high,int l,int r){
        // complete lazy
        if(lazy[i] != 0){
            int dx = lazy[i];
            lazy[i] = 0;
            seg[i] += dx * (high-low+1);

            if(low != high)
                lazy[2*i+1] += dx, lazy[2*i+2] += dx;
        }
        // no overlap
        if(l > high or r < low)
            return 0;
        // complete overlap
        if(low >= l and high <= r)
            return seg[i];
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);
        return left + right;
    }

    void update(int i,int low,int high,int l,int r,int val){
        if(lazy[i] != 0){
            int dx = lazy[i];
            lazy[i] = 0;
            seg[i] += dx * (high-low+1);

            if(low != high)
                lazy[2*i+1] += dx, lazy[2*i+2] += dx;
        }
        if(low > r or high < l)return;
        if(low >= l and high <= r){
            int dx = (high-low+1)*val;
            seg[i] += dx;
            if(low != high)
                lazy[2*i+1] += val, lazy[2*i+2] += val;
            return;
        }
        int mid = (low + high) >> 1;
        update(2*i+1,low,mid,l,r,val);
        update(2*i+2,mid+1,high,l,r,val);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTree st(n);
    st.build(0,0,n-1,arr);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << st.query(0,0,n-1,l,r) << endl;
        }else{
            int l,r,val;
            cin >> l >> r >> val;
            st.update(0,0,n-1,l,r,val);
        }
    }

    return 0;
}
```

# Binary Index Tree

```cpp
#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

class BIT{
    int n;
    vector<int> bit;

public:

    BIT(int n){
        this->n = n;
        bit.resize(n+1);
    }

    void update(int index,int val){
        for(int i=index;i<=n;i += (i&(-i))){
            bit[i] += val;
        }
    }

    int query(int index){
        int ans = 0;
        for(int i=index;i>0;i -= (i&(-i))){
            ans += bit[i];
        }
        return ans;
    }
};

int main(){
    // https://codeforces.com/blog/entry/61364
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif

    int n;
    cin >> n;
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)cin >> arr[i];

    BIT bit(n);
    for(int i=1;i<=n;i++)
        bit.update(i,arr[i]);

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << bit.query(r) - bit.query(l-1) << endl;
        }else{
            int index, val;
            cin >> index >> val;
            bit.update(index,-arr[index]);
            arr[index] = val;
            bit.update(index,arr[index]);
        }
    }


    return 0;
}
```

# Sde Sheet's Questions

### Arrays
`Striver Sheet`
✅ https://leetcode.com/problems/set-matrix-zeroes/
✅ https://leetcode.com/problems/next-permutation/
✅ https://leetcode.com/problems/merge-sorted-array/
✅ https://www.interviewbit.com/problems/repeat-and-missing-number-array/
⚠ https://www.codingninjas.com/codestudio/problems/count-inversions_615
✅ https://leetcode.com/problems/majority-element/
✅ https://leetcode.com/problems/majority-element-ii/
⚠ https://leetcode.com/problems/reverse-pairs/ 
⚠ https://www.interviewbit.com/problems/subarray-with-given-xor/

`Leetcode`
✅ https://leetcode.com/problems/container-with-most-water/
⚠ https://leetcode.com/problems/first-missing-positive/
✅ https://leetcode.com/problems/trapping-rain-water/
✅ https://leetcode.com/problems/spiral-matrix/
⚠ https://leetcode.com/problems/gas-station/
✅ https://leetcode.com/problems/find-peak-element/
⚠ https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
✅ https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
✅ https://leetcode.com/problems/maximum-sum-circular-subarray/

### LinkedList
`Striver Sheet`
✅ https://leetcode.com/problems/linked-list-cycle-ii/
⚠ https://leetcode.com/problems/reverse-nodes-in-k-group/
⚠ https://leetcode.com/problems/copy-list-with-random-pointer/

`Leetcode`
✅ https://leetcode.com/problems/merge-k-sorted-lists/
⚠ https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
⚠ https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
❌ https://leetcode.com/problems/lru-cache/

### Binary Search
`Striver Sheet`
✅ https://www.interviewbit.com/problems/matrix-median/
✅ https://leetcode.com/problems/single-element-in-a-sorted-array/
✅ https://leetcode.com/problems/search-in-rotated-sorted-array/
✅ https://leetcode.com/problems/median-of-two-sorted-arrays/
✅ https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

### Greedy
`Striver Sheet`
✅ https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

### Recursion Backtracking
`Striver Sheet`
✅ https://leetcode.com/problems/subsets-ii/
✅ https://leetcode.com/problems/palindrome-partitioning 
✅ https://leetcode.com/problems/permutation-sequence 
✅ https://leetcode.com/problems/permutations-ii/
✅ https://leetcode.com/problems/n-queens/
⚠ https://leetcode.com/problems/sudoku-solver/

`Leetcode`
✅ https://leetcode.com/problems/unique-binary-search-trees/
✅ https://leetcode.com/problems/unique-binary-search-trees-ii/
✅ https://leetcode.com/problems/different-ways-to-add-parentheses 
✅ https://leetcode.com/problems/decode-string/
✅ https://leetcode.com/problems/find-the-winner-of-the-circular-game 

### Stack and Queues
`Striver`
✅ https://leetcode.com/problems/largest-rectangle-in-histogram/
❌ https://leetcode.com/problems/lfu-cache/
❌ https://leetcode.com/problems/lru-cache/
✅ https://leetcode.com/problems/sliding-window-maximum/
✅ https://leetcode.com/problems/min-stack/
⚠ https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
⚠ https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
❌ https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

`Leetcode`
✅ https://leetcode.com/problems/simplify-path/
✅ https://leetcode.com/problems/basic-calculator/
✅ https://leetcode.com/problems/basic-calculator-ii/
✅ https://leetcode.com/problems/different-ways-to-add-parentheses/
✅ https://leetcode.com/problems/remove-duplicate-letters/
✅ https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
✅ https://leetcode.com/problems/longest-absolute-file-path/
✅ https://leetcode.com/problems/stamping-the-sequence/

### Binary Tree
`Striver Sheet`
✅ https://leetcode.com/problems/binary-tree-inorder-traversal/ (Iterative / Morris Traversal)
✅ https://leetcode.com/problems/binary-tree-postorder-traversal/ (Iterative)
✅ https://leetcode.com/problems/maximum-width-of-binary-tree/
✅ https://leetcode.com/problems/binary-tree-maximum-path-sum/
✅ https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
⚠ https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
✅ https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
✅ https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
✅ https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
✅ https://leetcode.com/problems/unique-binary-search-trees/
✅ https://leetcode.com/problems/unique-binary-search-trees-ii/
✅ https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
✅ https://leetcode.com/problems/delete-node-in-a-bst/ 
✅ https://leetcode.com/problems/insert-into-a-binary-search-tree/
✅ https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
❌ https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

### Graph
`Striver Sheet`
✅ https://leetcode.com/problems/clone-graph/
✅ https://leetcode.com/problems/minimum-height-trees/
✅ https://leetcode.com/problems/minimum-height-trees/
❌ https://leetcode.com/problems/redundant-connection-ii/
❌ https://leetcode.com/problems/find-eventual-safe-states/
❌ https://leetcode.com/problems/cheapest-flights-within-k-stops/
✅ https://leetcode.com/problems/flower-planting-with-no-adjacent/
✅ https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


### Trie
`Striver Sheet`
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

### Dynamic Programming
✅ https://leetcode.com/problems/longest-common-subsequence/
✅ https://leetcode.com/problems/edit-distance/
✅ https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
